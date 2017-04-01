//�ļ�����FU68xx_GPIO.c
//˵����FU68ϵ��оƬ��IO�ڵײ�����
//Log
//Timer 		Writer      Thing
//2016-8-1		Any			�����ļ�

#include <FU68xx_GPIO.h>

//������: Init_PU_GPIO
//�β�: port, pin
//����: ����IO������ģʽ
//�޸�����: 16-8-1
//�汾: V1.0
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

//������: Init_OU_GPIO
//�β�: port, pin
//����: ����IO�����ģʽ
//�޸�����: 16-8-1
//�汾: V1.0
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

//������: Init_AN_GPIO
//�β�: port, pin
//����: ����IO��ģ��ģʽ
//�޸�����: 16-8-1
//�汾: V1.0
void Init_AN_GPIO(u8 port, u8 pin)
{
    switch (port)
    {
        case 1: P1AN = (1 << pin); break;
        case 2: P2AN = (1 << pin); break;
        case 3: P3AN = (1 << pin); break;
    }
}

//������: Init_OD_GPIO
//�β�: pin
//����: ����P0�ڿ�©ģʽ
//�޸�����: 16-8-1
//�汾: V1.0
void Init_OD_GPIO(u8 pin)
{
    P1AN = (1 << pin);
}
