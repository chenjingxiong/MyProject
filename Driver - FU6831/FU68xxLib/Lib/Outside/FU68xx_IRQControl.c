//文件名：FU68xx_IRQControl.c
//说明：FU68xx中断控制
//Log
//Timer         Writer      Thing                                 Ver
//2016-09-22    Any         创建文件                              V1.0

#include <FU68xx_IRQControl.h>

/**
 * [Switch_IRQ description]
 *
 * @function  总中断控制
 * @date      2016-09-22
 * @Version   V1.0
 *
 * @requires
 *
 * @reference
 *
 * @param     sw         [总中断开关]
 */
void Switch_IRQ(bool sw)
{
	EA = sw;
}

/**
 * [Seting_IRQL description]
 *
 * @function  中断优先级设置
 * @date      2016-09-22
 * @Version   V1.0
 *
 * @requires
 *
 * @reference
 *
 * @param     IRQSource    [中断源编号]
 * @param     IRQLPriority [中断优先级]
 */
void Setting_IRQL(unsigned char IRQSource, unsigned char IRQPriority)
{
	switch (IRQSource)
	{
	case IRQ_FOC:   IRQFOC_H   = IRQPriority / 2; IRQFOC_L   = IRQPriority % 2; break;
	case IRQ_INT1:  IRQINT1_H  = IRQPriority / 2; IRQINT1_L  = IRQPriority % 2; break;
	case IRQ_INT0:  IRQINT0_H  = IRQPriority / 2; IRQINT0_L  = IRQPriority % 2; break;
	case IRQ_LVW:   IRQLVW_H   = IRQPriority / 2; IRQLVW_L   = IRQPriority % 2; break;
	case IRQ_CMP:   IRQCMP_H   = IRQPriority / 2; IRQCMP_L   = IRQPriority % 2; break;
	case IRQ_ADC:   IRQADC_H   = IRQPriority / 2; IRQADC_L   = IRQPriority % 2; break;
	case IRQ_TIM1:  IRQTIM1_H  = IRQPriority / 2; IRQTIM1_L  = IRQPriority % 2; break;
	case IRQ_TIM0:  IRQTIM0_H  = IRQPriority / 2; IRQTIM0_L  = IRQPriority % 2; break;
	case IRQ_TSD:   IRQTSD_H   = IRQPriority / 2; IRQTSD_L   = IRQPriority % 2; break;
	case IRQ_TIM45: IRQTIM45_H = IRQPriority / 2; IRQTIM45_L = IRQPriority % 2; break;
	case IRQ_TIM23: IRQTIM23_H = IRQPriority / 2; IRQTIM23_L = IRQPriority % 2; break;
	case IRQ_RTC:   IRQRTC_H   = IRQPriority / 2; IRQRTC_L   = IRQPriority % 2; break;
	case IRQ_MCD:   IRQMCD_H   = IRQPriority / 2; IRQMCD_L   = IRQPriority % 2; break;
	case IRQ_SPI:   IRQSPI_H   = IRQPriority / 2; IRQSPI_L   = IRQPriority % 2; break;
	case IRQ_I2C:   IRQI2C_H   = IRQPriority / 2; IRQI2C_L   = IRQPriority % 2; break;
	case IRQ_UART:  IRQUART_H  = IRQPriority / 2; IRQUART_L  = IRQPriority % 2; break;
	}
}
