#include <assert.h>
#include <stdio.h>

#include "heap.h"

void heapify(int *tab, unsigned pos, unsigned n)
{
    int swap;
    unsigned a;
    unsigned left;
    unsigned right;
    left = 2 * pos + 1;
    right = 2 * pos + 2;
    a = pos;
    if (left < n && tab[left] > tab[pos])
        a = left;
    if (right < n && tab[right] > tab[a])
        a = right;
    if (a != pos)
    {
        swap = tab[pos];
        tab[pos] = tab[a];
        tab[a] = swap;
        heapify(tab, a, n);
    }
}

int pop(struct heap *heap)
{
    unsigned del;
    unsigned p;
    if ((*heap).size == 0)
    {
        assert((*heap).size > 0);
    }
    if ((*heap).array == NULL)
        assert((*heap).size > 0);
    del = (*heap).array[0];
    p = (*heap).array[0];
    --p;
    heap[0] = heap[p];
    heapify((*heap).array, 0, p);
    return del;
}
