/*
* @Filename:           AS5048.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-03-30 21:53:36
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-01 23:18:20
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-03-30 22:02:51                            创建函数//
///////////////////////////////////////////////////////////

#include <AS5048.h>

/*******************************************************************************************************///Including Header Files

/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols

/*******************************************************************************************************///Function Subject
/**
 * 16位偶校验
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-03-30
 *
 * @param   Dat        校验数据
 * @return             校验结果
 */
static bool Parity16(unsigned short Dat)
{
    unsigned short tmp = Dat;

    tmp ^= (tmp >> 1);
    tmp ^= (tmp >> 2);
    tmp ^= (tmp >> 4);
    tmp ^= (tmp >> 8);

    return (bool)(tmp & 0x0001);
}

/**
 * 写数据到指定地址
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-03-30
 *
 * @param   Addr       写入地址
 * @param   Dat        写入内容
 */
void Write_AS5048(unsigned short Addr, unsigned short Dat)
{
    unsigned short WriteDat;

    WriteDat = Addr;
    WriteDat |= ((unsigned short)Parity16(WriteDat)) << 15;
    RW_AS5048(WriteDat);

    WriteDat = Dat;
    WriteDat |= ((unsigned short)Parity16(WriteDat)) << 15;
    RW_AS5048(WriteDat);
}

/**
 * 读数据到指定地址
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-03-30
 *
 * @param   Addr       读取地址
 * @param   Dat        存放地址
 */
void Read_AS5048(unsigned short Addr, unsigned short* Dat)
{
    unsigned short WriteDat;
    unsigned short ReadDat;

    WriteDat = Addr | 0x4000;
    WriteDat |= ((unsigned short)Parity16(WriteDat)) << 15;
    RW_AS5048(WriteDat);

    ReadDat = RW_AS5048(WriteDat);
    if (Parity16(ReadDat)) *Dat = ReadDat;
}
