#ifndef __FU68XX_SV_H__
#define __FU68xx_SV_H__

#include <FU68xx_Type.h>

/*************************************************************************************///Defined Register
 sfr   SV_CR  =                          0xe1;
 sfr16 SV_US  =                          0xe2;
 sfr16 SV_ANG =                          0xe4;

 #define SV_ARR                          *(__IO uint16_t xdata *)0x4060
 #define SV_SIN                          *(__IO  int16_t xdata *)0x407c
 #define SV_COS                          *(__IO  int16_t xdata *)0x407e
/*************************************************************************************///Defined CMD
 #define SV_CR_Mode_SPWM                0x80
 #define SV_CR_Mode_SVPWM               0x02
 #define SV_CR_Mode_SinCos              0x00

 #define SV_CR_SEG_5                    0x04
 #define SV_CR_SEG_7                    0x00

 #define SV_CR_Polar_1                  0x00
 #define SV_CR_Polar_2                  0x10

 #define SV_EN                          0x01
 #define SV_Flag_Busy                   0x80
/*************************************************************************************///External Function
 #define Init_SV(a)                     SV_CR = a
 #define Set_SV_US(a)                   SV_US = a
 #define Set_SV_Theta(a)                SV_ANG = a
 #define Set_SV_ARR(a)                  SV_ARR = a
 #define Enable_SV                      SV_CR = SV_EN
 #define BusyCheck_SV                   ((SV_CR & SV_Flag_Busy) == SV_Flag_Busy)


#endif
