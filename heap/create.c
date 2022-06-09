#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *heap = malloc(sizeof(heap));
    (*heap).size = 0;
    (*heap).capacity = 8;
    (*heap).array = malloc((*heap).capacity * sizeof(int));

    return heap;
}
