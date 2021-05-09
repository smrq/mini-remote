#include "main.h"

SendState send_state;
u8 send_bit;
u8 send_burst;
u8 address;
u8 command;

void main(void) {
	init();

	for(;;) {
		// Wait for EXTIB to wake processor
		enable_extib();
		_halt();
		disable_extib();

		u8 last_button = 0xFF;
		u8 button;

		while ((button = read_button_matrix()) != 0xFF) {
			if (last_button == button) {
				send_state = SEND_REPEAT_HEADER1;
				send_burst = 0;

				led_on();
				run_tx_state_machine();
				enable_ir();
				while (send_state != SEND_IDLE) {
					// TODO: wait in lower power mode for tim3 interrupt?
				}
				led_off();

				_delay_ms(97);
			} else {
				last_button = button;
				address = 0xA5; // Pioneer VSX-1020
				command = 0x55; // Input select next
				send_state = SEND_HEADER1;
				send_burst = 0;

				led_on();
				run_tx_state_machine();
				enable_ir();
				while (send_state != SEND_IDLE) {
					// TODO: wait in lower power mode for tim3 interrupt?
				}
				led_off();

				_delay_ms(40);
			}

			// TODO: use wake timer to repeatedly delay 108ms from start of tx
		}
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
				result = (col << 4) | row;
				goto break_outer;
			}
		}
		PC_ODR |= (1 << col);
	}
	break_outer:

	PC_ODR &= ~COL_MASK;
	return result;
}

void run_tx_state_machine(void) {
	switch (send_state) {
		case SEND_HEADER1:
			set_tim3_high();
			if (++send_burst == 16) {
				send_state = SEND_HEADER2;
				send_burst = 0;
			}
			break;

		case SEND_HEADER2:
			set_tim3_low();
			if (++send_burst == 8) {
				send_state = SEND_ADDRESS;
				send_bit = 0;
				send_burst = 0;
			}
			break;

		case SEND_REPEAT_HEADER1:
			set_tim3_high();
			if (++send_burst == 16) {
				send_state = SEND_REPEAT_HEADER2;
				send_burst = 0;
			}
			break;

		case SEND_REPEAT_HEADER2:
			set_tim3_low();
			if (++send_burst == 4) {
				send_state = SEND_FOOTER;
				send_burst = 0;
			}
			break;

		case SEND_ADDRESS:
			if (send_burst == 0) {
				set_tim3_high();
			} else {
				set_tim3_low();
			}

			if (address & (1 << send_bit)) {
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
				send_state = SEND_ADDRESS_INV;
				send_bit = 0;
			}

			break;

		case SEND_ADDRESS_INV:
			if (send_burst == 0) {
				set_tim3_high();
			} else {
				set_tim3_low();
			}

			if (~address & (1 << send_bit)) {
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
				send_state = SEND_COMMAND;
				send_bit = 0;
			}
			
			break;

		case SEND_COMMAND:
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
				send_state = SEND_COMMAND_INV;
				send_bit = 0;
			}

			break;

		case SEND_COMMAND_INV:
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

		case SEND_IDLE:
			break;
	}
}


