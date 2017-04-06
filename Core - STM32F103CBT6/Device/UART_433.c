/*
* @Filename:           UART_433.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-06 23:11:33
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-06 23:32:09
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-04-06 23:27:39                           创建文件 //
///////////////////////////////////////////////////////////

#include <UART_433.h>

/*******************************************************************************************************///Including Header Files
#include <API_UART.h>
#include <API_SYSCLK.h>
/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols

/*******************************************************************************************************///Function Subject
/**
 * 初始化433无线串口
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-06
 *
 * @param   Num        串口号
 * @param   Baud       波特率
 * @param   Config     校验位&停止位
 * @param   Len        字长
 */
void Init_433(uint8_t Num, uint32_t Baud, uint8_t Config, uint8_t Len)
{
    GPIO_InitTypeDef GPIOBASE;

    GPIOBASE.GPIO_Speed = GPIO_Speed_50MHz;

    RCC->APB2ENR |= M0_PORT_CLK;
    GPIOBASE.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIOBASE.GPIO_Pin   = M0_Pin;
    GPIO_Init(M0_BASE, &GPIOBASE);

    RCC->APB2ENR |= M1_PORT_CLK;
    GPIOBASE.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIOBASE.GPIO_Pin   = M1_Pin;
    GPIO_Init(M1_BASE, &GPIOBASE);

    RCC->APB2ENR |= AUX_PORT_CLK;
    GPIOBASE.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
    GPIOBASE.GPIO_Pin   = AUX_Pin;
    GPIO_Init(AUX_BASE, &GPIOBASE);


    Init_UART(Num, Baud, Config, Len);

    M0_BASE->BSRR = (uint32_t)M0_Pin << 8;
    M1_BASE->BSRR = (uint32_t)M1_Pin << 8;
    while (!GPIO_ReadInputDataBit(AUX_BASE, AUX_Pin));

    M0_BASE->BSRR = M0_Pin;
    M1_BASE->BSRR = M1_Pin;
    while (!GPIO_ReadInputDataBit(AUX_BASE, AUX_Pin));

    Delay_SYS(100, ms);

    USART_ClearFlag(USART1, USART_FLAG_TC);
}
