
//文件名：FU68xx_FOC.c
//说明：FOC控制程序
//Log
//Timer         Writer      Thing                                 Ver
//2016-12-02    Any         创建文件                              V1.0

#include <FU68xx_FOC.h>
#include <FU68xx_GPIO.h>
#include <FU68xx_ADC.h>
#include <FU68xx_TIMER0.h>
// #include <FU68xx_AMP.h>
#include <FU68xx_VREF.h>
#include <FU68xx_Config.h>
#include <API_Delay.h>


/**
 * 读取Ia、Ib的偏置电压并写入寄存器
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-12-02
 *
 */
void Calibrate_FOC(void)
{
    long Buff[2] = { 0 };
    short offset[2];
    unsigned char i;

    Init_ADC(0, 3);
    Init_ADC(1, 3);

    for (i=0; i!=128; i++)
    {
        Trigger_ADC;
        while (FlagCheck_ADC(ADC_IF));
        FlagClean_ADC(ADC_IF);

        Buff[0] += ADC_DR0;
        Buff[1] += ADC_DR1;
    }

    offset[0] = Buff[0] >> 4;
    offset[1] = Buff[1] >> 4;

    FOC_CHC = 0x62;
    FOC_CSO = offset[0];

    FOC_CHC = 0xa2;
    FOC_CSO = offset[1];
}

/**
 * 初始化FOC模块
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-12-02
 *
 */
void Init_FOC(void)
{
    //IO->AN
    // P2AN       = 0x0f;
    // P3AN       = 0x03;
    // P1AN       = 0xc0;

    // //ADC
    // EN_ADC;

    // //AMP
    // AMPCR      = 0x07;

    // //VHALF
    // VREFCR     = 0x01;

    // //TIM0  Dead Time
    TIM0DTR    = 24;                                            // Deadtime = 0x18/24MHZ = 1us

    //FOC
    FOCSET0    = 0x80;                                                                   // enable FOC module

    // Calibrate_FOC();

    FOC_CR1    = FOC_CR1_ANG_MANU |
                 FOC_CR1_FCE      |
                 FOC_CR1_PWM_FOC  |
                 FOC_CR1_START;//0x2d;
                                                                               // clear FOC_CR1
    FOC_CR2    = 0x00;//0x80;                                                                            // clear FOC_CR2
    FOC_THECOR = 0;
    FOC_TSMIN  = 0;// Theta error compensate
    FOC_TRGDLY = 0;
    FOC_ARR    = PWM_FREC;                                           // set 16Khz carry frequency
    FOC_CMR    = 0x3f;

    FOC_DMAX   = 0;
    FOC_DMIN   = 0;
    FOC_DKP    = 0;
    FOC_DKI    = 0;
    FOC_IDREF  = 0;

    FOC_QMAX   = 16384;
    FOC_QMIN   = -16384;
    FOC_QKP    = 4096;
    FOC_QKI    = 40;
    FOC_IQREF  = 0;

    FOC_THETA  = 0;

    //Driver
    DRVOUT     = 0x80;
    #ifdef FU6831
        DRVCTL     = 0x02;
        ms_Delay(5);
    #endif
    DRVCTL     |= 0x0d;
}

