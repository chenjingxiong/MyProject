/*
* @Filename:           AS5048.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-03-30 21:53:36
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-02 23:02:23
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-03-30 22:02:51                            创建函数//
//2017-04-02 09:46:06                   增加SPI-CS线控制 //
//2017-04-02 11:00:17           添加共用体处理收发的数据 //
//2017-04-02 16:30:20           通过仿真修复帧错误的问题 //
//2017-04-02 23:01:17   为获取角度增加函数和外联的寄存器 //
///////////////////////////////////////////////////////////

#include <AS5048.h>

/*******************************************************************************************************///Including Header Files

/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols
 unsigned short Angle_AS5048;
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
    unsigned short tmp = Dat & 0x7fff;

    tmp ^= (tmp >> 1);
    tmp ^= (tmp >> 2);
    tmp ^= (tmp >> 4);
    tmp ^= (tmp >> 8);

    return (bool)(tmp & 0x01);
}

/**
 * 写数据到指定地址
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2017-03-30
 *
 * @param   Addr       写入地址
 * @param   Dat        写入内容
 */
void Write_AS5048(unsigned short Addr, unsigned short Dat)
{
    AS5048_Package WriteAddr;
    AS5048_Package WriteDat;

    WriteAddr.content.Value  = Addr;
    WriteAddr.content.Parity = Parity16(WriteAddr.Dat);
    WriteDat.content.Value   = Dat;
    WriteDat.content.Parity  = Parity16(WriteDat.Dat);

    CS_L_AS5048;
    RW_AS5048(WriteDat.Dat);
    CS_H_AS5048;
    CS_L_AS5048;
    RW_AS5048(WriteDat.Dat);
    CS_H_AS5048;
}

/**
 * 读数据到指定地址
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2017-04-02
 *
 * @param   Addr       读取地址
 * @param   Dat        存放地址
 * @return             校检结果
 */
bool Read_AS5048(unsigned short Addr, unsigned short* Dat)
{
    AS5048_Package WriteDat;
    AS5048_Package ReadDat;

    WriteDat.content.Value  = Addr;
    WriteDat.content.Inf    = 1;
    WriteDat.content.Parity = Parity16(WriteDat.Dat);

    CS_L_AS5048;
    RW_AS5048(WriteDat.Dat);
    CS_H_AS5048;
    CS_L_AS5048;
    ReadDat.Dat = RW_AS5048(0x0000);
    CS_H_AS5048;

    if (ReadDat.content.Parity == Parity16(ReadDat.Dat))
    {
        *Dat = ReadDat.content.Value;
        return true;
    }

    return false;
}

/**
 * [Read_ANG_AS5048 description]
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2017-04-02
 *
 * @return             角度值
 */
void Read_ANG_AS5048(void)
{
    unsigned short Dat;

    CS_L_AS5048;
    RW_AS5048(0xffff);
    CS_H_AS5048;
    CS_L_AS5048;
    Angle_AS5048 = RW_AS5048(0x0000) << 2;
    CS_H_AS5048;

    // return Dat;
}
