#include "list.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *element = malloc(sizeof(struct list));
    if (!value || !element)
    {
        free(element);
        return NULL;
    }
    (*element).data = malloc(data_size);
    if (!(*element).data)
    {
        free((*element).data);
        free(element);
        element = NULL;
        return NULL;
    }
    (*element).next = list;
    memcpy((*element).data, value, data_size);
    return element;
}
size_t list_length(struct list *list)
{
    if (!list)
    {
        return 0;
    }
    size_t size = list_length((*list).next);
    return size + 1;
}
void list_destroy(struct list *list)
{
    while (list)
    {
        struct list *element = list;
        list = (*list).next;
        free((*element).data);
        free(element);
        element = NULL;
    }
    list = NULL;
}
