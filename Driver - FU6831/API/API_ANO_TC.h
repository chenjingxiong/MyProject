#ifndef __API_ANO_TC_H__
#define __API_ANO_TC_H__

/*******************************************************************************************************///Including Header Files
#include <stdbool.h>
#include <API_Base.h>
#include <stdio.h>
/*******************************************************************************************************///Define Struct/Union Type

/*******************************************************************************************************///Define Macro
#define BUFF_LEN (5 + DAT_LEN)
#define DAT_LEN  2
/*******************************************************************************************************///Extern Symbols

/*******************************************************************************************************///Inline Functions
#define Send_ANO_BUFF(a) putchar(a)
/*******************************************************************************************************///Extern Functions
extern void Reset_ANO_Package(unsigned char Cmd, unsigned char Len);
extern bool Load_ANO_Package(unsigned char Dat);
extern bool Send_ANO_Package(void);

#endif
