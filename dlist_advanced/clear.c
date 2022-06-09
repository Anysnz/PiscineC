#include "dlist.h"

void dlist_clear(struct dlist *list)
{
    if ((*list).head)
    {
        struct dlist_item *pop = NULL;
        struct dlist_item *leak = (*list).head;
        while (leak)
        {
            pop = (*leak).next;
            free(leak);
            leak = NULL;
            leak = pop;
        }
        free(pop);
        pop = NULL;
        (*list).tail = NULL;
        (*list).head = NULL;
        (*list).size = 0;
    }
}
void dlist_shift(struct dlist *list, int offset)
{
    if (offset > 0)
    {
        int i = 0;
        while (i < offset)
        {
            int swap = (*(*list).tail).data;
            struct dlist_item *shi = (*list).tail;
            while (shi)
            {
                if ((*shi).prev != NULL)
                    (*shi).data = (*(*shi).prev).data;
                else
                    (*shi).data = swap;
                shi = (*shi).prev;
            }
            i++;
        }
    }
    else if (offset <= 0)
    {
        int j = 0;
        while (j > offset)
        {
            int change = (*(*list).head).data;
            struct dlist_item *shiftfct = (*list).head;
            while (shiftfct)
            {
                if ((*shiftfct).next != NULL)
                    (*shiftfct).data = (*(*shiftfct).next).data;
                else
                    (*shiftfct).data = change;
                shiftfct = (*shiftfct).next;
            }
            j--;
        }
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    dlist_push_front(list, element);
    dlist_sort(list);
    return 1;
}
int dlist_remove_eq(struct dlist *list, int element)
{
    if ((*list).head != NULL)
    {
        struct dlist_item *pop = (*list).head;
        for (; pop; pop = (*pop).next)
        {
            if ((*pop).data == element)
            {
                (*(*pop).prev).next = (*pop).next;
                (*(*pop).next).prev = (*pop).prev;
                (*list).size--;
                free(pop);
                pop = NULL;
                return 1;
            }
        }
    }
    return 0;
}
