#ifndef __FU68XX_CTIMER_H__
#define __FU68XX_CTIMER_H__

#include <stdbool.h>
#include <XREG.h>

//CR0
//PSC
#define CT_DIV1   0x00 
#define CT_DIV2   0x20 
#define CT_DIV4   0x40 
#define CT_DIV8   0x60 
#define CT_DIV16  0x80 
#define CT_DIV32  0xa0 
#define CT_DIV64  0xc0 
#define CT_DIV128 0xe0

//OCM
#define AllWayLow   0x00 
#define AllWayHight 0x08 
#define OUT_IP      0x10 
#define OUT_RP      0x18

//CES
#define Falling 0x00 
#define Rising  0x04

//CTM&OM
#define Timer   0x00 
#define Counter 0x02
#define OUT 0x01

//CR1
//IDE, IFE
#define None   0x00 
#define Ife    0x08 
#define Ide    0x10 
#define IdeIfe 0x18

//FE
#define Unuse 0x00 
#define Use   0x04

//OPM
#define Continuity 0x00 
#define Single     0x02

//CEN
#define CT_OFF 0x00 
#define CT_ON  0x01



#define TIMXIR  0x80
#define TIMXIP  0x40
#define TIMXIF  0x20
#define TIMXCEN 0x01

//TIMER2
sfr TIM2CR0   = 0xa1;
sfr TIM2CR1   = 0xa9;

sfr16 TIM2CNTR = 0xaa;
sfr16 TIM2DR   = 0xac;
sfr16 TIM2ARR  = 0xae;
sfr16 TIM2CMTR = 0xb2;
sfr16 TIM2ADTR = 0xb4;


//TIMER3
sfr TIM3CR0   = 0x9c;
sfr TIM3CR1   = 0x9d;

sfr16 TIM3CNTR = 0xa2;
sfr16 TIM3DR   = 0xa4;
sfr16 TIM3ARR  = 0xa6;


//TIMER4
sfr TIM4CR0   = 0x9e;
sfr TIM4CR1   = 0x9f;

sfr16 TIM4CNTR = 0x92;
sfr16 TIM4DR   = 0x94;
sfr16 TIM4ARR  = 0x96;


//TIMER5
sfr TIM5CR0   = 0x89;
sfr TIM5CR1   = 0x91;

sfr16 TIM5CNTR = 0x8a;
sfr16 TIM5DR   = 0x8c;
sfr16 TIM5ARR  = 0x8e;


extern void Init_CTimer(unsigned char Num, unsigned char cr0, unsigned char cr1, unsigned short arr, unsigned short dr);
extern void switch_CTimer(unsigned char Num, bool sw);
extern char irq_CTimer(unsigned char Num);

#endif
