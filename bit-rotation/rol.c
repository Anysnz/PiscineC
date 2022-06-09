#include <stdio.h>
#define INT_SIZE sizeof(int)
#define INT_BITS INT_SIZE * 8 - 1

unsigned char rol(unsigned char value, unsigned char roll)
{
    if ((roll &= sizeof(value) * 8 - 1) == 0)
        return value;
    return (value << roll) | (value >> (sizeof(value) * 8 - roll));
}
