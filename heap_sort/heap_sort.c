#include <stddef.h>
#include <stdio.h>

void heapify(int *tab, unsigned n)
{
    for (size_t pos = 0; pos < n; pos++)
    {
        unsigned g = pos;
        unsigned l;
        unsigned r;
        l = 2 * pos + 1;
        r = 2 * pos + 2;
        if (l < n && tab[l] > tab[pos])
            g = l;
        if (r < n && tab[r] > tab[g])
            g = r;
        if (g != pos)
        {
            int swapp = tab[pos];
            tab[pos] = tab[g];
            tab[g] = swapp;
            heapify(tab, n);
        }
    }
}

void make_heap(int *array, size_t size)
{
    unsigned c = (size / 2) - 1;
    int j;
    for (j = c; j >= 0; j--)
    {
        heapify(array, size);
    }
}
int pop_heap(int *heap, unsigned *n)
{
    *n = *n - 1;
    int first = heap[0];
    heap[0] = heap[*n];
    heapify(heap, *n);
    return first;
}
void heap_sort(int *tab, unsigned n)
{
    unsigned x;
    unsigned y;
    make_heap(tab, n);
    for (x = 0; x < n; x++)
    {
        y = n - x;
        tab[y - 1] = pop_heap(tab, &y);
    }
}
