#ifndef __FU68XX_UART_H__
#define __FU68XX_UART_H__

#include <stdbool.h>

//UART
sfr UTCR   = 0x98;
sfr UTDR   = 0x99;
sfr16 UTBU = 0x9a;
sfr UTBUH  = 0x9b;
sfr UTBUL  = 0x9a;

sbit TI    = 0x99;
sbit RI    = 0x98;

sbit ES    = 0xac;

#define UARTMODE0 0x00
#define UARTMODE1 0x40
#define UARTMODE2 0x80
#define UARTMODE3 0xc0

#define EnRECEIVE 0x10
#define EnMASTERS 0x20

extern void Init_UART(unsigned char addr, unsigned char Config, unsigned long bund, bool irq);
extern void Send_UART(unsigned char* str, unsigned char Size);
extern void Send_Byte_UART(unsigned char dat);

#endif
