//文件名：FU68xx_Flash.h
//说明：FU68系列芯片的FLASH底层驱动
//Log
//Timer 		Writer      Thing                               Ver
//2016-8-05		Any			创建文件                            V1.0

#ifndef __FU68XX_FLASH_H__
#define __FU68XX_FLASH_H__

#include <Type.h>
#include <stdbool.h>

sfr PSCTL = 0x85;
sfr FLKEY = 0x84;


extern bool Erase_Flash(U8 xdata *FlashAddress);
extern bool WriteByte_Flash(U8 xdata *FlashAddress, U8 FlashData);
extern void Write_Flash(U8 xdata *FlashAddress, U8* FlashData, U8 sizes);
extern U8 Read_Flash(U8 code *FlashAddress);

#endif
