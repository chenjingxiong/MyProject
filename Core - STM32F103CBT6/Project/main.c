#include <stdbool.h>
#include <stdio.h>
#include <stm32f10x.h>
#include <API_Conf.h>
#include <Device_Conf.h>

//Main.c
//Ѱ��С��

//Log
//Date          Author          Notes
//2016-5-8      LinMin          V1.0
//2016-5-9      LinMin          ����tickʱ�ӳ�ʼ��
//2016-5-10     LinMin          ��tick�ƶ���SYSCLK.c,����SYSTICK�ж�,���Ӵ����������ռ�receive_sensor()
//2016-5-11     LinMin          ����receive_sensor()����������ȡ�Ĵ���,���Ѱ������
//2016-5-25     LinMin          �޸�С�����ٷ�ʽ���ɾ���ʽ��Ϊ����ʽ�������޷�����PWM����ʱ���Ϊ100ms
//2016-5-30     LinMin          ����δ�ʱ����ʱʱ��Ϊ100ms��ɾ�����ڵ��Բ��֣��Ż�ע��

//������//*************************************************************************************************************************

//����������ʼ��������
//˵����  ָ�����������Ӷ˿ڣ����ҽ������趨Ϊ��������
//���룺  ��
//�����  ��
void init_sensor(void)
{
    GPIO_InitTypeDef GPIOBASE;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);      //����GPIOA GPIOB��ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIOBASE.GPIO_Mode = GPIO_Mode_IPU;                        //ָ��GPIOģʽΪ��������
    GPIOBASE.GPIO_Speed = GPIO_Speed_50MHz;                    //ָ��GPIO�����ٶ�����Ϊ50MHz
    
    GPIOBASE.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_11; //ָ��GPIOA�е�7 8 11��ʹ����������
    GPIO_Init(GPIOA, &GPIOBASE);                               //��ʼ��GPIOA
    
    GPIOBASE.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;               //ָ��GPIOB�е�0 1��ʹ����������
    GPIO_Init(GPIOB, &GPIOBASE);                               //��ʼ��GPIOB       
}

//���������ռ�������״̬
//˵����  ���������ź��ռ������������������
//���룺  ��
//�����  �����Ĵ���������
uint8_t receive_sensor(void)
{
    uint8_t tmpb = 0;
    
    uint16_t tmp = GPIO_ReadInputData(GPIOA) & (GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_11);//��ȡGPIOA���������ݲ�ֻȡ����7 8 11������
    if (tmp & GPIO_Pin_11) tmpb |= 0x01;                                               //��GPIOA��7 8 11λ�����ݽ�������
    if (tmp & GPIO_Pin_8) tmpb |= 0x02;
    if (tmp & GPIO_Pin_7) tmpb |= 0x10;
    
    tmp = GPIO_ReadInputData(GPIOB) & (GPIO_Pin_0 | GPIO_Pin_1);                       //��ȡGPIOB���������ݲ�ֻȡ����0 1������
    if (tmp & GPIO_Pin_0) tmpb |= 0x08;                                                //��GPIOB��0 1λ�����ݽ�������
    if (tmp & GPIO_Pin_1) tmpb |= 0x04;
    
    return tmpb;
}

//��ʱ��//*************************************************************************************************************************
static bool time100ms = false;
static bool time500ms = false;

//���������δ�ʱ���жϴ�����
//˵����  ���м�ʱ�ۼӣ���Ӧʱ��λ��λ
//���룺  ��
//�����  ��
void SysTick_Handler(void)
{
    static uint8_t timebase = 0; //��̬���������½���ú���ʱ�����������ֵ�ᱣ��
    
    timebase++;                  //��ǰ����ʱ����timebase * 100ms
    
    time100ms = true;            //ÿ��100ms�����жϣ�����100ms��ʱ��
    
    if (timebase == 5)           //��timebase����5�Σ���500msʱ��500ms��־λ��λ��timebase����
    {
        timebase = 0;
        time500ms = true;
    }
}

//������//*************************************************************************************************************************
#define BASE 20000

//��������������
//˵����  ���г�ʼ�����������ƣ�����С���������
//���룺  ��
//�����  ��
int main(void)
{
    bool main500ms, main100ms;
    uint8_t sensor_value, sensor_value_tmp;
    short speedR = 10000;
    short speedL = 10000;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);       //AFIO//��������GPIOʱ��
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE); //JTAG//�趨ֻ��SW-Link��Ϊ�������ط�ʽ����JTAG����������ΪIO��
    init_rgb();                                               //��ʼ��LED��
    init_pwm(BASE, 72);                                       //10->100khz 10000->100hz  20000->50hz//��ʼ��PWM->50Hz
    init_sensor();                                            //��ʼ��������
    init_systick(100, ms, true);                              //��ʼ���δ�ʱ��->100ms
    
    while (1)
    {
        main100ms = time100ms;//���¶�ʱ����ʱ���
        main500ms = time500ms;
        
        if (main500ms == true)//���500ms��ʱ��
        {
            control_rgb(RED, true);//���ƺ����/��
            
            time500ms = false;//���500ms��ʱ
        }
        
        if (main100ms == true)
        {
            sensor_value = receive_sensor();//��ȡ����������
            
            if (sensor_value == 0x1b || sensor_value == 0x00 ||
                sensor_value == 0x19 || sensor_value == 0x1d || 
                sensor_value == 0x1c || sensor_value == 0x1e || 
                sensor_value == 0x13 || sensor_value == 0x17 || 
                sensor_value == 0x07 || sensor_value == 0x0f)
            {
                sensor_value_tmp = sensor_value;
            }//�����������������������������������
            
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
            
            //����Ϊ�޷�
            if (speedR < 0)          speedR = 0;  
            else if (speedR > 20000) speedR = 20000;
            
            if (speedL < 0)          speedL = 0;
            else if (speedL > 20000) speedL = 20000;
            //����PWM
            chang_pwm(BASE - (uint16_t)speedR, (uint16_t)speedR, 
                      BASE - (uint16_t)speedL, (uint16_t)speedL);
            
            time100ms = false;//���100ms��ʱ
        }
    }
}
