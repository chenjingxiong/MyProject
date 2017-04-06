#ifndef __API_RGB_H__
#define __API_RGB_H__

/*******************************************************************************************************///Including Header Files
#include <stm32f10x.h>

/*******************************************************************************************************///Define Struct/Union Type
/*******************************************************************************************************///Define Macro
/**********************************************///Define Hardware
#define RGB_PORT_CLK   RCC_APB2Periph_GPIOB
#define RGB_BASE       GPIOB
#define RED            GPIO_Pin_12
#define GREEN          GPIO_Pin_11
#define BLUE           GPIO_Pin_13

#define SYS_PORT_CLK   RCC_APB2Periph_GPIOB
#define SYS_BASE       GPIOB
#define SYS_LED        GREEN

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
