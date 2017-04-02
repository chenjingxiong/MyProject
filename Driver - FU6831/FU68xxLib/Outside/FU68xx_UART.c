//////////////////////////////////////////////////////////////////////
//�ļ�����FU68xx_UART.c                                             //
//˵����FU68ϵ��оƬ��UART�ײ�����                                  //
//Log                                                               //
//Timer         Writer      Thing                               Ver //
//2016-08-01    Any         �����ļ�                            V1.0//
//2016-08-01    Any         ����Դ���������¾�����ʹ��printf    V1.1//
//2016-09-09    Any         �޸Ķ˿ڸ��õĸ�ֵ��ʽ              V1.2//
//2016-09-23    Any         ��ԭ����������������ע����ʽ        V1.3//
//2016-12-14    Any         ��ʼ���������Ĵ���ֱֵ�������  V1.4//
//2016-12-22    Any         �������ڳ�ʼ������                  V1.5//
//2016-12-22    Any         ����ע��                            V1.6//
//2017-04-02    Any         ɾ���ֽڷ��ͺ�������putchar֧��     V��7//
//////////////////////////////////////////////////////////////////////

#include <FU68xx_UART.h>
#include <FU68xx_GPIO.h>
#include <FU68xx_Config.h>

/**
 * ���ô���
 *
 * @Writer  Any
 * @Version V1.2
 * @Date    2016-12-22
 *
 * @param   addr       ���ں�1: P06--Rx  P05--Tx    0: P33--Rx  P34--Tx
 * @param   Config     ��������
 * @param   bund       ������
 * @param   irq        �жϿ���
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
 * �����ַ���
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-08-01
 *
 * @param   str        �ַ������ڵ�ַ
 * @param   Size       �ַ�������
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
