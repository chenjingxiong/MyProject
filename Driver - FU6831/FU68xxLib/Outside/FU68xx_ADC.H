#ifndef __FU68XX_ADC_H__
#define __FU68XX_ADC_H__

#include <FU68xx_Type.h>

/*************************************************************************************///Defined Register
 #define ADCCFG              *(__IO uint8_t  xdata *)0x4035
 #define ADCMASK             *(__IO uint8_t  xdata *)0x4036
 #define ADCSTA              *(__IO uint8_t  xdata *)0x4037

 #define ADCDR0              *(__IO uint16_t xdata *)0x4038
 #define ADCDR1              *(__IO uint16_t xdata *)0x403a
 #define ADCDR2              *(__IO uint16_t xdata *)0x403c
 #define ADCDR3              *(__IO uint16_t xdata *)0x403e
 #define ADCDR4              *(__IO uint16_t xdata *)0x4040
 #define ADCDR5              *(__IO uint16_t xdata *)0x4042
 #define ADCDR6              *(__IO uint16_t xdata *)0x4044
 #define ADCDR7              *(__IO uint16_t xdata *)0x4046
 #define ADCSCY              *(__IO uint16_t xdata *)0x4048
/*************************************************************************************///Defined CMD
 #define ADC_EN           0x80
 #define ADC_BUSY         0x40
 #define ADC_IF           0x01
/*************************************************************************************///External Function
 #define EN_ADC           ADC_STA |= ADC_EN
 #define Trigger_ADC      ADC_STA |= ADC_BUSY
 #define FlagCheck_ADC(a) ((ADC_STA & a) == a)
 #define FlagClean_ADC(a) (ADC_STA &= ~a)
 extern void Init_ADC(uint8_t Channel, uint8_t Time);


#endif
