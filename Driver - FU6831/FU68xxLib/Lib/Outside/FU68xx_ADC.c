////////////////////////////////////////////////////////////////////////////////////
//文件名：FU68xx_ADC.c                                                            //
//说明：FU68系列芯片的ADC底层驱动                                                 //
//Log                                                                             //
//Timer         Writer      Thing                                             Ver //
//2016-11-21    Any         创建文件                                          V1.0//
//2016-12-02    Any         增加ADC触发函数                                   V1.1//
////////////////////////////////////////////////////////////////////////////////////

#include <FU68xx_ADC.h>

/**
 * 软件触发ADC采样
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-12-02
 *
 */
void Trigger_ADC(void)
{
    ADCSTA |= 0x40;
    while ((ADCSTA & 0x40) == 0x40);
}
