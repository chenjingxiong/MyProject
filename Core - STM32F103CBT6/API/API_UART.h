#ifndef __API_UART_H__
#define __API_UART_H__

/*******************************************************************************************************///Including Header Files
#include <stm32f10x.h>
/*******************************************************************************************************///Define Struct/Union Type

/*******************************************************************************************************///Define Macro
//Parity
#define None            USART_Parity_No
#define Even            USART_Parity_Even
#define Odd             USART_Parity_Odd

//StopBit
#define S0_5            USART_StopBits_0_5
#define S1_0            USART_StopBits_1
#define S1_5            USART_StopBits_1_5
#define S2_0            USART_StopBits_2


#define Printf_USART    USART1
/*******************************************************************************************************///Extern Symbols

/*******************************************************************************************************///Inline Functions

/*******************************************************************************************************///Extern Functions
extern void Init_UART(uint8_t Num, uint32_t Baud, uint8_t Config, uint8_t Len);

#endif
