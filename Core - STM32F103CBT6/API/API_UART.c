/*
* @Filename:           API_UART.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-06 21:57:57
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-06 23:21:14
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-04-06 23:09:33                           创建文件 //
//2017-04-06 23:20:27                 修改UART时钟初始化 //
///////////////////////////////////////////////////////////

#include <API_UART.h>

/*******************************************************************************************************///Including Header Files
#include <stdio.h>
#include <API_SYSCLK.h>

/*******************************************************************************************************///Define Macro
/*******************************************************************************************************///Define Global Symbols
static struct
{
    uint32_t       GPIORcc;
    uint32_t       UARTRcc;
    uint16_t       TxPin;
    uint16_t       RxPin;
    GPIO_TypeDef*  GPIOBase;
    USART_TypeDef* UARTBase;
}UART_Inf[] =
{
    {RCC_APB2Periph_GPIOA, RCC_APB2Periph_USART1, GPIO_Pin_9,  GPIO_Pin_10, GPIOA, USART1},
    {RCC_APB2Periph_GPIOA, RCC_APB1Periph_USART2, GPIO_Pin_2,  GPIO_Pin_3,  GPIOA, USART2},
    {RCC_APB2Periph_GPIOB, RCC_APB1Periph_USART3, GPIO_Pin_10, GPIO_Pin_11, GPIOB, USART3}
};
/*******************************************************************************************************///Function Subject
/**
 * printf重定向函数
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-06
 *
 * @param   ch         发送的字符
 * @param   f          Unknow
 * @return             发送的字符
 */
int fputc(int ch, FILE *f)
{
    USART_SendData(Printf_USART, (uint8_t) ch);
    while (!USART_GetFlagStatus(Printf_USART, USART_FLAG_TC));

    return ch;
}

/**
 * scanf重定向函数
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-06
 *
 * @param   f          Unknow
 * @return             接收的字符
 */
int fgetc(FILE* f)
{
    while (!USART_GetFlagStatus(Printf_USART, USART_FLAG_RXNE));

    return (USART_ReceiveData(Printf_USART));
}

/**
 * 初始化串口
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-06
 *
 * @param   Num        串口号
 * @param   Baud       波特率
 * @param   Config     校验位&停止位设置
 * @param   Len        位长
 */
void Init_UART(uint8_t Num, uint32_t Baud, uint8_t Config, uint8_t Len)
{
    GPIO_InitTypeDef GPIOBASE;
    USART_InitTypeDef UARTBASE;

    Num--;
    RCC->APB2ENR |= UART_Inf[Num].GPIORcc;
    if (Num == 0) RCC->APB2ENR |= UART_Inf[Num].UARTRcc;
    else          RCC->APB1ENR |= UART_Inf[Num].UARTRcc;

    GPIOBASE.GPIO_Speed = GPIO_Speed_50MHz;

    GPIOBASE.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIOBASE.GPIO_Pin   = UART_Inf[Num].TxPin;
    GPIO_Init(UART_Inf[Num].GPIOBase, &GPIOBASE);

    GPIOBASE.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIOBASE.GPIO_Pin  = UART_Inf[Num].RxPin;
    GPIO_Init(UART_Inf[Num].GPIOBase, &GPIOBASE);


    UARTBASE.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    UARTBASE.USART_Mode                = USART_Mode_Tx | USART_Mode_Rx;
    UARTBASE.USART_BaudRate            = Baud;
    UARTBASE.USART_Parity              = Config & 0x0600;
    UARTBASE.USART_StopBits            = Config & 0x3000;
    UARTBASE.USART_WordLength          = (Len - 8) * 0x1000;
    USART_Init(UART_Inf[Num].UARTBase, &UARTBASE);

    USART_Cmd(UART_Inf[Num].UARTBase, ENABLE);

    Delay_SYS(1, ms);
}
