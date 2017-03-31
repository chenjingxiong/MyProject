#ifndef __FU68XX_ADC_H__
#define __FU68XX_ADC_H__

#include <XREG.h>
 
#define ADCCFG XBYTE[0x4035]
#define ADCMASK XBYTE[0x4036]
#define ADCSTA XBYTE[0x4037]

#define ADCDR0 *(volatile unsigned int xdata *)0x4038
#define ADCDR1 *(volatile unsigned int xdata *)0x403a
#define ADCDR2 *(volatile unsigned int xdata *)0x403c
#define ADCDR3 *(volatile unsigned int xdata *)0x403e
#define ADCDR4 *(volatile unsigned int xdata *)0x4040
#define ADCDR5 *(volatile unsigned int xdata *)0x4042
#define ADCDR6 *(volatile unsigned int xdata *)0x4044
#define ADCDR7 *(volatile unsigned int xdata *)0x4046
#define ADCSCY *(volatile unsigned int xdata *)0x4048

extern void Trigger_ADC(void);


#endif