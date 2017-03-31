//文件名：FU68xx_GPIO.h
//说明：FU68系列芯片的IO口寄存器映射
//Log
//Timer 		Writer      Thing
//2016-8-1		Any			创建文件
//2016-8-1      Any         取消GPIO操作函数，直接采用寄存器操作


#ifndef __FU68XX_GPIO_H__
#define __FU68XX_GPIO_H__

#include <XREG.h>

//GPIO
sfr P0   = 0x80;
sfr P1   = 0x90;
sfr P2   = 0xA0;
sfr P3   = 0xB0;

sfr P0OE = 0xfc;			// P0输出使能寄存器
sfr P1OE = 0xfd;			// P1输出使能寄存器
sfr P2OE = 0xfe;			// P2输出使能寄存器
sfr P3OE = 0xff;			// P3输出使能寄存器

sfr DRVOUT = 0xf8;

#define P1AN   XBYTE[0x4050]	// P1模拟使能寄存器
#define P2AN   XBYTE[0x4051]	// P2模拟使能寄存器
#define P3AN   XBYTE[0x4052]	// P3模拟使能寄存器

#define P0PU   XBYTE[0x4053]    // P0上拉使能寄存器  
#define P1PU   XBYTE[0x4054]	// P1上拉使能寄存器
#define P2PU   XBYTE[0x4055]	// P2上拉使能寄存器
#define P3PU   XBYTE[0x4056]	// P3上拉使能寄存器
#define P4PU   XBYTE[0x4057]    // P4上拉使能寄存器

#define PHSEL  XBYTE[0x404c]    //端口复用
#define DRVCTL XBYTE[0x404d]

sbit P00 = P0^0;
sbit P01 = P0^1;
sbit P02 = P0^2;
sbit P03 = P0^3;
sbit P04 = P0^4;
sbit P05 = P0^5;
sbit P06 = P0^6;
sbit P07 = P0^7;

sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;
sbit P14 = P1^4;
sbit P15 = P1^5;
sbit P16 = P1^6;
sbit P17 = P1^7;

sbit P20 = P2^0;
sbit P21 = P2^1;
sbit P22 = P2^2;
sbit P23 = P2^3;
sbit P24 = P2^4;
sbit P25 = P2^5;
sbit P26 = P2^6;
sbit P27 = P2^7;

sbit P30 = P3^0;
sbit P31 = P3^1;
sbit P32 = P3^2;
sbit P33 = P3^3;
sbit P34 = P3^4;
sbit P35 = P3^5;
sbit P36 = P3^6;
sbit P37 = P3^7;

#endif
