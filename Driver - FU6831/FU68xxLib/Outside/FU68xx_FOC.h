#ifndef __FU68xx_FOC_H__
#define __FU68XX_FOC_H__

#include <FU68xx_Type.h>

/*************************************************************************************///Defined Register
 //FOC
 sfr FOCSET0 = 0xe8;

 #define FOC_DTR                 *(__IO uint8_t  xdata *)0x4064

 #define FOC_CR1                 *(__IO uint8_t  xdata *)0x4090
 #define FOC_CR2                 *(__IO uint8_t  xdata *)0x4091
 #define FOC_CR3                 *(__IO uint8_t  xdata *)0x4092
 #define FOC_IER                 *(__IO uint8_t  xdata *)0x4093
 #define FOC_SR                  *(__IO uint8_t  xdata *)0x4094
 #define FOC_CHC                 *(__IO uint8_t  xdata *)0x4095
 #define PI_RAN                  *(__IO uint8_t  xdata *)0x4096
 #define FOC_CMR                 *(__IO uint8_t  xdata *)0x4097
 #define FOC_RTHECNT             *(__IO uint8_t  xdata *)0x408e
 #define FOC_FDS                 *(__IO uint8_t  xdata *)0x408f

 #define FOC_EFREQACC            *(__IO uint16_t xdata *)0x4088
 #define FOC_EFREQMIN            *(__IO uint16_t xdata *)0x408a
 #define FOC_EFREQHOLD           *(__IO uint16_t xdata *)0x408c
 #define FOC_DKP                 *(__IO uint16_t xdata *)0x4098
 #define FOC_DKI                 *(__IO uint16_t xdata *)0x409a
 #define FOC_DMAX                *(__IO uint16_t xdata *)0x409c
 #define FOC_DMIN                *(__IO uint16_t xdata *)0x409e
 #define FOC_QKP                 *(__IO uint16_t xdata *)0x40a0
 #define FOC_QKI                 *(__IO uint16_t xdata *)0x40a2
 #define FOC_QMAX                *(__IO uint16_t xdata *)0x40a4
 #define FOC_QMIN                *(__IO uint16_t xdata *)0x40a6
 #define FOC_UD                  *(__IO uint16_t xdata *)0x40a8
 #define FOC_UQ                  *(__IO uint16_t xdata *)0x40aa
 #define FOC_IDREF               *(__IO uint16_t xdata *)0x40ac
 #define FOC_IQREF               *(__IO uint16_t xdata *)0x40ae
 #define FOC_ARR                 *(__IO uint16_t xdata *)0x40b0
 #define FOC_SWDUTY              *(__IO uint16_t xdata *)0x40b2
 #define FOC_TSMIN               *(__IO uint16_t xdata *)0x40b4
 #define FOC_TRGDLY              *(__IO uint16_t xdata *)0x40b6
 #define FOC_THETA               *(__IO uint16_t xdata *)0x40b8
 #define FOC_THECOMP             *(__IO uint16_t xdata *)0x40ba
 #define FOC_RTHESTEP            *(__IO uint16_t xdata *)0x40bc
 #define FOC_RTHEACC             *(__IO uint16_t xdata *)0x40be
 #define FOC_THECOR              *(__IO uint16_t xdata *)0x40c0
 #define FOC_ETHETA              *(__IO uint16_t xdata *)0x40c2
 #define FOC_KSLIDE              *(__IO uint16_t xdata *)0x40c4
 #define FOC_EKLPFMIN            *(__IO uint16_t xdata *)0x40c6
 #define FOC_EBMFK               *(__IO uint16_t xdata *)0x40c8
 #define FOC_OMEKLPF             *(__IO uint16_t xdata *)0x40ca
 #define FOC_FBASE               *(__IO uint16_t xdata *)0x40cc
 #define FOC_EOME                *(__IO uint16_t xdata *)0x40ce
 #define FOC_EKP                 *(__IO uint16_t xdata *)0x40d0
 #define FOC_EKI                 *(__IO uint16_t xdata *)0x40d2
 #define FOC_POWKLPF             *(__IO uint16_t xdata *)0x40d4
 #define FOC_POW                 *(__IO uint16_t xdata *)0x40d6
 #define FOC_EK1                 *(__IO uint16_t xdata *)0x40d8
 #define FOC_EK2                 *(__IO uint16_t xdata *)0x40da
 #define FOC_EK3                 *(__IO uint16_t xdata *)0x40dc
 #define FOC_EK4                 *(__IO uint16_t xdata *)0x40de
 #define FOC_IA                  *(__IO uint16_t xdata *)0x40e0
 #define FOC_IB                  *(__IO uint16_t xdata *)0x40e2
 #define FOC_IBET                *(__IO uint16_t xdata *)0x40e4
 #define FOC_COMR                *(__IO uint16_t xdata *)0x40e6
 #define FOC_ID                  *(__IO uint16_t xdata *)0x40e8
 #define FOC_IQ                  *(__IO uint16_t xdata *)0x40ea
 #define FOC_VALP                *(__IO uint16_t xdata *)0x40ec
 #define FOC_VBET                *(__IO uint16_t xdata *)0x40ee
 #define FOC_UALP                *(__IO uint16_t xdata *)0x40f0
 #define FOC_UBET                *(__IO uint16_t xdata *)0x40f2
 #define FOC_EALP                *(__IO uint16_t xdata *)0x40f4
 #define FOC_EBET                *(__IO uint16_t xdata *)0x40f6
 #define FOC_ESQU                *(__IO uint16_t xdata *)0x40f8
 #define FOC_UDCFLT              *(__IO uint16_t xdata *)0x40fa
 #define FOC_CSO                 *(__IO uint16_t xdata *)0x40fc
/*************************************************************************************///Defined CMD
 #define FOC_CR1_SMO            0x00
 #define FOC_CR1_PLL            0x80
 #define FOC_CR1_EFAE           0x40
 #define FOC_CR1_RFAE           0x20
 #define FOC_CR1_ANG_MANU       0x00
 #define FOC_CR1_ANG_AUTO       0x10
 #define FOC_CR1_SAM_SING       0x00
 #define FOC_CR1_SAM_DOUB       0x08
 #define FOC_CR1_FCE            0x04
 #define FOC_CR1_PWM_FOC        0x00
 #define FOC_CR1_PWM_SOFT       0x02
 #define FOC_CR1_START          0x01

 #define FOC_CR2_ISDEN          0x80
 #define FOC_CR2_SEG_7          0x00
 #define FOC_CR2_SEG_5          0X20
 #define FOC_CR2_SAM_SEQUE      0x00
 #define FOC_CR2_SAM_ALTER      0x10
 #define FOC_CR2_DBGEN          0x01

 #define FOC_CR3_COM_UP         0x00
 #define FOC_CR3_COM_DOWN       0x04
 #define FOC_CR3_COM_UPDOWN     0x08
 #define FOC_CR3_DFLOW_IRQ_1    0x00
 #define FOC_CR3_DFLOW_IRQ_2    0x01
 #define FOC_CR3_DFLOW_IRQ_3    0x02
 #define FOC_CR3_DFLOW_IRQ_4    0x03

 #define FOC_IE_FC              0x02
 #define FOC_IE_FU              0x01

 #define FOC_FLAG_EUOF          0x80
 #define FOC_FLAG_FCIF          0x02
 #define FOC_FLAG_FUIF          0x01
/*************************************************************************************///External Function


extern void Init_FOC(void);

#endif
