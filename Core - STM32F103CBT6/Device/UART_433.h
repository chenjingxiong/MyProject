#ifndef __UART_433_H__
#define __UART_433_H__

/*******************************************************************************************************///Including Header Files
#include <stm32f10x.h>
/*******************************************************************************************************///Define Struct/Union Type

/*******************************************************************************************************///Define Macro
#define M0_PORT_CLK             RCC_APB2Periph_GPIOA
#define M0_BASE                 GPIOA
#define M0_Pin                  GPIO_Pin_15

#define M1_PORT_CLK             RCC_APB2Periph_GPIOB
#define M1_BASE                 GPIOB
#define M1_Pin                  GPIO_Pin_3

#define AUX_PORT_CLK            RCC_APB2Periph_GPIOB
#define AUX_BASE                GPIOB
#define AUX_Pin                 GPIO_Pin_4

/*******************************************************************************************************///Extern Symbols

/*******************************************************************************************************///Inline Functions

/*******************************************************************************************************///Extern Functions
extern void Init_433(uint8_t Num, uint32_t Baud, uint8_t Config, uint8_t Len);

#endif
