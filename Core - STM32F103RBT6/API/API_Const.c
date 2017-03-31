/*
* @Filename:           API_Const.c
* @Author:             Min Lin
* @Explain:
* @Date:               2017-02-25 16:29:58
*
* @Last Modified by:   Min Lin
* @Last Modified time: 2017-03-02 21:43:44
*/

///////////////////////////////////////////////////////////
//LOG                                                    //
//2017-02-25 16:30:21         移植常量初始化函数到新文件 //
//2017-03-01 22:27:16                     添加标幺值常量 //
///////////////////////////////////////////////////////////

#include <API_Const.h>

/*******************************************************************************************************///Including Header Files
#include <math.h>
#include <API_MARK.h>
/*******************************************************************************************************///Define Macro

/*******************************************************************************************************///Define Global Symbols
double DIV2_3;
double SQRT3;
double SQRTcDIV2_3;
double DIVcSQRT3_2;

int32_t qDIV2_3;
int32_t qSQRTcDIV2_3;
int32_t qDIVcSQRT3_2;
/*******************************************************************************************************///Function Subject
/**
 * 初始化常量值
 *
 * @Writer  Any
 * @Version V1.1
 * @Date    2017-02-25
 *
 */
void Init_Const(void)
{
    DIV2_3       = 2.0 / 3.0;
    SQRT3        = sqrt(3);

    SQRTcDIV2_3  = sqrt(DIV2_3);
    DIVcSQRT3_2  = SQRT3 / 2.0;

    qDIV2_3      = Q31(DIV2_3);
    qSQRTcDIV2_3 = Q31(SQRTcDIV2_3);
    qDIVcSQRT3_2 = Q31(DIVcSQRT3_2);
}
