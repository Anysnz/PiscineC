#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

void fifo_clear(struct fifo *fifo)
{
    if (!fifo)
        return;
    while ((*fifo).size > 0)
        fifo_pop(fifo);
}

void fifo_destroy(struct fifo *fifo)
{
    if (!fifo)
        return;
    fifo_clear(fifo);
    free(fifo);
    fifo = NULL;
}

void fifo_print(const struct fifo *fifo)
{
    if ((*fifo).size == 0)
        return;
    struct list *tmp = (*fifo).head;
    printf("%d", (*tmp).data);
    tmp = (*tmp).next;
    while (tmp)
    {
        printf("-%d", (*tmp).data);
        tmp = (*tmp).next;
    }
    printf("\n");
}
