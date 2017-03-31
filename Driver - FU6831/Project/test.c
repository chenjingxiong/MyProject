//文件名：test.c
//说明：4CHOnOff
//Log
//Timer         Writer      Thing                                 Ver
//2016-12-19    Any         创建文件                              V1.0


#include <FU68xx_MCU.h>
#include <intrins.h>
#include <Parity.h>

union
{
    uint16_t Dat;
    uint8_t Dat8[2];
    struct
    {
        uint16_t Parity:1;
        uint16_t Inf:1;
        uint16_t Value:14;
    }Detail;
}Package;


void main(void)
{
    P3OE = 0xc0;
    Init_SPI(L4_2, MASTER, 2000000, false);
    NssCtlH_SPI;
    while (1)
    {
        NssCtlL_SPI;
//        unsigned char SendReceive_Byte_SPI(unsigned char SendDat)
    }
}
