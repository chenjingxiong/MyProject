//////////////////////////////////////////////////////////////////////
//文件名：FU68xx_UART.c                                             //
//说明：FU68系列芯片的UART底层驱动                                  //
//Log                                                               //
//Timer         Writer      Thing                               Ver //
//2016-08-01    Any         创建文件                            V1.0//
//2016-08-01    Any         在资源满足条件下尽可以使用printf    V1.1//
//2016-09-09    Any         修改端口复用的赋值方式              V1.2//
//2016-09-23    Any         还原变量类型名，更新注释形式        V1.3//
//2016-12-14    Any         初始化无需计算寄存器值直接填波特率  V1.4//
//2016-12-22    Any         升级串口初始化流程                  V1.5//
//2016-12-22    Any         更新注释                            V1.6//
//2017-04-02    Any         删除字节发送函数，由putchar支持     V。7//
//////////////////////////////////////////////////////////////////////

#include <FU68xx_UART.h>
#include <FU68xx_GPIO.h>
#include <FU68xx_Config.h>

/**
 * 配置串口
 *
 * @Writer  Any
 * @Version V1.2
 * @Date    2016-12-22
 *
 * @param   addr       串口号1: P06--Rx  P05--Tx    0: P33--Rx  P34--Tx
 * @param   Config     串口配置
 * @param   bund       波特率
 * @param   irq        中断开关
 */
void Init_UART(unsigned char addr, unsigned char Config, unsigned long bund, bool irq)
{
    UTCR  = Config;
    UTBU = FREC16 / bund - 1;
    TI = 1;

    ES = irq;

    PHSEL |= (0x20 << addr);
}

/**
 * 发送字符串
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-08-01
 *
 * @param   str        字符串所在地址
 * @param   Size       字符串长度
 */
void Send_UART(unsigned char* str, unsigned char Size)
{
    unsigned char i = 0;

    while (i < Size)
    {
        while (!TI);
        UTDR = *str;
        i++;
        str++;
        TI = 0;
    }
}
