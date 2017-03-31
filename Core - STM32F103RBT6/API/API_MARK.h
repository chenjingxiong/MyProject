#ifndef __API_MARK_H__
#define __API_MARK_H__

/*******************************************************************************************************///Including Header Files
 #include<stm32f4xx.h>
/*******************************************************************************************************///Define Struct/Union Type
/*******************************************************************************************************///Define Macro
/*******************************************************************************************************///Extern Symbols
/*******************************************************************************************************///Inline Functions
__inline int8_t Q7(double x)
{
    return (int8_t)(x * (double)0x7f);
}

__inline int16_t Q15(double x)
{
    return (int16_t)(x * (double)0x7fff);
}

__inline int32_t Q31(double x)
{
    return (int32_t)(x * (double)0x7fffffff);
}

__inline int64_t Q63(double x)
{
    return (int64_t)(x * (double)0x7fffffffffffffff);
}

__inline uint8_t Q8(double x)
{
    return (uint8_t)(x * (double)0xff);
}

__inline uint16_t Q16(double x)
{
    return (uint16_t)(x * (double)0xffff);
}

__inline uint32_t Q32(double x)
{
    return (uint32_t)(x * (double)0xffffffff);
}

__inline uint64_t Q64(double x)
{
    return (uint64_t)(x * (double)0xffffffffffffffff);
}



__inline int8_t Q15_Q7(int16_t x)
{
    return (x >> 7);
}

__inline int8_t Q31_Q7(int32_t x)
{
    return (x >> 23);
}

__inline int8_t Q63_Q7(int64_t x)
{
    return (x >> 55);
}

__inline int16_t Q31_Q15(int32_t x)
{
    return (x >> 15);
}

__inline int16_t Q63_Q15(int64_t x)
{
    return (x >> 47);
}

__inline int32_t Q63_Q31(int64_t x)
{
    return (x >> 31);
}



__inline uint8_t Q16_Q8(uint16_t x)
{
    return (x >> 8);
}

__inline uint8_t Q32_Q8(uint32_t x)
{
    return (x >> 24);
}

__inline uint8_t Q64_Q8(uint64_t x)
{
    return (x >> 56);
}

__inline uint16_t Q32_Q16(uint32_t x)
{
    return (x >> 16);
}

__inline uint16_t Q64_Q16(uint64_t x)
{
    return (x >> 48);
}

__inline uint32_t Q64_Q32(uint64_t x)
{
    return (x >> 32);
}
/*******************************************************************************************************///Extern Functions

#endif
