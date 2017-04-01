#ifndef __FU68xx_CTimer_H__
#define __FU68XX_CTIMER_H__

#include <stdbool.h>

/*************************************************************************************///Defined Register
//TIMER2
sfr TIM2_CR0    =           0xa1;
sfr TIM2_CR1    =           0xa9;

sfr16 TIM2_CNTR =           0xaa;
sfr16 TIM2_DR   =           0xac;
sfr16 TIM2_ARR  =           0xae;


//TIMER3
sfr TIM3_CR0    =           0x9c;
sfr TIM3_CR1    =           0x9d;

sfr16 TIM3_CNTR =           0xa2;
sfr16 TIM3_DR   =           0xa4;
sfr16 TIM3_ARR  =           0xa6;


//TIMER4
sfr TIM4_CR0    =           0x9e;
sfr TIM4_CR1    =           0x9f;
sfr TIM4_DRH    =           0x95;

sfr16 TIM4_CNTR =           0x92;
sfr16 TIM4_DR   =           0x94;
sfr16 TIM4_ARR  =           0x96;

//TIMER5
sfr TIM5_CR0    =           0x89;
sfr TIM5_CR1    =           0x91;

sfr16 TIM5_CNTR =           0x8a;
sfr16 TIM5_DR   =           0x8c;
sfr16 TIM5_ARR  =           0x8e;

/*************************************************************************************///Defined CMD
//CR0
//PSC
#define TIM_CR0_DIV1                    0x00
#define TIM_CR0_DIV2                    0x20
#define TIM_CR0_DIV4                    0x40
#define TIM_CR0_DIV8                    0x60
#define TIM_CR0_DIV16                   0x80
#define TIM_CR0_DIV32                   0xa0
#define TIM_CR0_DIV64                   0xc0
#define TIM_CR0_DIV128                  0xe0

//
#define TIM_CR0_Mode_Time               0x00        //计时模式             //234
#define TIM_CR0_Mode_Tick               0x01        //计时模式             //234
#define TIM_CR0_Mode_Out1               0x11        //输出模式(小于 =0)    //234
#define TIM_CR0_Mode_Out2               0x19        //输出模式(小于 =1)    //234
#define TIM_CR0_Mode_CounterDown        0x02        //下计数模式           //2
#define TIM_CR0_Mode_CounterUp          0x06        //上计数模式           //2


#define TIM_CR1_IRQ_IDE                 0x10
#define TIM_CR1_IRQ_IFE                 0x08
#define TIM_CR1_FE                      0x04
#define TIM_CR1_SINGLE                  0x02
#define TIM_CR1_EN                      0x01


#define TIM_CR1_Flag_IR                 0x80
#define TIM_CR1_Flag_IP                 0x40
#define TIM_CR1_Flag_IF                 0x20
/*************************************************************************************///External Function
#define FlagCheck_CTimer2(a) ((TIM2_CR1 & a) == a)
#define FlagCheck_CTimer3(a) ((TIM3_CR1 & a) == a)
#define FlagCheck_CTimer4(a) ((TIM4_CR1 & a) == a)
#define FlagCheck_CTimer5(a) ((TIM5_CR1 & a) == a)

#define FlagClear_CTimer2(a) TIM2_CR1 &= ~a
#define FlagClear_CTimer3(a) TIM3_CR1 &= ~a
#define FlagClear_CTimer4(a) TIM4_CR1 &= ~a
#define FlagClear_CTimer5(a) TIM5_CR1 &= ~a


extern void Init_CTimer(unsigned char Num, unsigned char cr0, unsigned char cr1, unsigned short arr, unsigned short dr);
extern void switch_CTimer(unsigned char Num, bool sw);
extern char irq_CTimer(unsigned char Num);

#endif
