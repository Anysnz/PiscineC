#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *fifo = malloc(sizeof(*fifo));
    (*fifo).head = NULL;
    (*fifo).tail = NULL;
    (*fifo).size = 0;
    return fifo;
}

size_t fifo_size(struct fifo *fifo)
{
    if (fifo == NULL)
        return 0;
    return (*fifo).size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    if (fifo == NULL)
        return;
    struct list *el = malloc(sizeof(*el));
    if (el == NULL)
        return;
    (*el).data = elt;
    (*el).next = NULL;
    if ((*fifo).size == 0)
    {
        (*fifo).head = el;
        (*fifo).tail = el;
        (*fifo).size++;
    }
    else
    {
        (*(*fifo).tail).next = el;
        (*fifo).tail = el;
        (*fifo).size++;
    }
}

int fifo_head(struct fifo *fifo)
{
    if (fifo == NULL)
        return 0;
    return (*(*fifo).head).data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo == NULL)
        return;
    struct list *el = (*fifo).head;
    if ((*fifo).size == 1)
    {
        (*fifo).head = NULL;
        (*fifo).tail = NULL;
        (*fifo).size--;
    }
    else
    {
        (*fifo).head = (*(*fifo).head).next;
        (*fifo).size--;
    }
    free(el);
}
