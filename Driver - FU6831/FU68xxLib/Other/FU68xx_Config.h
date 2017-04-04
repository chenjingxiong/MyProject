#ifndef __FU68xx_Config_H__
#define __FU68XX_CONFIG_H__

#define FREC     24000000
#define FREC2    (FREC / 2)
#define FREC16   (FREC / 16)

#define SPI_FREC (FREC / 2)
#define PWM_FREC (FREC2/ 25000)

#define FU6831

#define USE_CTIMER
#define USE_SPI
#define USE_UART
// #define USE_DMA
// #define USE_I2C
// #define USE_FOC
// #define USE_PI
// #define USE_LPF
// #define USE_MDU
// #define USE_TIMER1
// #define USE_DRV
// #define USE_ADC
// #define USE_CMP

#define EN_IRQ_CTIMER23
// #define EN_IRQ_CTIMER45
// #define EN_IRQ_SPI
// #define EN_IRQ_UART
// #define EN_IRQ_DMA
// #define EN_IRQ_I2C
// #define EN_IRQ_DRV
// #define EN_IRQ_INT1

#endif
