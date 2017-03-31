#ifndef __FU68XX_SFR_H__
#define __FU68XX_SFR_H__

sfr PSW  = 0xd0;
sbit CY  = PSW^7;
sbit AC  = PSW^6;
sbit F0  = PSW^5;
sbit RS1 = PSW^4;
sbit RS0 = PSW^3;
sbit OV  = PSW^2;
sbit F1  = PSW^1;
sbit P   = PSW^0;

#endif