#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *new = malloc(sizeof(struct dlist));
    if (!new)
        return NULL;
    (*new).size = 0;
    (*new).head = NULL;
    (*new).tail = NULL;
    return new;
}

void dlist_print(const struct dlist *list)
{
    if ((*list).head != NULL)
    {
        struct dlist_item *print = (*list).head;
        while (print != NULL)
        {
            printf("%d\n", (*print).data);
            print = (*print).next;
        }
        free(print);
    }
}
int dlist_push_front(struct dlist *list, int element)
{
    struct dlist_item *add = malloc(sizeof(struct dlist_item));
    (*add).data = element;
    (*add).next = (*list).head;
    (*add).prev = NULL;
    if (!(*list).tail)
        (*list).tail = add;
    if ((*list).head)
        (*(*list).head).prev = add;
    (*list).head = add;
    (*list).size++;
    return 1;
}

int dlist_push_back(struct dlist *list, int element)
{
    struct dlist_item *add = malloc(sizeof(struct dlist_item));
    (*add).data = element;
    (*add).prev = (*list).tail;
    (*add).next = NULL;
    if (!(*list).head)
        (*list).head = add;
    if ((*list).tail)
        (*(*list).tail).next = add;
    (*list).tail = add;
    (*list).size++;
    return 1;
}
size_t dlist_size(const struct dlist *list)
{
    size_t taille = 0;
    if ((*list).head)
    {
        struct dlist_item *dev = list->head;
        while (dev)
        {
            dev = dev->next;
            ++taille;
        }
    }
    return taille;
}
