#pragma once
#include "shared.h"
#include "init.h"
#include "hardware.h"

#define NO_MESSAGE() 0
#define MESSAGE_16(a) (a)
#define MESSAGE_32(a, b) ((a) | ((u32)(b) << 16))

typedef enum MessageFormat {
	FORMAT_NEC,
	/*
		Samsung format is identical to NEC, except:
		- The high start bit is 4.5ms (8 bursts) instead of 9ms (16 bursts)
		- The address is transmitted twice instead of once and once inverted
	 */
	FORMAT_SAMSUNG,
} MessageFormat;

typedef enum SendState {
	SEND_IDLE,
	SEND_READY,
	SEND_HEADER1,
	SEND_HEADER2,
	SEND_ADDRESS1,
	SEND_ADDRESS2,
	SEND_COMMAND1,
	SEND_COMMAND2,
	SEND_FOOTER,
	SEND_DONE,
} SendState;

typedef u8 ButtonId;

void main(void);
void isr_extib(void) __interrupt(INT_EXTIB);
void isr_tim3_update(void) __interrupt(INT_TIM3_UPDATE);

u8 read_button_matrix(void);
void handle_pressed(u8 row, u8 col);
u32 get_message(u8 button);
MessageFormat get_message_format(u8 button);
void run_tx_state_machine(void);
