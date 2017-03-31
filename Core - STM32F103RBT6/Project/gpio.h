#ifndef "gpio.h"
#define "gpio.h"

#include "stm32f10x.h"

typedef enum
{ 
    IN = 0,
    OUT
}GPIORead_Def;

typedef enum
{ 
    RESET = 0,
    SET
}GPIOBitStatu_Def;

typedef enum
{ 
    FALL = 0,
    SUCCESS
}GPIOInitStatu_Def;

typedef enum
{ 
    INPUT = 0,
    OUTPUT_10MHz,
    OUTPUT_2MHz,
    OUTPUT_50MHz,
}GPIOMode_Def;

typedef enum
{ 
    AIN = 0,
    FLOAT,
    IPU,
    IPD,
    PP,
    OD,
    AFPP,
    AFOD,
}GPIOConf_Def;

#define GPIO_Pin_0                 ((uint16_t)0x0001)  /*!< Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /*!< Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /*!< Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /*!< Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /*!< Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /*!< Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /*!< Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /*!< Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */


extern GPIOInitStatu_Def init_GPIO( GPIO_TypeDef* gpiox, GPIOConf_Def conf, GPIOMode_Def mode, uint16_t pin );
extern uint16_t read_GPIO( GPIO_TypeDef* gpiox, uint16_t pin, GPIORead_Def inout );
extern void write_GPIO( GPIO_TypeDef* gpiox, uint16_t pin, GPIOBitStatu_Def bit );

#endif
