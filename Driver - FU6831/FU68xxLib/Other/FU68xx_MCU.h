#ifndef __FU68XX_MCU_H__
#define __FU68XX_MCU_H__

#include <FU68xx_SFR.h>
#include <FU68xx_Config.h>
//FU68xxLib
#include <FU68xx_GPIO.h>
#include <FU68xx_IRQControl.h>

#if defined(USE_UART)
#include <FU68xx_UART.h>
#endif
#if defined(USE_SPI)
#include <FU68xx_SPI.h>
#endif

#if defined(USE_CTIMER)
#include <FU68xx_CTimer.h>
#endif

#if defined(USE_TIMER1)
#include <FU68xx_Timer1.h>
#endif

#if defined(USE_DMA)
#include <FU68xx_DMA.h>
#endif

#if defined(USE_I2C)
#include <FU68xx_I2C.h>
#endif

#if defined(USE_FOC)
#define USE_DRV
#include <FU68xx_FOC.h>
#endif

#if defined(USE_DRV)
#include <FU68xx_DRV.h>
#endif

#if defined(USE_LPF)
#define USE_PI
#include <FU68xx_LPF.h>
#endif

#if defined(USE_PI)
#include <FU68xx_PI.h>
#endif

#if defined(USE_MDU)
#include <FU68xx_MDU.h>
#endif

#if defined(USE_ADC)
#include <FU68xx_ADC.h>
#endif

#if defined(USE_CMP)
#include <FU68xx_CMP.h>
#endif

#endif