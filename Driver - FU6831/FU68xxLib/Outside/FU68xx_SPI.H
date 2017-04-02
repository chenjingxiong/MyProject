#ifndef __FU68XX_SPI_H__
#define __FU68XX_SPI_H__

#include <stdbool.h>
#include <FU68xx_Type.h>

/*************************************************************************************///Defined Register
sbit SPI_IE = 0xab;
#define SPI_CFG *(__IO uint8_t xdata *)0x4030
#define SPI_CTL *(__IO uint8_t xdata *)0x4031
#define SPI_SCR *(__IO uint8_t xdata *)0x4032
#define SPI_DAT *(__IO uint8_t xdata *)0x4033

/*************************************************************************************///Defined CMD
//SPICFG
#define MASTER          0x40
#define CPHA            0x20
#define CPOL            0x10

//Line_Mode
#define L4_3            0x0c //四线单主模式，空闲电平为高
#define L4_2            0x08 //四线单主模式，空闲电平为低
#define L4_1            0x04 //四线多主模式
#define L3              0x00 //三线模式

//Flag-->SPI_CTL
#define SPI_F_IF        0x80
#define SPI_F_WCOL      0x40
#define SPI_F_MODF      0x20
#define SPI_F_RXOVRN    0x10
#define SPI_F_TXBMT     0x02

//Flag-->SPI_CFG
#define SPI_F_BSY       0x80
#define SPI_F_SLVSEL    0x08
#define SPI_F_NSS       0x04
#define SPI_F_SRMT      0x02
#define SPI_F_RXBMT     0x01

/*************************************************************************************///External Function
#define NssCtlH_SPI             SPI_CTL |= 0x04
#define NssCtlL_SPI             SPI_CTL &= 0xfb
#define FlagCheck_SPI(a)        ((SPI_CTL & a) == a)
#define FlagCheck1_SPI(a)       ((SPI_CFG & a) == a)
#define FlagClear_SPI(a)        SPI_CTL &= ~a

extern void Init_SPI(char Line_Mode, char Config, unsigned long SPEED, bool EnIrq);
extern unsigned char SendReceive_Byte_SPI(unsigned char SendDat);
extern void SendReceive_Bytes_SPI(unsigned char* SendDat, unsigned char* ReceiveDat, unsigned char len);
extern unsigned short SendReceive_DByte_SPI(unsigned short SendDat);

#endif
