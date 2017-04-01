//文件名：FU68xx_Flash.c
//说明：FU68系列芯片的FLASH底层驱动
//Log
//Timer 		Writer      Thing                               Ver
//2016-8-05		Any			创建文件                            V1.0

#include <FU68xx_Flash.h>
#include <intrins.h>

sbit EA = 0xaf;


//函数名: Erase_Flash
//形参: *FlashAddress
//功能: 擦除FlashAddress所在的扇区的Flash
//修改日期: 2016-8-08
//版本: V3.0
bool Erase_Flash(U8 xdata *FlashAddress)
{
    bool tmpEA;
//    U8 xdata *FlashAddress = FlashSector * 128;
    
    tmpEA = EA;
	EA = 0;
    
    if (FlashAddress <= 0x3f7f) 
    {
        PSCTL = 0x03;           //使能自擦除
        FLKEY = 0x5a;		
        FLKEY = 0x1f;           //flash预编程解锁
        _nop_();
        *FlashAddress = 0xff;   //写任意数据
        PSCTL = 0x08;           //开始预编程，完成后Flash再次上锁
    }
    
    EA = tmpEA;
    
	if(PSCTL & 0x10 == 0x10) return false;
	else                     return true;
}

//函数名: WriteByte_Flash
//形参: *FlashAddress, FlashData
//功能: 写一个字到指定位置上
//修改日期: 2016-8-08
//版本: V3.0
bool WriteByte_Flash(U8 xdata *FlashAddress, U8 FlashData)
{
    bool tmpEA;

    tmpEA = EA;
	EA = 0;
    
    if (FlashAddress <= 0x3f7f) 
    {
        PSCTL = 0x01;										//使能Flash编程
        FLKEY = 0x5a;		
        FLKEY = 0x1f;                   //flash预编程解锁	
        _nop_();
        *FlashAddress = FlashData;	    //写编程数据
        PSCTL = 0x08;			              //开始预编程，完成后Flash再次上锁
    }
    
    EA = tmpEA;
    
	if(PSCTL & 0x10 == 0x10) return false;
	else                     return true;
}

//函数名: Write_Flash
//形参: *FlashAddress, *FlashData
//功能: 写一串数据到
//修改日期: 2016-8-08
//版本: V3.0
void Write_Flash(U8 xdata *FlashAddress, U8* FlashData, U8 sizes)
{
    bool tmpEA;
    U8 i = 0;
    
    tmpEA = EA;
	EA = 0;
    
    if (FlashAddress <= 0x3f7f) 
    {
        while (i != sizes)
        {
            PSCTL = 0x01;										//使能Flash编程
            FLKEY = 0x5a;		
            FLKEY = 0x1f;										//flash预编程解锁	
            _nop_();
            *FlashAddress = *FlashData;	    //写编程数据
            PSCTL = 0x08;			              //开始预编程，完成后Flash再次上锁
            FlashAddress++;
            FlashData++;
            i++;
        }
    }
    
    EA = tmpEA;
}

//函数名: Read_Flash
//形参: *FlashAddress
//功能: 写一串数据到
//修改日期: 2016-8-08
//版本: V2.0
U8 Read_Flash(U8 code *FlashAddress)
{
    U8 Buff;
            
    Buff = *FlashAddress;
        
    return Buff;
}