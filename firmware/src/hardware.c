#include "hardware.h"

void led_on(void) {
	PD_ODR |= 0x01;
}

void led_off(void) {	
	PD_ODR &= ~0x01;
}

void debug_1_on(void){
	PA_ODR |= 0x04;
}

void debug_1_off(void){
	PA_ODR &= ~0x04;
}

void debug_1_toggle(void){
	PA_ODR ^= 0x04;
}

void debug_2_on(void){
	PA_ODR |= 0x08;
}

void debug_2_off(void){
	PA_ODR &= ~0x08;
}

void debug_2_toggle(void){
	PA_ODR ^= 0x08;
}

void enable_extib(void) {
	PB_CR2 |= 0b111111;
}

void disable_extib(void) {
	PB_CR2 &= ~0b111111;
}

void clear_extib(void) {
	EXTI_SR2 |= 0x01;
}

void clear_tim3_update(void) {
	TIM3_SR1 &= ~0x01;
}

void set_tim3_low(void) {
	TIM3_CCMR1 &= ~(0b111 << 4);
	TIM3_CCMR1 |= 0b100 << 4;
}

void set_tim3_high(void) {
	TIM3_CCMR1 &= ~(0b111 << 4);
	TIM3_CCMR1 |= 0b101 << 4;
}

void enable_ir(void) {
	TIM2_CNTRH = 0;
	TIM2_CNTRL = 0;
	TIM2_CR1 |= 0x01; // Enable timer
	TIM2_BKR |= 0xF0; // Enable timer CC1 output

	TIM3_CNTRH = 0;
	TIM3_CNTRL = 0;
	TIM3_CR1 |= 0x01; // Enable timer	
	TIM3_BKR |= 0xF0; // Enable timer CC1 output

	// 0: Enable IR output
	// 1: Enable high sink LED driver
	IR_CR = 0b00000001;
	// IR_CR = 0b00000011;
}

void disable_ir(void) {
	IR_CR = 0x00;

	TIM2_BKR &= ~0xF0; // Disable timer CC1 output
	TIM2_CR1 &= ~0x01; // Disable timer

	TIM3_BKR &= ~0xF0; // Disable timer CC1 output
	TIM3_CR1 &= ~0x01; // Disable timer	
}
