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

#define ROW_COUNT 6
#define ROW_MASK ((1<<(ROW_COUNT+1))-1)
#define COL_COUNT 3
#define COL_MASK ((1<<(COL_COUNT+1))-1)

void main(void) {
	/*
		Set clock to 16MHz (0x00)

		RM0013 9.2.1
		In applications where the MCU can be halted for certain periods, the power consumption can be minimized by
		keeping a fast clock (high performance execution) during active periods, in order to reduce the ratio between
		active periods and Halt (that is “zero”- consumption) periods.
	*/
	CLK_DIVR = 0x00;

	/*
		Port A:
		0:   IR LED -> Output (1), open drain (0), normally high
		1:   Reset  -> Ignored* (0)
		2-7: Unused -> Output (1), push-pull (1), low

		*The reset pin is not configured for GPIO by default. See: RM0013 7.2.2
	 */
	PORTA_DDR = 0b11111101;
	PORTA_CR1 = 0b11111100;
	PORTA_ODR = 0b00000001;

	/*
		Port B:
		0-5: Rows 1-5 -> Input (0), pull-up (1)
		6-7: Unused   -> Output (1), push-pull (1), low
	 */

	PORTB_DDR = 0b11000000; 
	PORTB_CR1 = 0b11111111;
	PORTB_ODR = 0b00000000;

	/*
		Port C:
		0-2: Columns 1-2 -> Output (1), open drain* (0), normally low
		3-7: Unused      -> Output (1), push-pull (1), low

		*Ignored for true open drain pins (C0, C1)
	 */
	PORTC_DDR = 0b11111111;
	PORTC_CR1 = 0b11111000;
	PORTC_ODR = 0b00000111;

	/*
		Port D:
		0:   Status LED -> Output (1), push-pull (1), normally low
		1-7: Unused     -> Output (1), push-pull (1), low
	 */
	PORTD_DDR = 0b11111111;
	PORTD_CR1 = 0b11111111;
	PORTD_ODR = 0b00000000;

	for(;;) {
		PORTC_ODR &= ~COL_MASK;
		PORTD_ODR &= ~LED_PIN;
		for (u8 col = 0; col < COL_COUNT; ++col) {
			PORTC_ODR |= (1 << col);

			for (u8 row = 0; row < ROW_COUNT; ++row) {
				if (!(PORTB_IDR & (1 << row))) {
					// row,col is pressed
					PORTD_ODR |= LED_PIN;
				}
			}

			PORTC_ODR &= ~(1 << col);
		}
		PORTC_ODR |= COL_MASK;
	}
}
