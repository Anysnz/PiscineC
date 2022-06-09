#include <stdio.h>

void pointer_swap(int **a, int **b)
{
    if (a != NULL && b != NULL)
    {
        int *tmp = *a;
        *a = *b;
        *b = tmp;
    }
}
