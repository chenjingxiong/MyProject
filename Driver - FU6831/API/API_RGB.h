#ifndef __API_RGB_H__
#define __API_RGB_H__

/*******************************************************************************************************///Including Header Files
#include <FU68xx_GPIO.h>
/*******************************************************************************************************///Define Struct/Union Type

/*******************************************************************************************************///Define Macro
#define R_OE            P3OE
#define R_Pin           P37
#define R_PinNum        0x80

#define G_OE            P3OE
#define G_Pin           P36
#define G_PinNum        0x40

#define B_OE            P3OE
#define B_Pin           P37
#define B_PinNum        0x80
/*******************************************************************************************************///Extern Symbols

/*******************************************************************************************************///Inline Functions
#define Write_RGB(a, b)    a = b
#define Shine_RGB(a)       a = !a
/*******************************************************************************************************///Extern Functions
extern void Init_RGB(void);

#endif
