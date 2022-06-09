#include <assert.h>
#include <stddef.h>
#include <stdio.h>

int *binary_search(int *begin, int *end, int elt)
{
    if (end >= begin)
    {
        int *milieu = begin + (end - begin) / 2;
        if (*milieu == elt)
        {
            return milieu;
        }
        if (*milieu > elt)
        {
            return binary_search(begin, milieu - 1, elt);
        }
        else if (*milieu < elt)
        {
            return binary_search(milieu + 1, end, elt);
        }
    }
    return begin;
}
