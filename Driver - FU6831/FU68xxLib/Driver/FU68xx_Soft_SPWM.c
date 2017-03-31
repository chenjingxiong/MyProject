//文件名：FU68xx_SOFT_SPWM.c
//说明：手动驱动SPWM
//Log
//Timer         Writer      Thing                                 Ver
//2016-10-20    Any         创建文件                              V1.0

#include <FU68xx_Soft_SPWM.h>
#include <FU68xx_SV.h>
#include <FU68xx_Timer0.h>
#include <Delay.h>
#include <FU68xx_GPIO.h>

#define q15 32767.0f

//static unsigned short data i[3] = {0, 10922, 21845};

//void Init_Soft_SPWM(void)
//{
//    SVUS = POWER / 100.0f * 32760;
//    SVARR = PWM_FREC;

//    TIM0SR = 0;

//    TIM0CCMR1 = 0xee;
//    TIM0CCMR2 = 0xee;
//    TIM0CCER1 = 0x55;
//    TIM0CCER2 = 0x15;

//    TIM0DTR = 24;

//    DRVOUT = 0x80;
//#ifdef FU6831
//    DRVCTL = 0x02;
//    ms_Delay(5);
//#endif
//    DRVCTL |= 0x09;

//    TIM0CR = 0x67;
//}
void Init_Soft_SPWM(void)
{
    SVUS = POWER / 100.0f * 32760;
    SVARR = PWM_FREC;
    
    SVCR = 0x06;
    
    TIM0SR = 0;

    TIM0CCMR1 = 0xee;
    TIM0CCMR2 = 0xee;
    TIM0CCER1 = 0x55;
    TIM0CCER2 = 0x15;

    TIM0DTR = 24;
    
    DRVOUT = 0x80;
#ifdef FU6831
    DRVCTL = 0x02;
    ms_Delay(5);
#endif
    DRVCTL |= 0x09;

    TIM0CR = 0x67;
    SVANG = 8184;
    SVCR |= 0x01;
}
//static unsigned short data i[3] = {0, 0, 21845};

//void Updata_Soft_SPWM(short speed)
//{
//    short data output[3];
//    short data sin_thta;
//    char t = 0;

//    if (speed > 400) speed = 400;
//    else if (speed < -400) speed = -400;

//    
//    for (t = 0; t != 3; t++)
//    {
//        i[t] = (i[t] + speed) & 0x7fff;

//        if (i[t] > 0 && i[t] <= 10923) SVANG = i[t];
//        else if (i[t] > 10923 && i[t] <= 21845) SVANG = i[t] - 5461;
//        else if (i[t] > 21845 && i[t] <= 32767) SVANG = 0;

//        SVCR |= 0x01;
//        while ((SVCR & 0x80) == 0x80);
//        sin_thta = SVSIN;

//        output[t] = (short)((600.0f * ((float)sin_thta / q15)) + 50.0f);
//    }

//    TIM0CCR1 = output[0];
//    TIM0CCR2 = output[1];
//    TIM0CCR3 = output[2];
//}

#define MaxStep 1000
#define NeedLimit 1
void Updata_Soft_SPWM(float speed)
{
    static data float i;
    unsigned short j;
    #if (NeedLimit == 1)
    if (speed > MaxStep) speed = MaxStep;
    else if (speed < -MaxStep) speed = -MaxStep;
    #endif
    i += speed;
    j = (unsigned short)i & 0x07fff;
    
    SVANG = i;
    
    SVCR |= 0x01;
}
