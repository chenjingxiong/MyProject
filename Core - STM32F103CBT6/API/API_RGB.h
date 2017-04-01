#ifndef __API_RGB_H__
#define __API_RGB_H__

/*******************************************************************************************************///Including Header Files
#include <stm32f4xx.h>

/*******************************************************************************************************///Define Struct/Union Type
/*******************************************************************************************************///Define Macro
/**********************************************///Define Hardware 
#define RGB_PORT_CLK   RCC_AHB1Periph_GPIOH
#define RGB_BASE       GPIOH
#define RED            GPIO_Pin_10
#define GREEN          GPIO_Pin_11
#define BLUE           GPIO_Pin_12

#define SYS_PORT_CLK   RCC_AHB1Periph_GPIOD
#define SYS_BASE       GPIOD
#define SYS_LED        GPIO_Pin_12

/**********************************************///Define Software 
#define BLACK 0x00
#define ORG   (RED | GREEN       )
#define PUR   (RED |         BLUE)
#define YEL   (      GREEN | BLUE)
#define WHI   (RED | GREEN | BLUE)

/*******************************************************************************************************///Extern Symbols

/*******************************************************************************************************///Inline Functions
__inline void Shine_RGB(uint32_t color)
{
    RGB_BASE->ODR ^= color;
}

__inline void Shine_SYSLED(void)
{
    SYS_BASE->ODR ^= SYS_LED;
}

/*******************************************************************************************************///Extern Functions
extern void Init_RGB(void);
extern void Control_RGB(uint16_t color);
extern void Init_SYSLED(void);

#endif
