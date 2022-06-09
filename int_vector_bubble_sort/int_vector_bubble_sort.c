#include "int_vector_bubble_sort.h"

#include <stdio.h>

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    if (vec.size != 0)
    {
        int tmp;
        for (size_t i = 0; i < vec.size - 1; i++)
        {
            for (size_t j = 0; j < vec.size - i - 1; j++)
            {
                if (vec.data[j] > vec.data[j + 1])
                {
                    tmp = vec.data[j];
                    vec.data[j] = vec.data[j + 1];
                    vec.data[j + 1] = tmp;
                }
            }
        }
    }
    return vec;
}
