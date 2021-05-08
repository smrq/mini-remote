#include "stm8l10x.h"

/*
Pin assignments:
	A0:    IR LED
	B0-B5: Rows 0-5
	C0-C2: Columns 0-2
	D0:    LED
 */
#define IRLED_PIN 0x01
#define LED_PIN   0x01

void main(void) {
	/*
		RM0013 9.2.1
		In applications where the MCU can be halted for certain periods, the power consumption can be minimized by
		keeping a fast clock (high performance execution) during active periods, in order to reduce the ratio between
		active periods and Halt (that is “zero”- consumption) periods.
	*/
	CLK_DIVR = 0x00; // 16MHz

	PORTA_DDR |= IRLED_PIN; // IR LED: Output
	PORTD_DDR |= LED_PIN;   // LED: Output

	PORTA_DDR &= ~(IRLED_PIN); // IR LED: Open drain
	PORTD_CR1 |= LED_PIN;      // LED: Push-pull

	PORTD_ODR |= LED_PIN;
	for(;;) {
		for (u32 i = 0; i < 1e5; ++i) {}
		PORTD_ODR ^= LED_PIN;
	}
}
