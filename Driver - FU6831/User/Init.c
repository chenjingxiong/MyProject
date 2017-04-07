/*
* @Filename:           Init.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-01 23:25:09
*
* @Last Modified by:   Any
* @Last Modified time: 2017-04-07 16:05:46
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
    Init_SV(SV_CR_Mode_SinCos);
    Set_SV_US(UQx(IMax));
    Set_SV_Theta(8192);
    Enable_SV;
    while (BusyCheck_SV);


    Init_FOC();
    Set_FOC_DMax(SV_COS);
    Set_FOC_DMin(SV_COS);
    Set_FOC_DOut(SV_COS);
    Set_FOC_DKp(0);
    Set_FOC_DKi(0);
    Set_FOC_DRef(0);
    Set_FOC_QMax(SV_SIN);
    Set_FOC_QMin(SV_SIN);
    Set_FOC_QOut(SV_SIN);
    Set_FOC_QKp(0);
    Set_FOC_QKi(0);
    Set_FOC_QRef(0);

    Init_UART(0, UARTMODE1, 115200, false);
    Reset_ANO_Package(0xf1, DAT_LEN);

    Init_SPI(L4_3, MASTER, 2000000, false);
    CS_L_AS5048;
    RW_AS5048(AS5048_NOP);
    CS_H_AS5048;

    Init_RGB();
    Init_CTimer(2, TIM_CR0_DIV4 | TIM_CR0_Mode_Tick, TIM_CR1_IRQ_IFE | TIM_CR1_EN, 12000, 0);

    EA = 1;
}
