#include "int_vector_min.h"

#include <stdio.h>

int int_vector_min(struct int_vector vec)
{
    size_t i = 0;
    int min = vec.data[0];
    if (vec.size == 0)
    {
        return 0;
    }
    else
    {
        while (vec.size > i)
        {
            if (vec.data[i] < min)
                min = vec.data[i];
            i++;
        }
    }
    return min;
}
