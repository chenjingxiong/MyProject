//�ļ�����FU68xx_CTimer2.c
//˵����FU68ϵ��оƬ��ͨ�ö�ʱ���ײ�����
//Log
//Timer 		Writer      Thing                                             Ver
//2016-07-31	Any			�����ļ�                                          V1.0
//2016-07-31	Any			��ÿ����ʱ������д��һ���ļ�                      V1.1
//2016-08-01    Any         ʹ�ú궨���ֶ�ʱ��                              V1.2
//2016-09-09    Any         ���Ӷ�����ģʽIO�ڵĸ��ô����޸�ע�͸�ʽ        V1.3
//2016-09-22    Any         ����ʱ�������ϲ�                                  V2.0
//2016-09-23    Any         ��ԭ�����������ƣ�ȥ��Type.h                      V2.1

#include <FU68xx_CTimer.h>
#include <FU68xx_GPIO.h>

unsigned char code phsel[4] = {0x04, 0x08, 0x10, 0x02};
/**
 * [Init_CTimer description]
 *
 * @function  ��ʼ����ͨ��ʱ��
 * @date      2016-09-22
 * @Version   V1.0
 *
 * @param     num        [��ʱ����]
 * @param     cr0        [CR0��ֵ]
 * @param     cr1        [CR1��ֵ]
 * @param     arr        [ARR��ֵ]
 * @param     dr         [DR��ֵ]
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
 * @function  ���ض�ʱ��
 * @date      2016-09-22
 * @Version   V1.0
 *
 * @param     num        [��ʱ����]
 * @param     sw         [����ָ��]
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
 * @function  ��ʱ���жϱ��
 * @date      2016-09-22
 * @Version   V1.0
 *
 * @requires
 *
 * @reference
 *
 * @param     num        [��ʱ����]
 * @return     0         [���ж�]
 * @return     1         [����ж�]
 * @return     2         [�����ж�]
 * @return     4         [ƥ���ж�]
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
