/*
* @Filename:           API_ANO_TC.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-02 09:53:34
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-02 16:47:43
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-04-02 12:01:14                           创建文件 //
///////////////////////////////////////////////////////////

#include <API_ANO_TC.h>

/*******************************************************************************************************///Including Header Files
#include <string.h>
/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols
static union
{
    unsigned char BUFF[BUFF_LEN];
    struct
    {
        unsigned short Head;
        unsigned char Cmd;
        unsigned char Len;
        unsigned char Dat[DAT_LEN];
        unsigned char CheckSum;
    }content;
}AT_B;
/*******************************************************************************************************///Function Subject
/**
 * 重置匿名协议的数据包
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-02
 *
 * @param   Cmd        数据包类型字节重置为Cmd
 * @param   Len        数据包长度字节重置为Len
 */
void Reset_ANO_Package(unsigned char Cmd, unsigned char Len)
{
    memset(AT_B.content.Dat, 0x00, DAT_LEN);
    AT_B.content.Head = 0xaaaa;
    AT_B.content.Cmd = Cmd;
    AT_B.content.Len = Len;
    AT_B.content.CheckSum = (0x54 + Cmd + Len);
}

/**
 * 装载数据
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-02
 *
 * @param   Dat        要装载的数据
 * @return             装载完毕标志
 */
bool Load_ANO_Package(unsigned char Dat)
{
    static unsigned char i = 0;

    AT_B.content.Dat[i] = Dat;
    AT_B.content.CheckSum += Dat;

    if (++i == DAT_LEN)
    {
        i = 0;
        return true;
    }

    return false;
}

/**
 * 发送匿名协议的数据包
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-02
 *
 * @return             发送结束标志位
 */
bool Send_ANO_Package(void)
{
    static unsigned char i = 0;

    Send_ANO_BUFF(AT_B.BUFF[i]);

    i++;
    if (i == (4 + AT_B.content.Len))
    {
        i = BUFF_LEN - 1;
    }
    else if (i == BUFF_LEN)
    {
        i = 0;
        return true;
    }

    return false;
}
