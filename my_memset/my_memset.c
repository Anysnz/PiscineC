#include <stdio.h>
#include <stdlib.h>

void *my_memset(void *s, int c, size_t n)
{
    char *i = s;
    while (n > 0)
    {
        *i = c;
        i++;
        n--;
    }
    return s;
}
