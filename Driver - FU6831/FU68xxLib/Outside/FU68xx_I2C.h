#ifndef __FU68XX_I2C_H__
#define __FU68XX_I2C_H__

#include <XREG.h>
#include <stdbool.h>

#define I2CMOD XBYTE[0x4028]
#define I2CID  XBYTE[0x4029]
#define I2CDAT XBYTE[0x402a]
#define I2CSTA XBYTE[0x402b]

#define ADDR_AUTO_ADD

#define I2C_100k 0
#define I2C_400k 2
#define I2C_1M   4

extern void Init_I2C(char speed);

extern bool Write_Byte_I2C(unsigned char addr7, unsigned char reg, unsigned char dat);
extern bool Read_Byte_I2C(unsigned char addr7, unsigned char reg, unsigned char* dat);
extern void Start_I2C(bool rw);
extern void Stop_I2C(void);
extern void Send_I2C(unsigned char Dat);
extern void Addr_I2C(unsigned char Addr7);
extern bool Get_Ack_I2C(void);
extern void Set_Ack_I2C(bool Ack);
extern void Enable_I2C(bool sw);

extern bool Write_Bits_I2C(unsigned char addr7, unsigned char reg, unsigned char bitS, unsigned char length, unsigned char dat);
extern bool Read_Bits_I2C(unsigned char addr7, unsigned char reg, unsigned char bitS, unsigned char length, unsigned char* dat);

extern bool Write_I2C(unsigned char addr7, unsigned char reg, unsigned char length, unsigned char* dat);
extern bool Read_I2C(unsigned char addr7, unsigned char reg, unsigned char length, unsigned char* dat);

extern char Write_Bit_I2C(unsigned char slave, unsigned char addr, unsigned char bitNum, unsigned char Data);
extern char Read_Bit_I2C(unsigned char slave, unsigned char addr, unsigned char bitNum, unsigned char *Data);

#endif
