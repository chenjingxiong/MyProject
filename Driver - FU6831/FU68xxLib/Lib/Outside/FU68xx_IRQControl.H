#ifndef __FU68XX_IRQCONTROL_H__
#define __FU68XX_IRQCONTROL_H__

#include <stdbool.h>

sbit EA = 0xaf;
sfr IP0 = 0xb8;
sfr IP1 = 0xc0;
sfr IP2 = 0xc8;
sfr IP3 = 0xd8;

sbit IRQFOC_H   = IP0^7;
sbit IRQFOC_L   = IP0^6;
sbit IRQINT1_H  = IP0^5;
sbit IRQINT1_L  = IP0^4;
sbit IRQINT0_H  = IP0^3;
sbit IRQINT0_L  = IP0^2;
sbit IRQLVW_H   = IP0^1;

sbit IRQLVW_L   = IP0^0;
sbit IRQCMP_H   = IP1^7;
sbit IRQCMP_L   = IP1^6;
sbit IRQADC_H   = IP1^5;
sbit IRQADC_L   = IP1^4;
sbit IRQTIM1_H  = IP1^3;
sbit IRQTIM1_L  = IP1^2;
sbit IRQTIM0_H  = IP1^1;
sbit IRQTIM0_L  = IP1^0;

sbit IRQTSD_H   = IP2^7;
sbit IRQTSD_L   = IP2^6;
sbit IRQTIM45_H = IP2^5;
sbit IRQTIM45_L = IP2^4;
sbit IRQTIM23_H = IP2^3;
sbit IRQTIM23_L = IP2^2;
sbit IRQRTC_H   = IP2^1;
sbit IRQRTC_L   = IP2^0;

sbit IRQMCD_H   = IP3^7;
sbit IRQMCD_L   = IP3^6;
sbit IRQSPI_H   = IP3^5;
sbit IRQSPI_L   = IP3^4;
sbit IRQI2C_H   = IP3^3;
sbit IRQI2C_L   = IP3^2;
sbit IRQUART_H  = IP3^1;
sbit IRQUART_L  = IP3^0;

sfr TCON = 0x88;

#define 	IRQ_FOC 	0
#define 	IRQ_INT1 	1
#define 	IRQ_INT0 	2
#define 	IRQ_LVW 	3

#define 	IRQ_CMP 	4
#define 	IRQ_ADC 	5
#define 	IRQ_TIM1 	6
#define 	IRQ_TIM0 	7

#define 	IRQ_TSD 	8
#define 	IRQ_TIM45 	9
#define 	IRQ_TIM23 	10
#define 	IRQ_RTC 	11

#define 	IRQ_MCD 	12
#define 	IRQ_SPI 	13
#define 	IRQ_I2C 	14
#define 	IRQ_UART 	15

extern void Switch_IRQ(bool sw);
extern void Setting_IRQL(unsigned char IRQSource, unsigned char IRQPriority);

#endif
