#ifndef __AS5048_H__
#define __AS5048_H__

/*******************************************************************************************************///Including Header Files
 #include <stdbool.h>
 #include <Driver_Base.h>
/*******************************************************************************************************///Define Struct/Union Type

/*******************************************************************************************************///Define Macro
 #define AS5048_NOP 0x0000
 #define AS5048_ERR 0x0001
 #define AS5048_MAG 0x3ffe
 #define AS5048_ANG 0x3fff
/*******************************************************************************************************///Extern Symbols

/*******************************************************************************************************///Inline Functions
 #define RW_AS5048(a) SendReceive_Byte_SPI(a)
/*******************************************************************************************************///Extern Functions
 extern void Write_AS5048(unsigned short Addr, unsigned short Dat);
 extern void Read_AS5048(unsigned short Addr, unsigned short* Dat);

#endif
