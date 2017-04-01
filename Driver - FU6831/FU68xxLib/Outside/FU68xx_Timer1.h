#ifndef __FU68XX_TIMER1_H__
#define __FU68XX_TIMER1_H__

#include <Type.h>

#define TIM1DTR    XBYTE[0x4064]   
#define TIM1CR0    XBYTE[0x4068]  
#define TIM1CR1    XBYTE[0x4069]   
#define TIM1CR2    XBYTE[0x406a]   
#define TIM1CR3    XBYTE[0x406b]   
#define TIM1IER    XBYTE[0x406c]   
#define TIM1SR     XBYTE[0x406d]

#define TIM1DR *(volatile unsigned int xdata *)0x406e
#define TIM1DRH    XBYTE[0x406e]   
#define TIM1DRL    XBYTE[0x406f]

#define TIM1DBR *(volatile unsigned int xdata *)0x4070
#define TIM1DBRH   XBYTE[0x4070]   
#define TIM1DBRL   XBYTE[0x4071]

#define TIM1BCCR *(volatile unsigned int xdata *)0x4072
#define TIM1BCCRH  XBYTE[0x4072]   
#define TIM1BCCRL  XBYTE[0x4073]

#define TIM1RARR *(volatile unsigned int xdata *)0x4074
#define TIM1RARRH  XBYTE[0x4074]   
#define TIM1RARRL  XBYTE[0x4075]

#define TIM1RCNTR *(volatile unsigned int xdata *)0x4076
#define TIM1RCNTRH XBYTE[0x4076]   
#define TIM1RCNTRL XBYTE[0x4077]

#define TIM1BARR *(volatile unsigned int xdata *)0x4078
#define TIM1BARRH  XBYTE[0x4078]   
#define TIM1BARRL  XBYTE[0x4079] 

#define TIM1BCNTR *(volatile unsigned int xdata *)0x407a
#define TIM1BCNTRH XBYTE[0x407a]   
#define TIM1BCNTRL XBYTE[0x407b] 






//CR0
//CPE
//#define 	None_Check 		0x00
//#define 	Rise_Check 		0x40
//#define 	Fall_Check 		0x80
//#define 	All_Check 		0xc0

////INC2
//#define 	Filter2_Dis 	0x00
//#define 	Filter2_En 		0x20

////INC1
//#define 	Filter1_Dis 	0x00
//#define 	Filter1_En 		0x10

////INC0
//#define 	Filter0_Dis 	0x00
//#define 	Filter0_En 		0x08

////IEE2
//#define 	Check2_Dis 		0x00
//#define 	Check2_En 		0x04

////IEE1
//#define 	Check1_Dis 		0x00
//#define 	Check1_En 		0x02

////IEE0
//#define 	Check0_Dis 		0x00
//#define 	Check0_En 		0x01


////CR1
////T1RCEN
//#define 	RCEN_Dis 		0x00
//#define 	RCEN_En 		0x80

////ROPM
////CR2
////BRS
//#define 	Write 			0x00
//#define 	Position 		0x80

////TIS
//#define 	CMP 			0x00
//#define 	GPIO 			0x40

////INM2
//#define 	C42 			0x00
//#define 	C82 			0x10
//#define 	16C2 			0x20
//#define 	32C2 			0x30

////INM1
//#define 	4C1 			0x00
//#define 	8C1 			0x04
//#define 	16C1 			0x08
//#define 	32C1 			0x0c

////INM0
//#define 	4C0 			0x00
//#define 	8C0 			0x01
//#define 	16C0 			0x02
//#define 	32C0 			0x03



//CR3
//PSC						
#define 	T_DIV1 			0x00
#define 	T_DIV2 			0x10
#define 	T_DIV4 			0x20
#define 	T_DIV8 			0x30
#define 	T_DIV16 		0x40
#define 	T_DIV32 		0x50
#define 	T_DIV64 		0x60
#define 	T_DIV128 		0x70
#define 	T_DIV256 		0x80
#define 	T_DIV512 		0x90
#define 	T_DIV1024 		0xa0
#define 	T_DIV2048 		0xb0
#define 	T_DIV4096 		0xc0
#define 	T_DIV8192 		0xd0
#define 	T_DIV16384 		0xe0
#define 	T_DIV32768 		0xf0

//OPS
#define 	DBR_Trigger 	0x00
#define 	Timer_Falling 	0x02
#define 	Position_Tri 	0x04
#define 	TFandP_Start 	0x06
#define 	TForP 			0x08
#define 	TForP_Once 		0x0a
#define 	Position_Once 	0x0c
#define 	TF_OandP_Start 	0x0e

//T1BCEN
#define 	T_OFF 			0x00
#define 	T_ON 			0x01

#endif
