#include <stdio.h>

#include "heap.h"

void base(int o)
{
    if (o < 0)
    {
        o = (-1) * o;
        putchar('-');
    }
    if (o / 10)
        base(o / 10);
    putchar(o % 10 + '0');
}
void bis(const struct heap *heap, size_t ch)
{
    size_t t;
    int p;
    t = (*heap).size;
    if (ch > t - 1)
        return;
    putchar(' ');
    p = (*heap).array[ch];
    base(p);
    bis(heap, ch * 2 + 1);
    bis(heap, ch * 2 + 2);
}

void print_heap(const struct heap *heap)
{
    base((*heap).array[0]);
    bis(heap, 1);
    bis(heap, 2);
    putchar('\n');
}
