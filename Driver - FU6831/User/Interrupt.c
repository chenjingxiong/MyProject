/*
* @Filename:           Interrupt.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-01 23:07:31
*
* @Last Modified by:   Any
* @Last Modified time: 2017-04-07 13:39:23
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
///////////////////////////////////////////////////////////

#include <Interrupt.h>

/*******************************************************************************************************///Including Header Files
#include <stdbool.h>
#include <FU68xx_MCU.h>
#include <FU68xx_Type.h>
#include <API_Conf.h>

/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols
bool time500ms;
bool time10ms;
bool time2ms;
/*******************************************************************************************************///Function Subject
#if defined(EN_IRQ_CTIMER23)
    /**
     * 定时器2/3中断处理函数
     *
     * @Writer  Any
     * @Version V1.0
     * @Date    2017-04-02
     *
     */
    void Irq_CTimer23(void) interrupt 9
    {
        static uint8_t TimeCount;

        if (FlagCheck_CTimer2(TIM_CR1_Flag_IF))
        {
            TimeCount++;
            time2ms = true;

            if (TimeCount % 5 == 0) time10ms = true;

            if (TimeCount == 250)
            {
                Shine_RGB(G_Pin);
                TimeCount = 0;
                time500ms = true;
            }

            FlagClear_CTimer2(TIM_CR1_Flag_IF);
        }
    }
#endif
