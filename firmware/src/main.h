#pragma once
#include "shared.h"
#include "init.h"
#include "hardware.h"

typedef enum SendState {
	SEND_IDLE,
	SEND_READY,
	SEND_HEADER1,
	SEND_HEADER2,
	SEND_REPEAT_HEADER1,
	SEND_REPEAT_HEADER2,
	SEND_ADDRESS,
	SEND_ADDRESS_INV,
	SEND_COMMAND,
	SEND_COMMAND_INV,
	SEND_FOOTER,
	SEND_DONE,
} SendState;

typedef u8 ButtonId;

void main(void);
void isr_extib(void) __interrupt(INT_EXTIB);
void isr_tim3_update(void) __interrupt(INT_TIM3_UPDATE);

u8 read_button_matrix(void);
void handle_pressed(u8 row, u8 col);
void run_tx_state_machine(void);
