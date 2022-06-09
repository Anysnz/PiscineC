#include <limits.h>
#include <stddef.h>
#include <stdio.h>

int sommet_ok(int tab[], size_t len, size_t pos)
{
    for (size_t i = 0; i < pos; i++)
    {
        if (tab[i] > tab[i + 1])
            return 0;
    }
    for (size_t i = pos; i < len - 1; i++)
    {
        if (tab[i] < tab[i + 1])
            return 0;
    }
    return 1;
}
int top_of_the_hill(int tab[], size_t len)
{
    int pos = 0;
    int max = tab[0];
    for (size_t i = 0; i < len; i++)
    {
        if (tab[i] > max)
        {
            pos = i;
            max = tab[i];
        }
    }
    if (sommet_ok(tab, len, pos))
        return pos;
    else
        return -1;
}
