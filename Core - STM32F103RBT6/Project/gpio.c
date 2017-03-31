#include "gpio.h"
/*外设管脚GPIO配置表*/
/*TIM*/
/*捕获输入----浮空*/
/*比较输出----复用推挽*/
/*互补输出----复用推挽*/
/*刹车输入----浮空*/
/*时钟输入----浮空*/
/*UART*/
/*TX----复用推挽*/
/*RX----浮空/上拉（半双工模式下只作为通用IO）*/
/*CK----复用推挽*/
/*RTS----复用推挽*/
/*CTS----浮空/上拉*/
/*I2C*/
/*SCL----复用开漏*/
/*SDA----复用开漏*/
/*CAN*/
/*TX----复用推挽*/
/*RX----浮空/上拉*/
/*SDIO*/
/*CK----复用推挽*/
/*CMD----复用推挽*/
/*DATA----复用推挽*/
/*ADC/DAC*/
/*A----模拟输入*/
/*EXTI*/
/*GPIO----浮空/上拉/下拉*/

GPIOInitStatu_Def init_GPIO( GPIO_TypeDef* gpiox, GPIOConf_Def conf, GPIOMode_Def mode, uint16_t pin )
{
    uint16_t pintmp = 1;
    uint32_t conftmp;
    GPIOInitStatu_Def statu = FALL;
    
    //如果mode与conf设定匹配,则进行初始化
    if ( mode == IN && conf < ( GPIOConf_Def )4 || mode != IN && conf > ( GPIOConf_Def )3 )
    {        
        //打开时钟(0x40010800~0x40012000)
        RCC -> APB2ENR |= 1 << ( ( ( uint32_t )gpiox & 0x0000ffff ) >> 10 );
        
        //当设置为非浮空输入模式时对GPIO输入做上下拉处理
        if ( conf == IPU ) gpiox -> BSRR = pin;
        if ( conf == IPD ) gpiox -> BRR  = pin;
        
        //判断输入输出以适应conf的值
        if ( mode > 0 ) conf -= PP;                                     
        conftmp = ( ( uint32_t )( conf - PP ) << 2 ) | ( uint32_t )mode;
        
        //将初始化投入到预定的IO口上
        for ( i=0; i!=16; i++)
        {
            if ( i < 8 ) if ( pin & pintmp ) gpiox -> CRL |= conftmp << ( i * 4 ); 
            else         if ( pin & pintmp ) gpiox -> CRH |= conftmp << ( ( i * 4 ) - 32 );
            pintmp <<= 1;
        }
        
        //GPIO初始化成功
        statu = SUCCESS;
    }
    
    //如果mode与conf设定不匹配,则statu不会改变,返回FALL
    return statu;
}

uint16_t read_GPIO( GPIO_TypeDef* gpiox, uint16_t pin, GPIORead_Def inout )
{
    if ( inout == OUT ) return ( gpiox -> ODR & pin );
    return ( gpiox -> IDR & pin );
}

void write_GPIO( GPIO_TypeDef* gpiox, uint16_t pin, GPIOBitStatu_Def bit )
{
    if ( bit == SET ) gpiox -> BSRR = pin;
    else              gpiox -> BRR  = pin;
}
