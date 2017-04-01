////////////////////////////////////////////////////////////////////////////////////
//�ļ�����FU68xx_CTimer2.c                                                        //
//˵����FU68ϵ��оƬ��ͨ�ö�ʱ���ײ�����                                          //
//Log                                                                             //
//Timer 		Writer      Thing                                             Ver //
//2016-07-31	Any			�����ļ�                                          V1.0//
//2016-07-31	Any			��ÿ����ʱ������д��һ���ļ�                      V1.1//
//2016-08-01    Any         ʹ�ú궨���ֶ�ʱ��                              V1.2//
//2016-09-09    Any         ���Ӷ�����ģʽIO�ڵĸ��ô����޸�ע�͸�ʽ        V1.3//
//2016-09-22    Any         ����ʱ�������ϲ�                                  V2.0//
//2016-09-23    Any         ��ԭ�����������ƣ�ȥ��Type.h                      V2.1//
////////////////////////////////////////////////////////////////////////////////////

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
        case 2: TIM2_CR0 = cr0; TIM2_CR1 = cr1; TIM2_ARR = arr; TIM2_DR = dr; break;
        case 3: TIM3_CR0 = cr0; TIM3_CR1 = cr1; TIM3_ARR = arr; TIM3_DR = dr; break;
        case 4: TIM4_CR0 = cr0; TIM4_CR1 = cr1; TIM4_ARR = arr; TIM4_DR = dr; break;
        case 5: TIM5_CR0 = cr0; TIM5_CR1 = cr1; TIM5_ARR = arr; TIM5_DR = dr; break;

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
            if (sw) TIM2_CR1 |= TIM_CR1_EN;
            else    TIM2_CR1 &= ~TIM_CR1_EN;
        break;

        case 3:
            if (sw) TIM3_CR1 |= TIM_CR1_EN;
            else    TIM3_CR1 &= ~TIM_CR1_EN;
        break;

        case 4:
            if (sw) TIM4_CR1 |= TIM_CR1_EN;
            else    TIM4_CR1 &= ~TIM_CR1_EN;
        break;

        case 5:
            if (sw) TIM5_CR1 |= TIM_CR1_EN;
            else    TIM5_CR1 &= ~TIM_CR1_EN;
        break;
    }
}
