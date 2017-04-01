/*
* @Filename:           main.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-01 23:45:04
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-01 23:46:16
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-04-01 23:45:45                           创建文件 //
///////////////////////////////////////////////////////////


/*******************************************************************************************************///Including Header Files
#include <FU68xx_MCU.h>
#include <intrins.h>
#include <Interrupt.h>
#include <Driver_Conf.h>
#include <API_Conf.h>
#include <Init.h>
/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols
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
/*******************************************************************************************************///Function Subject
void main(void)
{
    Init();

    NssCtlH_SPI;
    while (1)
    {
        NssCtlL_SPI;
//        unsigned char SendReceive_Byte_SPI(unsigned char SendDat)
//

    }
}
