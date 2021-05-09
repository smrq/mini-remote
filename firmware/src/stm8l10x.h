#pragma once

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char i8;
typedef signed short i16;
typedef signed long i32;

#define F_CPU 16000000UL

#define INT_EXTIB 6
#define INT_TIM3_UPDATE 21

#define MEM(ADDR) (*(volatile u8 *)ADDR)

#define PA_ODR      MEM(0x5000)
#define PA_IDR      MEM(0x5001)
#define PA_DDR      MEM(0x5002)
#define PA_CR1      MEM(0x5003)
#define PA_CR2      MEM(0x5004)

#define PB_ODR      MEM(0x5005)
#define PB_IDR      MEM(0x5006)
#define PB_DDR      MEM(0x5007)
#define PB_CR1      MEM(0x5008)
#define PB_CR2      MEM(0x5009)

#define PC_ODR      MEM(0x500A)
#define PC_IDR      MEM(0x500B)
#define PC_DDR      MEM(0x500C)
#define PC_CR1      MEM(0x500D)
#define PC_CR2      MEM(0x500E)

#define EXTI_CR1    MEM(0x50A0)
#define EXTI_CR2    MEM(0x50A1)
#define EXTI_CR3    MEM(0x50A2)
#define EXTI_SR1    MEM(0x50A3)
#define EXTI_SR2    MEM(0x50A4)
#define EXTI_CONF   MEM(0x50A5)

#define PD_ODR      MEM(0x500F)
#define PD_IDR      MEM(0x5010)
#define PD_DDR      MEM(0x5011)
#define PD_CR1      MEM(0x5012)
#define PD_CR2      MEM(0x5013)

#define RST_SR      MEM(0x50B1)

#define CLK_CKDIVR  MEM(0x50C0)
#define CLK_PCKENR  MEM(0x50C3)
#define CLK_CCOR    MEM(0x50C5)

#define AWU_TBR     MEM(0x50F2)

#define TIM2_CR1    MEM(0x5250)
#define TIM2_IER    MEM(0x5254)
#define TIM2_SR1    MEM(0x5255)
#define TIM2_EGR    MEM(0x5257)
#define TIM2_CCMR1  MEM(0x5258)
#define TIM2_CCER1  MEM(0x525A)
#define TIM2_CNTRH  MEM(0x525B)
#define TIM2_CNTRL  MEM(0x525C)
#define TIM2_PSCR   MEM(0x525D)
#define TIM2_ARRH   MEM(0x525E)
#define TIM2_ARRL   MEM(0x525F)
#define TIM2_CCR1H  MEM(0x5260)
#define TIM2_CCR1L  MEM(0x5261)
#define TIM2_BKR    MEM(0x5264)
#define TIM2_OISR   MEM(0x5265)

#define TIM3_CR1    MEM(0x5280)
#define TIM3_IER    MEM(0x5284)
#define TIM3_SR1    MEM(0x5285)
#define TIM3_EGR    MEM(0x5287)
#define TIM3_CCMR1  MEM(0x5288)
#define TIM3_CCER1  MEM(0x528A)
#define TIM3_CNTRH  MEM(0x528B)
#define TIM3_CNTRL  MEM(0x528C)
#define TIM3_PSCR   MEM(0x528D)
#define TIM3_ARRH   MEM(0x528E)
#define TIM3_ARRL   MEM(0x528F)
#define TIM3_CCR1H  MEM(0x5290)
#define TIM3_CCR1L  MEM(0x5291)
#define TIM3_BKR    MEM(0x5294)
#define TIM3_OISR   MEM(0x5295)

#define IR_CR       MEM(0x52FF)

#define CFG_GCR     MEM(0x7F60)

#define ITC_SPR2    MEM(0x7F71)

#define _halt() __asm__("halt\n")
#define _enable_interrupts() __asm__("rim\n")
#define _disable_interrupts() __asm__("sim\n")

#define _delay_us(US) { for (u16 x = F_CPU * (US) / 1333333UL; x; --x) {} }
#define _delay_ms(MS) { for (u16 ms = (MS); ms; --ms) _delay_us(1000); }
