#ifndef __FU68XX_FOC_H__
#define __FU68XX_FOC_H__

//FOC
sfr FOCSET0 = 0xe8;

#define FOC_DTR                 XBYTE[0x4064]

#define FOC_CR1                 XBYTE[0x4090]
#define FOC_CR2                 XBYTE[0x4091]
#define FOC_CR3                 XBYTE[0x4092]
#define FOC_IER                 XBYTE[0x4093]
#define FOC_SR                  XBYTE[0x4094]
#define FOC_CHC                 XBYTE[0x4095]
#define PI_RAN                  XBYTE[0x4096]
#define FOC_CMR                 XBYTE[0x4097]
#define FOC_RTHECNT             XBYTE[0x408e]
#define FOC_FDS                 XBYTE[0x408f]

#define FOC_EFREQACC            *(volatile unsigned int xdata *)0x4088
#define FOC_EFREQMIN            *(volatile unsigned int xdata *)0x408a
#define FOC_EFREQHOLD           *(volatile unsigned int xdata *)0x408c
#define FOC_DKP                 *(volatile unsigned int xdata *)0x4098
#define FOC_DKI                 *(volatile unsigned int xdata *)0x409a
#define FOC_DMAX                *(volatile unsigned int xdata *)0x409c
#define FOC_DMIN                *(volatile unsigned int xdata *)0x409e
#define FOC_QKP                 *(volatile unsigned int xdata *)0x40a0
#define FOC_QKI                 *(volatile unsigned int xdata *)0x40a2
#define FOC_QMAX                *(volatile unsigned int xdata *)0x40a4
#define FOC_QMIN                *(volatile unsigned int xdata *)0x40a6
#define FOC_UD                  *(volatile unsigned int xdata *)0x40a8
#define FOC_UQ                  *(volatile unsigned int xdata *)0x40aa
#define FOC_IDREF               *(volatile unsigned int xdata *)0x40ac
#define FOC_IQREF               *(volatile unsigned int xdata *)0x40ae
#define FOC_ARR                 *(volatile unsigned int xdata *)0x40b0
#define FOC_SWDUTY              *(volatile unsigned int xdata *)0x40b2
#define FOC_TSMIN               *(volatile unsigned int xdata *)0x40b4
#define FOC_TRGDLY              *(volatile unsigned int xdata *)0x40b6
#define FOC_THETA               *(volatile unsigned int xdata *)0x40b8
#define FOC_THECOMP             *(volatile unsigned int xdata *)0x40ba
#define FOC_RTHESTEP            *(volatile unsigned int xdata *)0x40bc
#define FOC_RTHEACC             *(volatile unsigned int xdata *)0x40be
#define FOC_THECOR              *(volatile unsigned int xdata *)0x40c0
#define FOC_ETHETA              *(volatile unsigned int xdata *)0x40c2
#define FOC_KSLIDE              *(volatile unsigned int xdata *)0x40c4
#define FOC_EKLPFMIN            *(volatile unsigned int xdata *)0x40c6
#define FOC_EBMFK               *(volatile unsigned int xdata *)0x40c8
#define FOC_OMEKLPF             *(volatile unsigned int xdata *)0x40ca
#define FOC_FBASE               *(volatile unsigned int xdata *)0x40cc
#define FOC_EOME                *(volatile unsigned int xdata *)0x40ce
#define FOC_EKP                 *(volatile unsigned int xdata *)0x40d0
#define FOC_EKI                 *(volatile unsigned int xdata *)0x40d2
#define FOC_POWKLPF             *(volatile unsigned int xdata *)0x40d4
#define FOC_POW                 *(volatile unsigned int xdata *)0x40d6
#define FOC_EK1                 *(volatile unsigned int xdata *)0x40d8
#define FOC_EK2                 *(volatile unsigned int xdata *)0x40da
#define FOC_EK3                 *(volatile unsigned int xdata *)0x40dc
#define FOC_EK4                 *(volatile unsigned int xdata *)0x40de
#define FOC_IA                  *(volatile unsigned int xdata *)0x40e0
#define FOC_IB                  *(volatile unsigned int xdata *)0x40e2
#define FOC_IBET                *(volatile unsigned int xdata *)0x40e4
#define FOC_COMR                *(volatile unsigned int xdata *)0x40e6
#define FOC_ID                  *(volatile unsigned int xdata *)0x40e8
#define FOC_IQ                  *(volatile unsigned int xdata *)0x40ea
#define FOC_VALP                *(volatile unsigned int xdata *)0x40ec
#define FOC_VBET                *(volatile unsigned int xdata *)0x40ee
#define FOC_UALP                *(volatile unsigned int xdata *)0x40f0
#define FOC_UBET                *(volatile unsigned int xdata *)0x40f2
#define FOC_EALP                *(volatile unsigned int xdata *)0x40f4
#define FOC_EBET                *(volatile unsigned int xdata *)0x40f6
#define FOC_ESQU                *(volatile unsigned int xdata *)0x40f8 
#define FOC_UDCFLT              *(volatile unsigned int xdata *)0x40fa 
#define FOC_CSO                 *(volatile unsigned int xdata *)0x40fc


extern void Init_FOC(void);

#endif