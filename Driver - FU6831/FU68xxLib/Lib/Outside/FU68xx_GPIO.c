//文件名：FU68xx_GPIO.c
//说明：FU68系列芯片的IO口底层驱动
//Log
//Timer 		Writer      Thing
//2016-8-1		Any			创建文件

#include <FU68xx_GPIO.h>

//函数名: Init_PU_GPIO
//形参: port, pin
//功能: 配置IO口上拉模式
//修改日期: 16-8-1
//版本: V1.0
void Init_PU_GPIO(u8 port, u8 pin)
{
    switch (port)
    {
        case 0: P0PU = (1 << pin); break;
        case 1: P1PU = (1 << pin); break;
        case 2: P2PU = (1 << pin); break;
        case 3: P3PU = (1 << pin); break;
    }
}

//函数名: Init_OU_GPIO
//形参: port, pin
//功能: 配置IO口输出模式
//修改日期: 16-8-1
//版本: V1.0
void Init_OU_GPIO(u8 port, u8 pin)
{
    switch (port)
    {
        case 0: P0OE = (1 << pin); break;
        case 1: P1OE = (1 << pin); break;
        case 2: P2OE = (1 << pin); break;
        case 3: P3OE = (1 << pin); break;
    }
}

//函数名: Init_AN_GPIO
//形参: port, pin
//功能: 配置IO口模拟模式
//修改日期: 16-8-1
//版本: V1.0
void Init_AN_GPIO(u8 port, u8 pin)
{
    switch (port)
    {
        case 1: P1AN = (1 << pin); break;
        case 2: P2AN = (1 << pin); break;
        case 3: P3AN = (1 << pin); break;
    }
}

//函数名: Init_OD_GPIO
//形参: pin
//功能: 配置P0口开漏模式
//修改日期: 16-8-1
//版本: V1.0
void Init_OD_GPIO(u8 pin)
{
    P1AN = (1 << pin);
}
