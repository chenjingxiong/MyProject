//////////////////////////////////////////////////////////////////////
//文件名：FU68xx_I2C.c                                              //
//说明：FU68系列芯片的I2C底层驱动                                   //
//Log                                                               //
//Timer         Writer      Thing                               Ver //
//2016-10-08    Any         创建文件                            V1.0//
//2016-10-09    Any         I2C初始化增加速度设置               V1.1//
//2016-10-09    Any         增加数据位操作                      V1.2//
//2016-10-10    Any         将I2C的启动改为随时启动             V1.3//
//2016-12-08    Any         更新注释                            V1.4//
//2016-12-08    Any         删除单次收发的相关函数              V1.5//
//2016-12-08    Any         封闭小函数，取消应答、收发宏定义    V1.6//
//2016-12-08    Any         对位操作函数做适应性修改            V1.7//
//2016-12-14    Any         恢复单次收发函数                    V1.8//
//2016-12-22    Any         修改等待函数类型为bool              V1.9//
//////////////////////////////////////////////////////////////////////


#include <FU68xx_I2C.h>
#include <intrins.h>

static unsigned char config = 0xc0;

/**
 * 初始化I2C配置
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2016-10-09
 *
 * @param   speed      I2C时钟频率
 */
void Init_I2C(char speed)
{
    config = 0xc0 + speed;
}

/**
 * 使能I2C
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-10-10
 *
 * @param   sw         0:关闭    1:启动    
 */
void Enable_I2C(bool sw)
{
    if (sw) I2CMOD = config;
    else    I2CMOD = 0;
}

/**
 * 等待时钟线松开
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2016-12-22
 *
 * @return             false:未松开    true:已松开
 */
static bool Wait_I2C(void)
{
    if ((I2CSTA & 0x04) == 0x04) return false;
    
    return true;
}

/**
 * 启动I2C传输
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-10-09
 *
 * @param   rw         0:MOSI    1：MISO
 */
void Start_I2C(bool rw)
{
    I2CSTA = 0x10 + ((unsigned char)rw * 0x40);
    while (Wait_I2C());
}

/**
 * 发送停止信号
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-10-09
 *
 */
void Stop_I2C(void)
{
    I2CSTA |= 0x08;
    I2CSTA &= ~0x04;
    while ((I2CSTA & 0x08) == 0x08);
}

/**
 * 载入I2C地址
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-10-09
 *
 * @param   Addr7      从设备7位地址
 */
void Addr_I2C(unsigned char Addr7)
{
    I2CID = Addr7;
}

/**
 * 发送数据
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-10-09
 *
 * @param   Dat        要发送的数据
 */
void Send_I2C(unsigned char Dat)
{
    I2CDAT = Dat;
    I2CSTA &= ~0x04;
    while (Wait_I2C());
}

/**
 * 接收数据
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-10-09
 *
 * @return             收到的数据
 */
static unsigned char Receive_I2C(void)
{
    I2CSTA &= ~0x04;
    while (Wait_I2C());
    return I2CDAT;
}

/**
 * 获取应答信号
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-10-09
 *
 * @return             0:无应答    1:应答
 */
bool Get_Ack_I2C(void)
{
    bool tmp = false;

    _nop_();
    if ((I2CSTA & 0x02) == 0x00) tmp = true;

    return tmp;
}

/**
 * 发送应答信号
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-10-09
 *
 * @param   Ack        0:无应答    1:应答
 */
void Set_Ack_I2C(bool Ack)
{
    if (Ack) I2CSTA &= ~0x02;
    else     I2CSTA |=  0x02;
}

/**
 * 写入单字节数据
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-12-14
 *
 * @param   addr7      从机7位地址
 * @param   reg        写入的寄存器
 * @param   dat        数据
 * @return             0:写入失败    1:写入成功
 */
bool Write_Byte_I2C(unsigned char addr7, unsigned char reg, unsigned char dat)
{
    Enable_I2C(true);

    Addr_I2C(addr7);

    Start_I2C(false);
    if (!Get_Ack_I2C()) return false;

    Send_I2C(reg);
    if (!Get_Ack_I2C()) return false;

    Send_I2C(dat);
    if (!Get_Ack_I2C()) return false;

    Stop_I2C();

    Enable_I2C(false);

    return true;
}

/**
 * 读取单字节数据
 *
 * @Writer  Any
 * @Version V1.0
 * @Date    2016-12-14
 *
 * @param   addr7      从机7位地址
 * @param   reg        写入的寄存器
 * @param   dat        数据存放地址
 * @return             0:写入失败    1:写入成功
 */
bool Read_Byte_I2C(unsigned char addr7, unsigned char reg, unsigned char* dat)
{
    Enable_I2C(true);
    
    Addr_I2C(addr7);

    Start_I2C(false);
    if (!Get_Ack_I2C()) return false;

    Send_I2C(reg);
    if (!Get_Ack_I2C()) return false;

    Start_I2C(true);
    if (!Get_Ack_I2C()) return false;

    *dat = Receive_I2C();
    Set_Ack_I2C(false);

    Stop_I2C();

    Enable_I2C(false);
    
    return true;
}

