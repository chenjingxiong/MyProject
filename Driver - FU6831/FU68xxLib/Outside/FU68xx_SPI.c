//////////////////////////////////////////////////////////////////////
//文件名：FU68xx_SPI.c                                              //
//说明：FU68xx系列芯片的SPI底层驱动                                 //
//Log                                                               //
//Timer         Writer      Thing                               Ver //
//2016-10-08    Any         创建文件                            V1.0//
//2016-11-03    Any         SPI一些配置使用宏条件                   //
//                          收发函数合并                        V1.1//
//2016-12-19    Any         除去宏定义操作                      V1.2//
//2016-12-22    Any         增加空闲电平初始化                  V1.3//
//2016-12-23    Any         PHSEL修改                           V1.4//
//2017-02-06    Any         增强PHSEL判断                       V1.5//
//2017-02-13    Any         把空闲电平设置归入Line_Mode         V1.6//
//2017-02-21    Any         取消Nss控制函数，改为宏定义         V1.7//
//2017-02-21    Any         取消收发函数的Nss控制权             V1.8//
//2017-02-21    Any         取消SPI忙检测函数，改为宏定义       V1.9//
//2017-02-21    Any         建立SPI所有标志位的检测和部分清除   V2.0//
//2017-04-02    Any         增加收发16位数据的支持              V2.1//
//////////////////////////////////////////////////////////////////////

#include <FU68xx_SPI.h>
#include <FU68xx_GPIO.h>
#include <FU68xx_Config.h>
/**
 * 初始化SPI
 *
 * @Writer  Any
 * @Version V1.6
 * @Date    2016-12-23
 *
 * @param   Line_Mode    SPI线制 L3: 三线制    L4: 四线从机/多主    L4_Signal: 四线单主
 * @param   Config       SPICFG配置
 * @param   SPEED        SPI时钟频率
 * @param   EnIrq        中断使能 true: 使能    false: 禁能
 */
void Init_SPI(char Line_Mode, char Config, unsigned long SPEED, bool EnIrq)
{
    SPI_SCR = SPI_FREC / SPEED - 1;
    if ((PHSEL & 0x60) == 0x40) PHSEL &= 0xbf;

    SPI_CFG = Config;
    SPI_CTL = Line_Mode + 1;
    SPI_IE  = EnIrq;
}

/**
 * SPI单字节收发
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2016-11-03
 *
 * @param   SendDat    发送的数据
 * @return             接收的数据
 */
unsigned char SendReceive_Byte_SPI(unsigned char SendDat)
{
    SPI_DAT = SendDat;
    while (FlagCheck1_SPI(SPI_F_BSY));

    return SPI_DAT;
}

/**
 * SPI双字节收发
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2017-04-02
 *
 * @param   SendDat    发送的数据
 * @return             接收的数据
 */
unsigned short SendReceive_DByte_SPI(unsigned short SendDat)
{
    unsigned short tmp;

    SPI_DAT  = SendDat >> 8;
    while (FlagCheck1_SPI(SPI_F_BSY));
    tmp = (unsigned short)SPI_DAT << 8;

    SPI_DAT  = SendDat;
    while (FlagCheck1_SPI(SPI_F_BSY));
    tmp |= SPI_DAT;

    return tmp;
}

/**
 * 收发一串SPI数据
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2016-11-03
 *
 * @param   SendDat    发送数据流
 * @param   ReceiveDat 接收数据流
 * @param   len        数据流长度
 */
void SendReceive_Bytes_SPI(unsigned char* SendDat, unsigned char* ReceiveDat, unsigned char len)
{
    while (len--)
    {
        SPI_DAT = *SendDat;
        SendDat++;
        while (!((SPI_CTL & 0x02) == 0x02));

        *ReceiveDat = SPI_DAT;
        ReceiveDat++;
    }
}
