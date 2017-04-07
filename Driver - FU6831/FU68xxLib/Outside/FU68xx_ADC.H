#ifndef __FU68XX_ADC_H__
#define __FU68XX_ADC_H__

#include <FU68xx_Type.h>

/*************************************************************************************///Defined Register
 #define ADC_CFG                *(__IO uint8_t  xdata *)0x4035
 #define ADC_MASK               *(__IO uint8_t  xdata *)0x4036
 #define ADC_STA                *(__IO uint8_t  xdata *)0x4037

 #define ADC_DR0                *(__IO uint16_t xdata *)0x4038
 #define ADC_DR1                *(__IO uint16_t xdata *)0x403a
 #define ADC_DR2                *(__IO uint16_t xdata *)0x403c
 #define ADC_DR3                *(__IO uint16_t xdata *)0x403e
 #define ADC_DR4                *(__IO uint16_t xdata *)0x4040
 #define ADC_DR5                *(__IO uint16_t xdata *)0x4042
 #define ADC_DR6                *(__IO uint16_t xdata *)0x4044
 #define ADC_DR7                *(__IO uint16_t xdata *)0x4046
 #define ADC_SYSC               *(__IO uint16_t xdata *)0x4048
/*************************************************************************************///Defined CMD
 #define ADC_EN                 0x80
 #define ADC_BUSY               0x40
 #define ADC_IF                 0x01
/*************************************************************************************///External Function
 #define EN_ADC                 ADC_STA |= ADC_EN
 #define Trigger_ADC            ADC_STA |= ADC_BUSY
 #define FlagCheck_ADC(a)       ((ADC_STA & a) == a)
 #define FlagClean_ADC(a)       (ADC_STA &= ~a)
 extern void Init_ADC(uint8_t Channel, uint8_t Time);


#endif
