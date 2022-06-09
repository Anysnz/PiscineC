#include "list.h"

#include <stdlib.h>

struct list *list_add(struct list *l, int e)
{
    struct list *element = malloc(sizeof(struct list));
    (*element).data = e;
    if (l == NULL)
    {
        (*element).next = NULL;
    }
    else
        (*element).next = l;
    return element;
}
struct list *list_find(struct list *l, int e)
{
    struct list *element = l;
    while (element != NULL)
    {
        if ((*element).data == e)
            return element;
        element = (*element).next;
    }
    return NULL;
}

struct list *list_remove(struct list *l, int e)
{
    if (l == NULL)
    {
        return NULL;
    }
    struct list *k = l;
    if ((*k).data == e)
    {
        l = (*l).next;
        free(k);
        return l;
    }
    struct list *o = (*l).next;
    while (o != NULL)
    {
        if ((*o).data == e)
        {
            (*k).next = (*o).next;
            free(o);
            return l;
        }
        o = (*o).next;
        k = (*k).next;
    }
    return l;
}

struct list *list_reverse_sorted_add(struct list *l, int e)
{
    if (!l || e > (*l).data)
        return list_add(l, e);
    struct list *tmp = l;
    struct list *g = malloc(sizeof(struct list));
    if (!g)
        return l;
    (*g).data = e;
    (*g).next = NULL;
    while (l)
    {
        if ((*l).next)
        {
            if (e >= (*(*l).next).data)
            {
                (*g).next = (*l).next;
                (*l).next = g;
                break;
            }
        }
        else
        {
            (*l).next = g;
            break;
        }
        l = (*l).next;
    }
    return tmp;
}
struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    struct list *elem = l;
    while (elem != NULL)
    {
        if (predicate(elem->data))
        {
            int s = elem->data;
            elem = elem->next;
            l = list_remove(l, s);
        }
        else
            elem = (*elem).next;
    }
    return l;
}
/*
    struct list *tmp = l;
    struct list *g = l;
    if (l == NULL || e > (*l).data)
        return list_add(l, e);
    while (tmp != NULL)
    {
        if (e >= (*tmp).data)
        {
            l = list_add(l, e);
            return l;
        }
        g = tmp;
        tmp = (*tmp).next;
    }
    struct list *new = malloc(sizeof(struct list));
    (*new).data = e;
    (*new).next = NULL;
    (*g).next = new;
    return l;

*/
