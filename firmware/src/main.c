#include "main.h"

MessageFormat message_format;
u16 command;

SendState send_state;
u8 send_bit;
u8 send_burst;

u32 messages[COL_COUNT * ROW_COUNT] = {
	MESSAGE_16(0xA51C),         // 0,0: Receiver power
	NO_MESSAGE(),               // 0,1: No button
	MESSAGE_16(0xA50A),         // 0,2: Volume up
	MESSAGE_16(0x0702),         // 1,0: TV power (Samsung format)
	MESSAGE_16(0xA512),         // 1,1: Mute
	MESSAGE_16(0xA50B),         // 1,2: Volume down
	MESSAGE_32(0xA556, 0xA5C1), // 2,0: Previous input
	MESSAGE_16(0xA555),         // 2,1: Next input
	NO_MESSAGE(),               // 2,2: No button
	MESSAGE_32(0xA55E, 0xA5CA), // 3,0: HDMI 1
	MESSAGE_32(0xA55E, 0xA5CB), // 3,1: HDMI 2
	MESSAGE_32(0xA55E, 0xA5CC), // 3,2: HDMI 3
	MESSAGE_32(0xA55E, 0xA5C7), // 4,0: HDMI 5
	MESSAGE_16(0xA50C),         // 4,1: TV
	MESSAGE_16(0xA516),         // 4,2: Video 1
	NO_MESSAGE(),               // 5,0: Not assigned
	NO_MESSAGE(),               // 5,1: Not assigned
	NO_MESSAGE(),               // 5,2: Not assigned
	NO_MESSAGE(),               // 6,0: Not assigned
	NO_MESSAGE(),               // 6,1: Not assigned
	NO_MESSAGE(),               // 6,2: Not assigned
};

void main(void) {
	init();

	led_on();
	_delay_ms(250);
	led_off();
	_delay_ms(250);
	led_on();
	_delay_ms(250);
	led_off();

	for(;;) {
		// Wait for EXTIB to wake processor
		enable_extib();
		_halt();
		disable_extib();

		led_on();

		u8 button;
		while ((button = read_button_matrix()) != 0xFF) {
			message_format = get_message_format(button);
			u32 message = get_message(button);

			while (message != 0) {
				command = message & 0xFFFF;
				message = message >> 16;
				send_state = SEND_HEADER1;
				send_burst = 0;

				run_tx_state_machine();
				enable_ir();

				// TODO: use wake timer to delay until 108ms from start of tx
				while (send_state != SEND_IDLE) {}
				_delay_ms(40);
			}
		}

		led_off();
	}
}

void isr_extib(void) __interrupt(INT_EXTIB) {
	debug_2_toggle();
	clear_extib();
}

void isr_tim3_update(void) __interrupt(INT_TIM3_UPDATE) {
	run_tx_state_machine();
	clear_tim3_update();
}

ButtonId read_button_matrix(void) {
	// Columns are normally low (open drain) in order to trigger interrupts on any button press.
	// To determine which button is held, bring all columns high and then check each column one
	// by one.
	ButtonId result = 0xFF;

	PC_ODR |= COL_MASK;

	for (u8 col = 0; col < COL_COUNT; ++col) {
		PC_ODR &= ~(1 << col);
		for (u8 row = 0; row < ROW_COUNT; ++row) {
			if (!(PB_IDR & (1 << row))) {
				result = COL_COUNT*row + col;
				goto break_outer;
			}
		}
		PC_ODR |= (1 << col);
	}
	break_outer:

	PC_ODR &= ~COL_MASK;
	return result;
}

u32 get_message(u8 button) {
	return messages[button];
}

MessageFormat get_message_format(u8 button) {
	if (button == 3) { // 1,0
		return FORMAT_SAMSUNG;
	} else {
		return FORMAT_NEC;
	}
}

void run_tx_state_machine(void) {
	switch (send_state) {
		case SEND_HEADER1:
			set_tim3_high();
			if (++send_burst == (message_format == FORMAT_SAMSUNG ? 8 : 16)) {
				send_state = SEND_HEADER2;
				send_burst = 0;
			}
			break;

		case SEND_HEADER2:
			set_tim3_low();
			if (++send_burst == 8) {
				send_state = SEND_ADDRESS1;
				send_bit = 0;
				send_burst = 0;
			}
			break;

		case SEND_ADDRESS1:
			if (send_burst == 0) {
				set_tim3_high();
			} else {
				set_tim3_low();
			}

			if (command & (1 << (8+send_bit))) {
				if (++send_burst == 4) {
					send_burst = 0;
					++send_bit;
				}
			} else {
				if (++send_burst == 2) {
					send_burst = 0;
					++send_bit;
				}
			}

			if (send_bit == 8) {
				send_state = SEND_ADDRESS2;
				send_bit = 0;
			}

			break;

		case SEND_ADDRESS2:
			if (send_burst == 0) {
				set_tim3_high();
			} else {
				set_tim3_low();
			}

			if ((message_format == FORMAT_SAMSUNG ? command : ~command) & (1 << (8+send_bit))) {
				if (++send_burst == 4) {
					send_burst = 0;
					++send_bit;
				}
			} else {
				if (++send_burst == 2) {
					send_burst = 0;
					++send_bit;
				}
			}

			if (send_bit == 8) {
				send_state = SEND_COMMAND1;
				send_bit = 0;
			}
			
			break;

		case SEND_COMMAND1:
			if (send_burst == 0) {
				set_tim3_high();
			} else {
				set_tim3_low();
			}

			if (command & (1 << send_bit)) {
				if (++send_burst == 4) {
					send_burst = 0;
					++send_bit;
				}
			} else {
				if (++send_burst == 2) {
					send_burst = 0;
					++send_bit;
				}
			}

			if (send_bit == 8) {
				send_state = SEND_COMMAND2;
				send_bit = 0;
			}

			break;

		case SEND_COMMAND2:
			if (send_burst == 0) {
				set_tim3_high();
			} else {
				set_tim3_low();
			}

			if (~command & (1 << send_bit)) {
				if (++send_burst == 4) {
					send_burst = 0;
					++send_bit;
				}
			} else {
				if (++send_burst == 2) {
					send_burst = 0;
					++send_bit;
				}
			}

			if (send_bit == 8) {
				send_state = SEND_FOOTER;
				send_bit = 0;
			}
			
			break;

		case SEND_FOOTER:
			set_tim3_high();
			send_state = SEND_DONE;
			break;

		case SEND_DONE:
			set_tim3_low();
			disable_ir();
			send_state = SEND_IDLE;
			break;

		case SEND_IDLE:
			break;
	}
}


