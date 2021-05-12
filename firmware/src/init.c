#include "init.h"

void init(void) {
	init_clock();

	// RM0013 11.3.1
	// If the AWU is not in use, then the AWUTB[3:0] bits the Timebase selection register (AWU_TBR) should be loaded
	// with 0b0000 to reduce power consumption.
	AWU_TBR = 0x00;

	// Global configuration register:
	// 0: SWIM disabled (0)
	// 1: Interrupt-only activation level (1) - return to HALT state after interrupt handlers return
	// CFG_GCR = 0b00000010;
	CFG_GCR = 0b00000000;

	init_gpio();
	init_tim2();
	init_tim3();

	_enable_interrupts();
}

void init_clock(void) {
	// Set clock to 16MHz (0x00)
	// RM0013 9.2.1
	// In applications where the MCU can be halted for certain periods, the power consumption can be minimized by
	// keeping a fast clock (high performance execution) during active periods, in order to reduce the ratio between
	// active periods and Halt (that is “zero”- consumption) periods.
	CLK_CKDIVR = 0x00;

	// 0: Enable TIM2
	// 1: Enable TIM3
	CLK_PCKENR = 0b00000011;
}

void init_gpio(void) {
	// Port A:
	// 0:   IR LED -> Output (DDR=1), open drain (CR1=0), normally high
	// 1:   Reset  -> Ignored*
	// 2-7: Unused -> Output (DDR=1), push-pull (CR1=1), low
	// *The reset pin is not configured for GPIO by default. See: RM0013 7.2.2
	PA_DDR = 0b11111101;
	PA_CR1 = 0b11111100;
	PA_ODR = 0b00000001;
	
	// Port B:
	// 0-6: Rows 0-6 -> Input (DDR=0), pull-up (CR1=1), interrupts enabled (CR2=1)
	// 7:   Unused   -> Output (DDR=1), push-pull (CR1=1), low
	PB_DDR = 0b10000000;
	PB_CR1 = 0b11111111;
	PB_CR2 = 0b01111111;
	PB_ODR = 0b00000000;
	
	// Port C:
	// 0-2: Columns 0-2 -> Output (DDR=1), open drain* (CR1=0), low during halt
	// 3-7: Unused      -> Output (DDR=1), push-pull (CR1=1), low
	// *Ignored for true open drain pins (C0, C1)
	PC_DDR = 0b11111111;
	PC_CR1 = 0b11111000;
	PC_ODR = 0b00000000;

	// Port D:
	// 0:   Status LED -> Output (DDR=1), push-pull (CR1=1), low during halt
	// 1-7: Unused     -> Output (DDR=1), push-pull (CR1=1), low
	PD_DDR = 0b11111111;
	PD_CR1 = 0b11111111;
	PD_ODR = 0b00000000;

	// 2-3: Unused
	// 0-1: Trigger EXTIB instead of EXTI[7:0] for pins PB[7:0]
	EXTI_CONF = 0b00000011;

	// 2-3: Unused
	// 0-1: Trigger Port B interrupt on falling edge only (10)
	EXTI_CR3 = 0b00000010;
}

void init_tim2(void) {
	// Count value
	TIM2_ARRH = (TIMER_COUNT_38KHz >> 8) & 0xFF;
	TIM2_ARRL = (TIMER_COUNT_38KHz >> 0) & 0xFF;

	// Prescaler = 1
	TIM2_PSCR = 0x00;

	// 4:   Direction           -> Up (0)
	// 5-6: Center-aligned mode -> Edge aligned (00)
	TIM2_CR1 = 0b00000000;

	// 0: Output enable   -> OC1 signal is output on the corresponding output pin (1)
	// 1: Output polarity -> OC1 active high (0)
	TIM2_CCER1 = 0b00000001;

	// 0-1: CC1 channel is configured as output (00)
	// 4-6: Output compare mode -> PWM mode 1 (110) - In up-counting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	TIM2_CCMR1 = 0b01100000;

	// Pulse width = 50%
	TIM2_CCR1H = ((TIMER_COUNT_38KHz / 2) >> 8) & 0xFF;
	TIM2_CCR1L = ((TIMER_COUNT_38KHz / 2) >> 0) & 0xFF;

}

void init_tim3(void) {
	// Count value
	TIM3_ARRH = (TIMER_COUNT_562_5uS >> 8) & 0xFF;
	TIM3_ARRL = (TIMER_COUNT_562_5uS >> 0) & 0xFF;

	// Prescaler = 1
	TIM3_PSCR = 0x00;

	// 4:   Direction           -> Up (0)
	// 5-6: Center-aligned mode -> Edge aligned (00)
	TIM3_CR1 = 0b00000000;

	// 0: Output enable   -> OC1 signal is output on the corresponding output pin (1)
	// 1: Output polarity -> OC1 active high (0)
	TIM3_CCER1 = 0b00000001;

	// 0-1: CC1 channel is configured as output (00)
	// 4-6: Output compare mode -> Frozen (000) - The comparison between the output compare register TIMx_CCR1 and the counter TIMx_CNT has no effect on the outputs
	TIM3_CCMR1 = 0b00000000;

	// 0: Enable update interrupt
	TIM3_IER = 0x01;
}
