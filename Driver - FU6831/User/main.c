/*
* @Filename:           main.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-01 23:45:04
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-02 22:38:12
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-04-01 23:45:45                           创建文件 //
///////////////////////////////////////////////////////////


/*******************************************************************************************************///Including Header Files
#include <FU68xx_MCU.h>

#include <stdio.h>
#include <intrins.h>
#include <stdbool.h>

#include <Driver_Conf.h>
#include <API_Conf.h>

#include <Init.h>
#include <Interrupt.h>
/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols
/*******************************************************************************************************///Function Subject
void main(void)
{
    bool main2ms;
    uint16_t DatLast;
    uint16_t DatOut;
    // uint8_t i = 0;

    struct
    {
        uint16_t BUFF[3];
        uint8_t  _SP;
    }OB_Win = { 0 };

    Init();

    while (1)
    {
        main2ms = time2ms;
        if (main2ms)
        {
            Shine_RGB(R_Pin);
            Read_ANG_AS5048();
            if (Angle_AS5048 != 0)
            {
                DatLast = Angle_AS5048;

            }
            DatOut = DatLast;
            Shine_RGB(R_Pin);

            Load_ANO_Package((uint8_t)(DatOut >> 8));
            Load_ANO_Package((uint8_t)DatOut);
            while (!Send_ANO_Package());
            Reset_ANO_Package(0xf1, 2);

            time2ms = false;
        }
    }
}
