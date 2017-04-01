/*
* @Filename:           API_PWM.c
* @Author:             Min Lin
* @Explain:
* @Date:               2017-02-17 22:13:17
*
* @Last Modified by:   Min Lin
* @Last Modified time: 2017-02-26 16:28:55
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-02-24 21:27:25                       完成代码注释 //
//2017-02-25 23:47:09             增加定时器计数模式设定 //
//2017-02-26 16:28:08               设定定时器预装载使能 //
///////////////////////////////////////////////////////////


#include <API_PWM.h>

/*******************************************************************************************************///Including Header Files
/*******************************************************************************************************///Define Global Symbols
/*******************************************************************************************************///Function Subject
/**
 * PWM输出的GPIO配置
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-02-24
 *
 * @param   GPIOx      GPIO配置信息
 */
static void Init_PWMGPIO(PWM_GPIO_TypeDef* GPIOx)
{
    GPIO_InitTypeDef GPIOBASE;
    uint32_t PinTmp;

    PinTmp = 0x0001 << (GPIOx->PinNum);

    GPIOBASE.GPIO_Mode  = GPIO_Mode_AF;
    GPIOBASE.GPIO_OType = GPIO_OType_PP;
    GPIOBASE.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIOBASE.GPIO_Speed = GPIO_Speed_100MHz;
    GPIOBASE.GPIO_Pin   = PinTmp;

    RCC->AHB1ENR |= 0x00000001 << ((GPIOx->Port & 0xffff) / 0x0400);

    GPIO_Init((GPIO_TypeDef *)(GPIOx->Port), &GPIOBASE);

    GPIO_PinAFConfig((GPIO_TypeDef *)(GPIOx->Port), GPIOx->PinNum, GPIOx->AF);
}

/**
 * PWM的定时器配置
 *
 * @Writer  Any
 * @Version V1.2
 * @Date    2017-02-24
 *
 * @param   TIMx       定时器配置信息
 */
static void Init_PWMTIM(PWM_TIM_TypeDef* TIMx)
{
    TIM_TimeBaseInitTypeDef TIMBASE;
    TIM_OCInitTypeDef TIMOCBASE;

    TIMBASE.TIM_Period        = TIMx->Period    - 1;
    TIMBASE.TIM_Prescaler     = TIMx->Prescaler - 1;
    TIMBASE.TIM_ClockDivision = TIM_CKD_DIV1;
    TIMBASE.TIM_CounterMode   = TIMx->Mode;

    TIMOCBASE.TIM_OCMode      = TIM_OCMode_PWM1;
    TIMOCBASE.TIM_OutputState = TIM_OutputState_Enable;
    TIMOCBASE.TIM_Pulse       = TIMx->Pulse - 1;
    TIMOCBASE.TIM_OCPolarity  = TIM_OCPolarity_High;

    if (TIMx->Timer < TIM9_BASE) RCC->APB1ENR |= 0x00000001 << ((TIMx->Timer & 0xffff) / 0x0400);
    else                         RCC->APB2ENR |= 0x00000001 << ((TIMx->Timer & 0xffff) / 0x0400);

    TIM_TimeBaseInit((TIM_TypeDef *)(TIMx->Timer), &TIMBASE);

    switch (TIMx->Channel)
    {
        case 1:
                TIM_OC1Init((TIM_TypeDef *)(TIMx->Timer), &TIMOCBASE);
                TIM_OC1PreloadConfig((TIM_TypeDef *)(TIMx->Timer), TIM_OCPreload_Enable);
        break;
        case 2:
                TIM_OC2Init((TIM_TypeDef *)(TIMx->Timer), &TIMOCBASE);
                TIM_OC2PreloadConfig((TIM_TypeDef *)(TIMx->Timer), TIM_OCPreload_Enable);
        break;
        case 3:
                TIM_OC3Init((TIM_TypeDef *)(TIMx->Timer), &TIMOCBASE);
                TIM_OC3PreloadConfig((TIM_TypeDef *)(TIMx->Timer), TIM_OCPreload_Enable);
        break;
        case 4:
                TIM_OC4Init((TIM_TypeDef *)(TIMx->Timer), &TIMOCBASE);
                TIM_OC4PreloadConfig((TIM_TypeDef *)(TIMx->Timer), TIM_OCPreload_Enable);
        break;
    }

    ((TIM_TypeDef *)(TIMx->Timer))->CR1 |= (TIM_CR1_CEN | TIM_CR1_ARPE);
}

/**
 * 初始化PWM
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-02-24
 *
 * @param   PWMx       PWM通道配置信息
 */
void Init_PWM(PWM_TypeDef* PWMx)
{
    Init_PWMGPIO(&(PWMx->GPIOx));
    Init_PWMTIM(&(PWMx->TIMx));
}

