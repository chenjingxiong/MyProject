//文件名：FU68xx_CTimer2.c
//说明：FU68系列芯片的通用定时器底层驱动
//Log
//Timer 		Writer      Thing                                             Ver
//2016-07-31	Any			创建文件                                          V1.0
//2016-07-31	Any			将每个定时器单独写成一个文件                      V1.1
//2016-08-01    Any         使用宏定义拆分定时器                              V1.2
//2016-09-09    Any         增加对输入模式IO口的复用处理，修改注释格式        V1.3
//2016-09-22    Any         将定时器操作合并                                  V2.0
//2016-09-23    Any         还原变量类型名称，去掉Type.h                      V2.1

#include <FU68xx_CTimer.h>
#include <FU68xx_GPIO.h>

unsigned char code phsel[4] = {0x04, 0x08, 0x10, 0x02};
/**
 * [Init_CTimer description]
 *
 * @function  初始化普通定时器
 * @date      2016-09-22
 * @Version   V1.0
 *
 * @param     num        [定时器号]
 * @param     cr0        [CR0的值]
 * @param     cr1        [CR1的值]
 * @param     arr        [ARR的值]
 * @param     dr         [DR的值]
 */
void Init_CTimer(unsigned char num, unsigned char cr0, unsigned char cr1, unsigned short arr, unsigned short dr)
{
    switch (num)
    {
        case 2: TIM2CR0 = cr0; TIM2CR1 = cr1; TIM2ARR = arr; TIM2DR = dr; break;
        case 3: TIM3CR0 = cr0; TIM3CR1 = cr1; TIM3ARR = arr; TIM3DR = dr; break;
        case 4: TIM4CR0 = cr0; TIM4CR1 = cr1; TIM4ARR = arr; TIM4DR = dr; break;
        case 5: TIM5CR0 = cr0; TIM5CR1 = cr1; TIM5ARR = arr; TIM5DR = dr; break;

    }
    
    if ((cr0 & 0x01) == 0x01) PHSEL &= ~phsel[num - 2];
    else                      PHSEL |=  phsel[num - 2];
}

/**
 * [switch_CTimer description]
 *
 * @function  开关定时器
 * @date      2016-09-22
 * @Version   V1.0
 *
 * @param     num        [定时器号]
 * @param     sw         [开关指令]
 */
void switch_CTimer(unsigned char num, bool sw)
{
    switch (num)
    {
        case 2: 
            if (sw) TIM2CR1 |= TIMXCEN;
            else    TIM2CR1 &= ~TIMXCEN;
        break;
        
        case 3: 
            if (sw) TIM3CR1 |= TIMXCEN;
            else    TIM3CR1 &= ~TIMXCEN;
        break;
        
        case 4: 
            if (sw) TIM4CR1 |= TIMXCEN;
            else    TIM4CR1 &= ~TIMXCEN;
        break;
        
        case 5: 
            if (sw) TIM5CR1 |= TIMXCEN;
            else    TIM5CR1 &= ~TIMXCEN;
        break;        
    }
}

/**
 * [irq_CTimer description]
 *
 * @function  定时器中断编号
 * @date      2016-09-22
 * @Version   V1.0
 *
 * @requires
 *
 * @reference
 *
 * @param     num        [定时器号]
 * @return     0         [无中断]
 * @return     1         [溢出中断]
 * @return     2         [输入中断]
 * @return     4         [匹配中断]
 */
char irq_CTimer(unsigned char num)
{
    char value = 0;
        
    switch (num)
    {
        case 2: 
            if ((TIM2CR1 & TIMXIF) == TIMXIF) value += 1;
            if ((TIM2CR1 & TIMXIP) == TIMXIP) value += 2;
            if ((TIM2CR1 & TIMXIR) == TIMXIR) value += 4;
            TIM2CR1 &= ~0xe0;
        break;
        case 3: 
            if ((TIM3CR1 & TIMXIF) == TIMXIF) value += 1;
            if ((TIM3CR1 & TIMXIP) == TIMXIP) value += 2;
            if ((TIM3CR1 & TIMXIR) == TIMXIR) value += 4;
            TIM3CR1 &= ~0xe0;
        break;
        case 4: 
            if ((TIM4CR1 & TIMXIF) == TIMXIF) value += 1;
            if ((TIM4CR1 & TIMXIP) == TIMXIP) value += 2;
            if ((TIM4CR1 & TIMXIR) == TIMXIR) value += 4;
            TIM4CR1 &= ~0xe0;
        break;
        case 5: 
            if ((TIM5CR1 & TIMXIF) == TIMXIF) value += 1;
            if ((TIM5CR1 & TIMXIP) == TIMXIP) value += 2;
            if ((TIM5CR1 & TIMXIR) == TIMXIR) value += 4;
            TIM5CR1 &= ~0xe0;
        break;
    }
    
    return value;
}
