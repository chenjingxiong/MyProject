#include <stdbool.h>
#include <stdio.h>
#include <stm32f10x.h>
#include <API_Conf.h>
#include <Device_Conf.h>

//Main.c
//寻迹小车

//Log
//Date          Author          Notes
//2016-5-8      LinMin          V1.0
//2016-5-9      LinMin          增加tick时钟初始化
//2016-5-10     LinMin          将tick移动至SYSCLK.c,增加SYSTICK中断,增加传感器数据收集receive_sensor()
//2016-5-11     LinMin          修正receive_sensor()不能正常读取的错误,完成寻迹动作
//2016-5-25     LinMin          修改小车变速方式：由绝对式改为增量式；增加限幅，将PWM更新时间改为100ms
//2016-5-30     LinMin          变更滴答定时器定时时间为100ms；删除串口调试部分；优化注释

//传感器//*************************************************************************************************************************

//函数名：初始化传感器
//说明：  指定传感器链接端口，并且将它们设定为上拉输入
//输入：  无
//输出：  无
void init_sensor(void)
{
    GPIO_InitTypeDef GPIOBASE;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);      //启动GPIOA GPIOB的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIOBASE.GPIO_Mode = GPIO_Mode_IPU;                        //指定GPIO模式为上拉输入
    GPIOBASE.GPIO_Speed = GPIO_Speed_50MHz;                    //指定GPIO输入速度上限为50MHz
    
    GPIOBASE.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_11; //指定GPIOA中的7 8 11脚使用以上配置
    GPIO_Init(GPIOA, &GPIOBASE);                               //初始化GPIOA
    
    GPIOBASE.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;               //指定GPIOB中的0 1脚使用以上配置
    GPIO_Init(GPIOB, &GPIOBASE);                               //初始化GPIOB       
}

//函数名：收集传感器状态
//说明：  将传感器信号收集起来并进行排序组合
//输入：  无
//输出：  处理后的传感器数据
uint8_t receive_sensor(void)
{
    uint8_t tmpb = 0;
    
    uint16_t tmp = GPIO_ReadInputData(GPIOA) & (GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_11);//读取GPIOA的输入数据并只取出第7 8 11脚数据
    if (tmp & GPIO_Pin_11) tmpb |= 0x01;                                               //对GPIOA第7 8 11位的数据进行排列
    if (tmp & GPIO_Pin_8) tmpb |= 0x02;
    if (tmp & GPIO_Pin_7) tmpb |= 0x10;
    
    tmp = GPIO_ReadInputData(GPIOB) & (GPIO_Pin_0 | GPIO_Pin_1);                       //读取GPIOB的输入数据并只取出第0 1脚数据
    if (tmp & GPIO_Pin_0) tmpb |= 0x08;                                                //对GPIOB第0 1位的数据进行排列
    if (tmp & GPIO_Pin_1) tmpb |= 0x04;
    
    return tmpb;
}

//定时器//*************************************************************************************************************************
static bool time100ms = false;
static bool time500ms = false;

//函数名：滴答定时器中断处理函数
//说明：  进行计时累加，相应时间位置位
//输入：  无
//输出：  无
void SysTick_Handler(void)
{
    static uint8_t timebase = 0; //静态变量，重新进入该函数时，这个变量的值会保留
    
    timebase++;                  //当前所记时长：timebase * 100ms
    
    time100ms = true;            //每隔100ms进入中断，所以100ms计时到
    
    if (timebase == 5)           //当timebase记了5次，即500ms时，500ms标志位置位，timebase清零
    {
        timebase = 0;
        time500ms = true;
    }
}

//主函数//*************************************************************************************************************************
#define BASE 20000

//函数名：主函数
//说明：  进行初始化，运行闪灯，运行小车处理核心
//输入：  无
//输出：  无
int main(void)
{
    bool main500ms, main100ms;
    uint8_t sensor_value, sensor_value_tmp;
    short speedR = 10000;
    short speedL = 10000;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);       //AFIO//启动复用GPIO时钟
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE); //JTAG//设定只用SW-Link作为调试下载方式，将JTAG其他脚设置为IO口
    init_rgb();                                               //初始化LED灯
    init_pwm(BASE, 72);                                       //10->100khz 10000->100hz  20000->50hz//初始化PWM->50Hz
    init_sensor();                                            //初始化传感器
    init_systick(100, ms, true);                              //初始化滴答定时器->100ms
    
    while (1)
    {
        main100ms = time100ms;//更新定时器计时情况
        main500ms = time500ms;
        
        if (main500ms == true)//如果500ms定时到
        {
            control_rgb(RED, true);//控制红灯亮/灭
            
            time500ms = false;//清除500ms定时
        }
        
        if (main100ms == true)
        {
            sensor_value = receive_sensor();//读取传感器数据
            
            if (sensor_value == 0x1b || sensor_value == 0x00 ||
                sensor_value == 0x19 || sensor_value == 0x1d || 
                sensor_value == 0x1c || sensor_value == 0x1e || 
                sensor_value == 0x13 || sensor_value == 0x17 || 
                sensor_value == 0x07 || sensor_value == 0x0f)
            {
                sensor_value_tmp = sensor_value;
            }//如果传感器数据属于以上情况，则更新数据
            
            switch (sensor_value_tmp)
            {
                case 0x1b: speedR = 13000; speedL = 13000; break;//11011
                
                case 0x19: speedR += 1; speedL -= 1; break;//11001
                case 0x1d: speedR += 2; speedL -= 2; break;//11101
                case 0x1c: speedR += 4; speedL -= 4; break;//11100
                case 0x1e: speedR += 6; speedL -= 6; break;//11110
                
                case 0x13: speedR -= 1; speedL += 1; break;//10011
                case 0x17: speedR -= 2; speedL += 2; break;//10111
                case 0x07: speedR -= 4; speedL += 4; break;//00111
                case 0x0f: speedR -= 6; speedL += 6; break;//01111
                
                default:   speedR = 10000; speedL = 10000; break;
            }
            
            //以下为限幅
            if (speedR < 0)          speedR = 0;  
            else if (speedR > 20000) speedR = 20000;
            
            if (speedL < 0)          speedL = 0;
            else if (speedL > 20000) speedL = 20000;
            //更新PWM
            chang_pwm(BASE - (uint16_t)speedR, (uint16_t)speedR, 
                      BASE - (uint16_t)speedL, (uint16_t)speedL);
            
            time100ms = false;//清除100ms定时
        }
    }
}
