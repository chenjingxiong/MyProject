#ifndef __FU68xx_SV_H__
#define __FU68xx_SV_H__

#include <XREG.h>

sfr SVCR = 0xe1;
sfr16 SVUS = 0xe2;
sfr16 SVANG = 0xe4;
#define SVARR *(volatile unsigned short xdata *) 0x4060
#define SVSIN *(volatile unsigned short xdata *) 0x407c
#define SVCOS *(volatile unsigned short xdata *) 0x407e

#endif