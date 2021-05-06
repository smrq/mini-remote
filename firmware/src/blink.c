#include "stm8l10x.h"

#define LED_PIN 0x01

void main(void) {
	CLK_DIVR = 0x00; // 16MHz

	PORTD_DDR |= LED_PIN; // Output
	PORTD_CR1 |= LED_PIN; // Push-pull

	PORTD_ODR |= LED_PIN;
	for(;;) {
		for (u32 i = 0; i < 1e5; ++i) {}
		PORTD_ODR ^= LED_PIN;
	}
}
