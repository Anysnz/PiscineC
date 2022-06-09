#include "dlist.h"

struct dlist *dlist_copy(const struct dlist *list)
{
    struct dlist *obj = dlist_init();
    if ((*list).head != NULL)
    {
        struct dlist_item *cpy = (*list).head;
        for (; cpy; cpy = (*cpy).next)
        {
            dlist_push_back(obj, (*cpy).data);
        }
    }
    return obj;
}
void dlist_sort(struct dlist *list)
{
    if ((*list).head != NULL)
    {
        struct dlist_item *obj = (*list).head;
        while ((*obj).next)
        {
            obj = (*obj).next;
            struct dlist_item *tri = (*list).head;
            for (; (*tri).next; tri = (*tri).next)
            {
                if ((*tri).data > (*(*tri).next).data)
                {
                    int swap = (*(*tri).next).data;
                    (*(*tri).next).data = (*tri).data;
                    (*tri).data = swap;
                }
            }
            tri = (*list).head;
        }
    }
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    dlist_concat(list1, list2);
    dlist_sort(list1);
}

unsigned int exch(unsigned int p, unsigned int d, unsigned int r)
{
    if (p <= d && p <= r)
        return p;
    if (d <= p && d <= r)
        return d;
    return r;
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    if (list1 == list2)
        return 0;
    size_t p = dlist_size(list1);
    size_t m = dlist_size(list2);
    int *lis = malloc(sizeof(int) * (p + 1) * (m + 1));
    int spp = 0;
    for (size_t a = 0; a <= p; a++)
        lis[a * (m + 1)] = a;
    for (size_t z = 0; z <= m; z++)
        lis[z] = z;
    for (size_t e = 1; e <= p; e++)
    {
        for (size_t r = 1; r <= m; r++)
        {
            int mono = dlist_get(list1, e - 1);
            if (mono != dlist_get(list2, r - 1))
                spp = 1;
            else
                spp = 0;
            lis[e * (m + 1) + r] = exch(lis[(e - 1) * (m + 1) + r] + 1,
                                        lis[e * (m + 1) + r - 1] + 1,
                                        lis[(e - 1) * (m + 1) + r - 1] + spp);
        }
    }
    int res = lis[(p) * (m + 1) + m];
    free(lis);
    return res;
}
