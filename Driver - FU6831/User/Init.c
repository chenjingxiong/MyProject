/*
* @Filename:           Init.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-01 23:25:09
*
* @Last Modified by:   Any
* @Last Modified time: 2017-04-07 11:49:39
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-04-02 00:01:55                           创建文件 //
///////////////////////////////////////////////////////////

#include <Init.h>

/*******************************************************************************************************///Including Header Files
#include <FU68xx_MCU.h>

#include <API_Conf.h>
#include <Driver_Conf.h>

#include <Hardware.h>
/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols

/*******************************************************************************************************///Function Subject
/**
 * 初始化函数
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-02
 *
 */
void Init(void)
{
    Init_RGB();
    Init_SPI(L4_3, MASTER, 2000000, false);
    Init_CTimer(2, TIM_CR0_DIV4 | TIM_CR0_Mode_Tick, TIM_CR1_IRQ_IFE | TIM_CR1_EN, 12000, 0);
    Init_UART(0, UARTMODE1, 115200, false);
    Init_FOC();

    Set_DMax(0);
    Set_DMin(0);
    Set_DKp(0);
    Set_DKi(0);
    Set_DRef(0);

    Set_QMax(UQx);
    Set_QMin(UQx);
    Set_QKp(0);
    Set_QKi(0);
    Set_QRef(0);

    EA = 1;

    Reset_ANO_Package(0xf1, DAT_LEN);

    CS_L_AS5048;
    RW_AS5048(AS5048_NOP);
    CS_H_AS5048;

}
