/*
* @Filename:           main.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-01 23:45:04
*
* @Last Modified by:   Administrator
* @Last Modified time: 2017-04-05 22:32:35
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
    int16_t i = 0;

    Init();

    while (1)
    {
        main2ms = time2ms;
        if (main2ms)
        {
            Shine_RGB(R_Pin);

            Read_ANG_AS5048();
            if (Angle_AS5048 != 0) DatLast = Angle_AS5048;
            DatOut = DatLast;

            Shine_RGB(R_Pin);

//            i += 256;
            Set_Theta(0);


            Load_ANO_Package((uint8_t)(DatOut >> 8));
            Load_ANO_Package((uint8_t)DatOut);
            Load_ANO_Package((int8_t)(i >> 8));
            Load_ANO_Package((int8_t)i);

            while (!Send_ANO_Package());
            Reset_ANO_Package(0xf1, DAT_LEN);

            time2ms = false;
        }
    }
}
