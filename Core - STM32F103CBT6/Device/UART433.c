#include <UART433.h>

void init_433(uint8_t num, uint32_t baud, uint8_t bit, uint8_t stop, uint8_t par)
{
    GPIO_InitTypeDef GPIOBASE;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIOBASE.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIOBASE.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIOBASE.GPIO_Pin   = M0 | M1; 
    GPIO_Init(GPIOA, &GPIOBASE);
    
    GPIOBASE.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
    GPIOBASE.GPIO_Pin   = AUX; 
    GPIO_Init(GPIOB, &GPIOBASE);

    init_uart();
    
    GPIO_WriteBit(GPIOA, M0, Bit_SET);
    GPIO_WriteBit(GPIOA, M1, Bit_SET);
    while (!GPIO_ReadInputDataBit(GPIOB, AUX));
    GPIO_WriteBit(GPIOA, M0, Bit_RESET);
    GPIO_WriteBit(GPIOA, M1, Bit_RESET);
    while (!GPIO_ReadInputDataBit(GPIOB, AUX));
    
    delay_sys(100, ms);
    
    USART_ClearFlag(USART1, USART_FLAG_TC);
}
