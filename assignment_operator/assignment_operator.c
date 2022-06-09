#include <stdio.h>

void plus_equal(int *a, int *b)
{
    if (a != NULL && b != NULL)
        *a = *a + *b;
}

void minus_equal(int *a, int *b)
{
    if (a != NULL && b != NULL)
        *a = *a - *b;
}

void mult_equal(int *a, int *b)
{
    if (a != NULL && b != NULL)
        *a = *a * *b;
}

int div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return 0;
    else if (*b == 0)
        return 0;
    int rest = *a % *b;
    *a = *a / *b;
    return rest;
}
