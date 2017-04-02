#ifndef __AS5048_H__
#define __AS5048_H__

/*******************************************************************************************************///Including Header Files
 #include <stdbool.h>
 #include <Driver_Base.h>
/*******************************************************************************************************///Define Struct/Union Type
typedef union
{
    unsigned short Dat;
    struct
    {
        unsigned short Value:14;
        unsigned short Inf:1;
        unsigned short Parity:1;
    }content;
}AS5048_Package;
/*******************************************************************************************************///Define Macro
 #define AS5048_NOP 0x0000
 #define AS5048_ERR 0x0001
 #define AS5048_MAG 0x3ffe
 #define AS5048_ANG 0x3fff
/*******************************************************************************************************///Extern Symbols

/*******************************************************************************************************///Inline Functions
 #define RW_AS5048(a) SendReceive_DByte_SPI(a)
 #define CS_H_AS5048  NssCtlH_SPI
 #define CS_L_AS5048  NssCtlL_SPI
/*******************************************************************************************************///Extern Functions
 extern void Write_AS5048(unsigned short Addr, unsigned short Dat);
 extern bool Read_AS5048(unsigned short Addr, unsigned short* Dat);

#endif
