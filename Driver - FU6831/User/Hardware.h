#ifndef __HARDWARE_H__
#define __HARDWARE_H__

/*******************************************************************************************************///Define Macro
 #define Q15(a)                                 (int16_t)(a * 32768.0)

 //Motor Parameter
 #define Pole                                   11

 //Calibration Parameter
 #define Criterion                              (uint16_t)(65536.0 / Pole)  //pu
 #define Angle_SensorToElectric(a)              (int16_t)((a % Criterion) * Pole) //pu

 //Sample Parameter
 #define Sample                                 0.5                               //Ω
 #define Amp_R1                                 12.0                              //kΩ
 #define Amp_R2                                 2.0                               //kΩ
 #define ADCRef                                 5.0                               //V
 #define Amp                                    (Amp_R1 / Amp_R2)
 #define IRange                                 (ADCRef / Amp / Sample / 2.0)     //A

 //Current Parameter
 #define IMax                                   0.5                               //A
 #define Correction                             0.75
 #define UQx(a)                                 Q15((a * Correction) / IRange)    //pu
 #define HalfUQx(a)                             (UQx(a) >> 1)                     //pu

#endif