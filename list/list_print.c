#include <stdio.h>

#include "list.h"

void list_print(struct list *l)
{
    while (l != NULL)
    {
        if ((*l).next == NULL)
            printf("%d", (*l).data);
        else
            printf("%d ", (*l).data);

        l = (*l).next;
    }
    printf("\n");
}
