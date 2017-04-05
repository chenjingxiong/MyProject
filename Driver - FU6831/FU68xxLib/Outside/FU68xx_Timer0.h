#ifndef __FU68XX_TIMER0_H__
#define __FU68XX_TIMER0_H__

#include <FU68xx_Type.h>

sfr TIM0IER    = 0xb9;
sfr TIM0SR     = 0xb1;
sfr16 TIM0CCR1 = 0xb6;
sfr16 TIM0CCR2 = 0xba;
sfr16 TIM0CCR3 = 0xbc;
sfr16 TIM0CCR4 = 0xbe;

#define TIM0CR    *(__IO uint8_t  xdata *)0x4058
#define TIM0EGR   *(__IO uint8_t  xdata *)0x4059
#define TIM0CCMR1 *(__IO uint8_t  xdata *)0x405a
#define TIM0CCMR2 *(__IO uint8_t  xdata *)0x405b
#define TIM0CCER1 *(__IO uint8_t  xdata *)0x405c
#define TIM0CCER2 *(__IO uint8_t  xdata *)0x405d
#define TIM0CNTR  *(__IO uint16_t xdata *)0x405e
#define TIM0ARR   *(__IO uint16_t xdata *)0x4060

#define TIM0PSCR  *(__IO uint8_t  xdata *)0x4062
#define TIM0RCR   *(__IO uint8_t  xdata *)0x4063
#define TIM0DTR   *(__IO uint8_t  xdata *)0x4064

#endif
