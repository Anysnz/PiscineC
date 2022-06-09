#include <limits.h>
#include <stdio.h>
int max_ptr(int *ptr, size_t size)
{
    int max = 0;
    if (size == 0)
    {
        return INT_MIN;
    }
    else
    {
        for (size_t i = 1; i < size; i++)
        {
            if (*(ptr + max) < *(ptr + i))
            {
                max = i;
            }
            else
                max = max;
        }
    }
    return *(ptr + max);
}
