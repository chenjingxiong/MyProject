#ifndef __FU68XX_SV_H__
#define __FU68xx_SV_H__

#include <FU68xx_Type.h>

sfr SVCR = 0xe1;
sfr16 SVUS = 0xe2;
sfr16 SVANG = 0xe4;
#define SVARR           *(__IO uint16_t xdata *)0x4060
#define SVSIN           *(__IO uint16_t xdata *)0x407c
#define SVCOS           *(__IO uint16_t xdata *)0x407e

#endif