/**
 * 连续写入数据
 *
 * @Writer  Any
 * @Version V1.2
 * @Date    2016-12-08
 *
 * @param   addr7      从机7位地址
 * @param   reg        第一个写入的寄存器
 * @param   length     数据长度
 * @param   dat        数据包
 * @return             0:写入失败    1:写入成功
 */
bool Write_I2C(unsigned char addr7, unsigned char reg, unsigned char length, unsigned char* dat)
{
	unsigned char i;

    Enable_I2C(true);

	Addr_I2C(addr7);

    #if defined(ADDR_AUTO_ADD)
    	Start_I2C(false);
        if (!Get_Ack_I2C()) return false;

    	Send_I2C(reg);
        if (!Get_Ack_I2C()) return false;

    	for (i=0; i!=length; i++)
    	{
    		Send_I2C(*dat);
            if (!Get_Ack_I2C()) return false;
            dat++;
    	}
    #else
        for (i=0; i!=length; i++)
        {
            Start_I2C(false);
            if (!Get_Ack_I2C()) return false;

            Send_I2C(reg);
            if (!Get_Ack_I2C()) return false;

            Send_I2C(*dat);
            if (!Get_Ack_I2C()) return false;
            dat++;
            reg++;
        }
    #endif

	Stop_I2C();

    Enable_I2C(false);

    return true;
}

/**
 * 读出连续数据
 *
 * @Writer  Any
 * @Version V1.2
 * @Date    2016-12-08
 *
 * @param   addr7      从机7位地址
 * @param   reg        第一个读出的寄存器
 * @param   length     读出的数据长度
 * @param   dat        读出的数据包
 * @return             0:读出失败    1：读出成功
 */
bool Read_I2C(unsigned char addr7, unsigned char reg, unsigned char length, unsigned char* dat)
{
    unsigned char i;

    Enable_I2C(true);
    
    Addr_I2C(addr7);

    #if defined(ADDR_AUTO_ADD)
        Start_I2C(false);
        if (!Get_Ack_I2C()) return false;

        Send_I2C(reg);
        if (!Get_Ack_I2C()) return false;

        Start_I2C(true);
        if (!Get_Ack_I2C()) return false;

        for (i=0; i!=length; i++)
        {
            *(dat + i) = Receive_I2C();

            if (i == (length-1)) Set_Ack_I2C(false);
            else                 Set_Ack_I2C(true);
        }
    #else
        for (i=0; i!=length; i++)
        {
            Start_I2C(false);
            if (!Get_Ack_I2C()) return false;
            
            Send_I2C(reg + i);
            if (!Get_Ack_I2C()) return false;

            Start_I2C(true);
            if (!Get_Ack_I2C()) return false;
        
            Send_I2C(*dat);
            if (!Get_Ack_I2C()) return false; 
            dat++;
        }
    #endif

    Stop_I2C();

    Enable_I2C(false);
    
    return true;
}

/**
 * 写入连续的位值
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2016-12-08
 *
 * @param   addr7      从机7位地址
 * @param   reg        写入的寄存器
 * @param   bitS       写入的起始位
 * @param   length     写入的位数
 * @param   dat        写入的数据
 * @return             0:写入失败    1:写入成功
 */
bool Write_Bits_I2C(unsigned char addr7, unsigned char reg, unsigned char bitS, unsigned char length, unsigned char dat)
{
    unsigned char tmp;
    unsigned char mask;
    char move = bitS + 1 - length;

    if (Read_I2C(addr7, reg, 1, &tmp)) 
    {
        mask = ((1 << length) - 1) << move;
        dat <<= move;
        dat &= mask;
        tmp &= ~mask;
        tmp |= dat;
        Write_I2C(addr7, reg, 1, &tmp);
    }
    else
    {
        return false;
    }

    return true;
}

/**
 * 读出连续的位值
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2016-12-08
 *
 * @param   addr7      从机7位地址
 * @param   reg        读出的寄存器
 * @param   bitS       数据的起始位
 * @param   length     读出的位长
 * @param   dat        读出的数据
 * @return             0:读出失败    1:读出成功
 */
bool Read_Bits_I2C(unsigned char addr7, unsigned char reg, unsigned char bitS, unsigned char length, unsigned char* dat)
{
    unsigned char tmp;
    unsigned char mask;
    char move = bitS + 1 - length;

    if (Read_I2C(addr7, reg, 1, &tmp)) 
    {
        mask = ((1 << length) - 1) << move;
        tmp &= mask;
        tmp >>= move;
        *dat = tmp;
    }
    else
    {
        return false;
    }

    return true;
}

char Write_Bit_I2C(unsigned char slave, unsigned char addr, unsigned char bitNum, unsigned char Data)
{
    unsigned char b;

    if (Read_Byte_I2C(slave, addr, &b))
    {
        b = (Data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
        return Write_Byte_I2C(slave, addr, b);    //写入数据
    }

    return 0;
}

char Read_Bit_I2C(unsigned char slave, unsigned char addr, unsigned char bitNum, unsigned char *Data)
{
    unsigned char b;

    if (Read_Byte_I2C(slave, addr, &b))
    {
        *Data = b & (1 << bitNum);

        return 1;
    }

    return 0;
}
