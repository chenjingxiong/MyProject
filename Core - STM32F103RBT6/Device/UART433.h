#ifndef __UART433_H__
#define __UART433_H__

#include <stm32f10x.h>
#include <SYSCLK.h>
#include <UART.h>

#define M0 GPIO_Pin_12
#define M1 GPIO_Pin_15
#define AUX GPIO_Pin_3

extern void init_433(uint8_t num, uint32_t baud, uint8_t bit, uint8_t stop, uint8_t par);

#endif
