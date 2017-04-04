/*
* @Filename:           FU68xx_ADC.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-01 15:25:38
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-04 11:10:49
*/

///////////////////////////////////////////////////////////
//Log                                                    //
//2017-03-08                                    创建文件 //
///////////////////////////////////////////////////////////

#include <FU68xx_ADC.h>
/*******************************************************************************************************///Including Header Files

/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols

/*******************************************************************************************************///Function Subject
/**
 * ADC初始化
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-03
 *
 * @param   Channel    初始化通道
 * @param   Time       采样时间
 */
void Init_ADC(uint8_t Channel, uint8_t Time)
{
    ADC_MASK |= (1 << Channel);
    ADC_SYSC |= (Time << ((Channel >> 2) << 2));
}
