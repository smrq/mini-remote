typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char i8;
typedef signed short i16;
typedef signed long i32;

#define PORTA_ODR (*(volatile u8 *)0x5000)
#define PORTA_IDR (*(volatile u8 *)0x5001)
#define PORTA_DDR (*(volatile u8 *)0x5002)
#define PORTA_CR1 (*(volatile u8 *)0x5003)
#define PORTA_CR2 (*(volatile u8 *)0x5004)

#define PORTB_ODR (*(volatile u8 *)0x5005)
#define PORTB_IDR (*(volatile u8 *)0x5006)
#define PORTB_DDR (*(volatile u8 *)0x5007)
#define PORTB_CR1 (*(volatile u8 *)0x5008)
#define PORTB_CR2 (*(volatile u8 *)0x5009)

#define PORTC_ODR (*(volatile u8 *)0x500A)
#define PORTC_IDR (*(volatile u8 *)0x500B)
#define PORTC_DDR (*(volatile u8 *)0x500C)
#define PORTC_CR1 (*(volatile u8 *)0x500D)
#define PORTC_CR2 (*(volatile u8 *)0x500E)

#define PORTD_ODR (*(volatile u8 *)0x500F)
#define PORTD_IDR (*(volatile u8 *)0x5010)
#define PORTD_DDR (*(volatile u8 *)0x5011)
#define PORTD_CR1 (*(volatile u8 *)0x5012)
#define PORTD_CR2 (*(volatile u8 *)0x5013)

#define CLK_DIVR (*(volatile u8 *)0x50c0)
