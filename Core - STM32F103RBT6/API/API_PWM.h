#ifndef __API_PWM_H__
#define __API_PWM_H__

/*******************************************************************************************************///Including Header Files
#include <stm32f4xx.h>

/*******************************************************************************************************///Define Struct/Union Type
typedef struct
{
    uint32_t Port;
    uint32_t PinNum;
    uint32_t AF;
}PWM_GPIO_TypeDef;

typedef struct
{
    uint32_t Timer;
    uint32_t Channel;
    uint32_t Mode;

    uint32_t Period;
    uint32_t Prescaler;
    uint32_t Pulse;
}PWM_TIM_TypeDef;

typedef struct
{
    PWM_GPIO_TypeDef GPIOx;

    PWM_TIM_TypeDef TIMx;
}PWM_TypeDef;

/*******************************************************************************************************///Define Macro
/*******************************************************************************************************///Extern Symbols
/*******************************************************************************************************///Inline Functions
__inline void Change_PWM(__IO uint32_t* CCRx, uint32_t Value)
{
    *CCRx = Value;
}
/*******************************************************************************************************///Extern Functions
extern void Init_PWM(PWM_TypeDef* PWMx);

#endif
