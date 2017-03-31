/*
* @Filename:           API_SYSCLK.c
* @Author:             Min Lin
* @Explain:            
* @Date:               2017-02-17 21:31:54
*
* @Last Modified by:   Min Lin
* @Last Modified time: 2017-02-24 22:46:04
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-02-24 22:34:01                            增加注释//
///////////////////////////////////////////////////////////


#include <API_SYSCLK.h>

/*******************************************************************************************************///Including Header Files
/*******************************************************************************************************///Define Macro
/*******************************************************************************************************///Define Global Symbols
/*******************************************************************************************************///Function Subject
/**
 * 获取系统时钟
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-02-24
 *
 * @return             系统运行时钟
 */
static uint32_t get_sysclk(void)
{
	RCC_ClocksTypeDef CLK;
    
    RCC_GetClocksFreq(&CLK);
    
    return CLK.SYSCLK_Frequency;
}

/**
 * 软件延时的汇编程序
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-02-24
 *
 * @param   count      延时长度
 */
__ASM void delay_sysclk(uint32_t count)
{
    subs  r0, #1;
    bne   delay_sysclk;
    bx    lr;
}

/**
 * 高进度软件延时
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-02-24
 *
 * @param   tim        延时值
 * @param   times      延时倍率
 */
void Delay_SYS(uint32_t tim, uint32_t times)
{
    delay_sysclk(tim * (get_sysclk() / 3 / times));
}

/**
 * 初始化滴答定时器
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-02-24
 *
 * @param   tim        延时值
 * @param   times      延时倍率
 */
void Init_Systick(uint32_t tim, uint32_t times)
{
    if(SysTick_Config(tim *(get_sysclk() / times)))
    {
        while(1);
    }
    
    // SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
