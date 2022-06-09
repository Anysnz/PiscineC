#include <stddef.h>
#include <stdlib.h>

int *my_calloc(size_t size, int init)
{
    if (size == 0)
        return NULL;
    else
    {
        int *tab = malloc(size * sizeof(int));
        if (!tab)
            return NULL;
        for (size_t i = 0; i < size; i++)
            tab[i] = init;
        return tab;
    }
}
