#include "gpio.h"
/*����ܽ�GPIO���ñ�*/
/*TIM*/
/*��������----����*/
/*�Ƚ����----��������*/
/*�������----��������*/
/*ɲ������----����*/
/*ʱ������----����*/
/*UART*/
/*TX----��������*/
/*RX----����/��������˫��ģʽ��ֻ��Ϊͨ��IO��*/
/*CK----��������*/
/*RTS----��������*/
/*CTS----����/����*/
/*I2C*/
/*SCL----���ÿ�©*/
/*SDA----���ÿ�©*/
/*CAN*/
/*TX----��������*/
/*RX----����/����*/
/*SDIO*/
/*CK----��������*/
/*CMD----��������*/
/*DATA----��������*/
/*ADC/DAC*/
/*A----ģ������*/
/*EXTI*/
/*GPIO----����/����/����*/

GPIOInitStatu_Def init_GPIO( GPIO_TypeDef* gpiox, GPIOConf_Def conf, GPIOMode_Def mode, uint16_t pin )
{
    uint16_t pintmp = 1;
    uint32_t conftmp;
    GPIOInitStatu_Def statu = FALL;
    
    //���mode��conf�趨ƥ��,����г�ʼ��
    if ( mode == IN && conf < ( GPIOConf_Def )4 || mode != IN && conf > ( GPIOConf_Def )3 )
    {        
        //��ʱ��(0x40010800~0x40012000)
        RCC -> APB2ENR |= 1 << ( ( ( uint32_t )gpiox & 0x0000ffff ) >> 10 );
        
        //������Ϊ�Ǹ�������ģʽʱ��GPIO����������������
        if ( conf == IPU ) gpiox -> BSRR = pin;
        if ( conf == IPD ) gpiox -> BRR  = pin;
        
        //�ж������������Ӧconf��ֵ
        if ( mode > 0 ) conf -= PP;                                     
        conftmp = ( ( uint32_t )( conf - PP ) << 2 ) | ( uint32_t )mode;
        
        //����ʼ��Ͷ�뵽Ԥ����IO����
        for ( i=0; i!=16; i++)
        {
            if ( i < 8 ) if ( pin & pintmp ) gpiox -> CRL |= conftmp << ( i * 4 ); 
            else         if ( pin & pintmp ) gpiox -> CRH |= conftmp << ( ( i * 4 ) - 32 );
            pintmp <<= 1;
        }
        
        //GPIO��ʼ���ɹ�
        statu = SUCCESS;
    }
    
    //���mode��conf�趨��ƥ��,��statu����ı�,����FALL
    return statu;
}

uint16_t read_GPIO( GPIO_TypeDef* gpiox, uint16_t pin, GPIORead_Def inout )
{
    if ( inout == OUT ) return ( gpiox -> ODR & pin );
    return ( gpiox -> IDR & pin );
}

void write_GPIO( GPIO_TypeDef* gpiox, uint16_t pin, GPIOBitStatu_Def bit )
{
    if ( bit == SET ) gpiox -> BSRR = pin;
    else              gpiox -> BRR  = pin;
}
