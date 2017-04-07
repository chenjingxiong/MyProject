/*
* @Filename:           main.c
* @Author:             Administrator
* @Explain:
* @Date:               2017-04-01 23:45:04
*
* @Last Modified by:   Any
* @Last Modified time: 2017-04-07 16:07:45
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
#include <Hardware.h>
/*******************************************************************************************************///Define Macro
/*******************************************************************************************************///Define Global Symbols
/*******************************************************************************************************///Function Subject
void main(void)
{
    bool main2ms;
    bool main500ms;

    uint16_t DatLast;
    uint16_t DatOut;
    uint16_t i = 0;
    int16_t  Sin;

    Init();
    Sin = SV_SIN;

    while (1)
    {
        main2ms   = time2ms;
        main500ms = time500ms;

        if (main2ms)
        {
            Read_ANG_AS5048();
            if (Angle_AS5048 != 0) DatLast = Angle_AS5048;
            DatOut = DatLast;


            i = -Angle_SensorToElectric(DatOut);
            Set_FOC_Theta(i);


            Load_ANO_Package((uint8_t)(DatOut >> 8));
            Load_ANO_Package((uint8_t)DatOut);
            Load_ANO_Package((uint8_t)(i >> 8));
            Load_ANO_Package((uint8_t)i);
            while (!Send_ANO_Package());
            Reset_ANO_Package(0xf1, DAT_LEN);

            time2ms = false;
        }

        if (main500ms)
        {
            Sin *= -1;
            Set_FOC_QMax(Sin);
            Set_FOC_QMin(Sin);
            Set_FOC_QOut(Sin);

            time500ms = false;
        }
    }
}
