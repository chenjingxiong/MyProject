//�ļ�����FU68xx_Flash.c
//˵����FU68ϵ��оƬ��FLASH�ײ�����
//Log
//Timer 		Writer      Thing                               Ver
//2016-8-05		Any			�����ļ�                            V1.0

#include <FU68xx_Flash.h>
#include <intrins.h>

sbit EA = 0xaf;


//������: Erase_Flash
//�β�: *FlashAddress
//����: ����FlashAddress���ڵ�������Flash
//�޸�����: 2016-8-08
//�汾: V3.0
bool Erase_Flash(U8 xdata *FlashAddress)
{
    bool tmpEA;
//    U8 xdata *FlashAddress = FlashSector * 128;
    
    tmpEA = EA;
	EA = 0;
    
    if (FlashAddress <= 0x3f7f) 
    {
        PSCTL = 0x03;           //ʹ���Բ���
        FLKEY = 0x5a;		
        FLKEY = 0x1f;           //flashԤ��̽���
        _nop_();
        *FlashAddress = 0xff;   //д��������
        PSCTL = 0x08;           //��ʼԤ��̣���ɺ�Flash�ٴ�����
    }
    
    EA = tmpEA;
    
	if(PSCTL & 0x10 == 0x10) return false;
	else                     return true;
}

//������: WriteByte_Flash
//�β�: *FlashAddress, FlashData
//����: дһ���ֵ�ָ��λ����
//�޸�����: 2016-8-08
//�汾: V3.0
bool WriteByte_Flash(U8 xdata *FlashAddress, U8 FlashData)
{
    bool tmpEA;

    tmpEA = EA;
	EA = 0;
    
    if (FlashAddress <= 0x3f7f) 
    {
        PSCTL = 0x01;										//ʹ��Flash���
        FLKEY = 0x5a;		
        FLKEY = 0x1f;                   //flashԤ��̽���	
        _nop_();
        *FlashAddress = FlashData;	    //д�������
        PSCTL = 0x08;			              //��ʼԤ��̣���ɺ�Flash�ٴ�����
    }
    
    EA = tmpEA;
    
	if(PSCTL & 0x10 == 0x10) return false;
	else                     return true;
}

//������: Write_Flash
//�β�: *FlashAddress, *FlashData
//����: дһ�����ݵ�
//�޸�����: 2016-8-08
//�汾: V3.0
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
            PSCTL = 0x01;										//ʹ��Flash���
            FLKEY = 0x5a;		
            FLKEY = 0x1f;										//flashԤ��̽���	
            _nop_();
            *FlashAddress = *FlashData;	    //д�������
            PSCTL = 0x08;			              //��ʼԤ��̣���ɺ�Flash�ٴ�����
            FlashAddress++;
            FlashData++;
            i++;
        }
    }
    
    EA = tmpEA;
}

//������: Read_Flash
//�β�: *FlashAddress
//����: дһ�����ݵ�
//�޸�����: 2016-8-08
//�汾: V2.0
U8 Read_Flash(U8 code *FlashAddress)
{
    U8 Buff;
            
    Buff = *FlashAddress;
        
    return Buff;
}