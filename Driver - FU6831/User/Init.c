/*
* @Filename:           Init.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-01 23:25:09
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-02 00:02:34
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-04-02 00:01:55                           创建文件 //
///////////////////////////////////////////////////////////

#include <Init.h>

/*******************************************************************************************************///Including Header Files
#include <FU68xx_MCU.h>
#include <API_Conf.h>

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
    Init_SPI(L4_2, MASTER, 2000000, false);
    Init_CTimer(2, TIM_CR0_DIV4 | TIM_CR0_Mode_Tick, TIM_CR1_IRQ_IFE | TIM_CR1_EN, 12000, 0);
    EA = 1;
}
