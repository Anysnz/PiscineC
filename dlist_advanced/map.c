#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    if (list->head)
    {
        struct dlist_item *map = (*list).head;
        while (map)
        {
            (*map).data *= (*map).data;
            map = (*map).next;
        }
    }
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *swap = NULL;
    if ((*list).head)
    {
        struct dlist_item *structure = (*list).head;
        while (structure)
        {
            swap = (*structure).next;
            (*structure).next = (*structure).prev;
            (*structure).prev = swap;
            structure = swap;
        }
    }
    swap = (*list).head;
    (*list).head = (*list).tail;
    (*list).tail = swap;
}
struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if ((*list).head)
    {
        struct dlist_item *pop = (*list).head;
        for (; pop; pop = (*pop).next)
        {
            if (index == 0)
            {
                (*list).tail = (*pop).prev;
                (*(*pop).prev).next = NULL;
                (*pop).prev = NULL;
                struct dlist *back = malloc(sizeof(struct dlist));
                (*back).head = pop;
                (*back).tail = (*list).tail;
                (*back).size = dlist_size(back);
                (*list).size = dlist_size(list);
                return back;
            }
            index--;
        }
    }
    return NULL;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if ((*list2).head)
    {
        struct dlist_item *num = NULL;
        struct dlist_item *most = (*list2).head;
        while (most)
        {
            dlist_push_back(list1, (*most).data);
            num = (*most).next;
            most = num;
        }
        (*list2).size = 0;
        free(num);
        num = NULL;
        dlist_clear(list2);
    }
}
