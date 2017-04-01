/*
* @Filename:           API_RGB.c
* @Author:             Min Lin
* @Explain:            
* @Date:               2017-02-17 21:31:54
*
* @Last Modified by:   Min Lin
* @Last Modified time: 2017-02-24 23:12:24
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-02-24 23:05:40                    完成代码注释    //
///////////////////////////////////////////////////////////

#include <API_RGB.h>

/*******************************************************************************************************///Including Header Files
#include <API_SYSCLK.h>

/*******************************************************************************************************///Define Macro
/*******************************************************************************************************///Define Global Symbols
/*******************************************************************************************************///Function Subject
/**
 * [Control_RGB description]
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-02-24
 *
 * @param   color      [description]
 */
void Control_RGB(uint16_t color)
{
    if (color & RED)   RGB_BASE->BSRRH = RED;
    else               RGB_BASE->BSRRL = RED;
    
    if (color & BLUE)  RGB_BASE->BSRRH = BLUE;
    else               RGB_BASE->BSRRL = BLUE;
    
    if (color & GREEN) RGB_BASE->BSRRH = GREEN;
    else               RGB_BASE->BSRRL = GREEN;
}

/**
 * 初始化RGB的GPIO
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-02-24
 *
 */
void Init_RGB(void)
{
	GPIO_InitTypeDef GPIOBASE;
        
    RCC->AHB1ENR |= RGB_PORT_CLK;

    GPIOBASE.GPIO_Mode  = GPIO_Mode_OUT;
    GPIOBASE.GPIO_OType = GPIO_OType_PP;
    GPIOBASE.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIOBASE.GPIO_Speed = GPIO_Speed_2MHz;
    GPIOBASE.GPIO_Pin   = RED | BLUE | GREEN; 
    
    GPIO_Init(RGB_BASE, &GPIOBASE);
    
    Delay_SYS(1, s);//延时1s
    Shine_RGB(WHI);//关掉
}

/**
 * 初始化系统指示灯的GPIO
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-02-24
 *
 */
void Init_SYSLED(void)
{
    GPIO_InitTypeDef GPIOBASE;
        
    RCC->AHB1ENR |= SYS_PORT_CLK;

    GPIOBASE.GPIO_Mode  = GPIO_Mode_OUT;
    GPIOBASE.GPIO_OType = GPIO_OType_PP;
    GPIOBASE.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIOBASE.GPIO_Speed = GPIO_Speed_2MHz;
    GPIOBASE.GPIO_Pin   = SYS_LED; 
    
    GPIO_Init(SYS_BASE, &GPIOBASE);
    
}
