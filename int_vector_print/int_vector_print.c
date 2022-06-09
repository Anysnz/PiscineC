#include "int_vector_print.h"

#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    printf("%d", vec.data[0]);
    size_t i = 1;
    while (i < vec.size)
    {
        printf(" %d", vec.data[i]);
        i++;
    }
    printf("\n");
}
