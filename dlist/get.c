#include "dlist.h"
int dlist_get(struct dlist *list, size_t index)
{
    if ((*list).head)
    {
        struct dlist_item *dev = (*list).head;
        while (dev)
        {
            if (index != 0)
            {
                dev = (*dev).next;
                --index;
            }
            else
                return (*dev).data;
        }
    }
    return -1;
}
int init_avec_un(struct dlist *list, int element)
{
    struct dlist_item *elem = malloc(sizeof(struct dlist_item));
    (*elem).data = element;
    (*elem).prev = NULL;
    (*elem).next = NULL;
    list->size = 1;
    list->tail = elem;
    list->head = elem;
    return 1;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if ((*list).head)
    {
        if (element > -1 && index <= dlist_size(list))
        {
            size_t i = 1;
            struct dlist_item *elem = (*list).head;
            for (; elem; elem = (*elem).next)
            {
                if (index == 0 || index == dlist_size(list) || i == index)
                {
                    if (index == 0)
                    {
                        dlist_push_front(list, element);
                    }
                    if (index == dlist_size(list))
                    {
                        dlist_push_back(list, element);
                    }
                    if (i == index)
                    {
                        struct dlist_item *add =
                            malloc(sizeof(struct dlist_item));
                        (*add).prev = elem;
                        (*add).next = (*elem).next;
                        (*add).data = element;
                        (*(*add).next).prev = add;
                        (*elem).next = add;
                        (*list).size++;
                    }
                    return 1;
                }
                i++;
            }
        }
    }
    if (index == 0 && element >= 0)
    {
        dlist_push_front(list, element);
        return 1;
    }
    return -1;
}
int dlist_find(const struct dlist *list, int element)
{
    if ((*list).head)
    {
        size_t j = 0;
        struct dlist_item *tp = (*list).head;
        while (tp)
        {
            if ((*tp).data == element)
                return j;
            tp = (*tp).next;
            j++;
        }
    }
    return -1;
}
/*
int dlist_remove_at(struct dlist *list, size_t index)
{
    if ((*list).head != NULL)
    {
        struct dlist_item *pop = (*list).head;
        while (pop != NULL)
        {
            if (index == 0)
            {
                if ((*pop).next && (*pop).prev)
                {
                    (*(*pop).prev).next = (*pop).next;
                    (*(*pop).next).prev = (*pop).prev;
                }
                else if ((*pop).next && (!(*pop).prev))
                {
            (*list).head = (*pop).next;
                    (*(*pop).next).prev = NULL;
                }
                else if ((!(*pop).next) && (*pop).prev)
                {
                (*list).tail = (*pop).prev;
                    (*(*pop).prev).next = NULL;
                }
                else
                {
                    (*list).tail = NULL;
                    (*list).head = NULL;
                }
                int stock = (*pop).data;
                free(pop);
                (*list).size--;
                return stock;
            }
            index--;
            pop = (*pop).next;
        }
    }
    return -1;
}
*/
int dlist_remove_at(struct dlist *list, size_t index)
{
    struct dlist_item *pop = (*list).head;
    if (index >= (*list).size || !pop)
        return -1;
    while (index > 0)
    {
        pop = (*pop).next;
        --index;
    }
    if ((*pop).next && (*pop).prev)
    {
        (*(*pop).prev).next = (*pop).next;
        (*(*pop).next).prev = (*pop).prev;
    }
    else if ((*pop).next && (!(*pop).prev))
    {
        (*list).head = (*pop).next;
        (*(*pop).next).prev = NULL;
    }
    else if ((!(*pop).next) && (*pop).prev)
    {
        (*list).tail = (*pop).prev;
        (*(*pop).prev).next = NULL;
    }
    else
    {
        (*list).tail = NULL;
        (*list).head = NULL;
    }
    int stock = (*pop).data;
    free(pop);
    (*list).size--;
    return stock;
}
