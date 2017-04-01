#ifndef __FU68XX_TIMER0_H__
#define __FU68XX_TIMER0_H__

#include <XREG.h>

sfr TIM0IER    = 0xb9;
sfr TIM0SR     = 0xb1;
sfr16 TIM0CCR1 = 0xb6;
sfr16 TIM0CCR2 = 0xba;
sfr16 TIM0CCR3 = 0xbc;
sfr16 TIM0CCR4 = 0xbe;

#define TIM0CR    XBYTE[0x4058]
#define TIM0EGR   XBYTE[0x4059]
#define TIM0CCMR1 XBYTE[0x405a]
#define TIM0CCMR2 XBYTE[0x405b]
#define TIM0CCER1 XBYTE[0x405c]
#define TIM0CCER2 XBYTE[0x405d] 
#define TIM0CNTR  *(volatile unsigned short xdata *) 0x405e
#define TIM0ARR   *(volatile unsigned short xdata *) 0x4060

#define TIM0PSCR  XBYTE[0x4062]   
#define TIM0RCR   XBYTE[0x4063]   
#define TIM0DTR   XBYTE[0x4064]

#endif