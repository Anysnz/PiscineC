#include <stddef.h>
#include <stdio.h>

#include "gtree.h"

void gtree_print(struct gtree *root)
{
    if (root != NULL)
    {
        fprintf(stdout, "%c", (*root).data);
        gtree_print((*root).children);
        gtree_print((*root).siblings);
    }
}

void gtree_print_preorder(struct gtree *root)
{
    if (root != NULL)
    {
        fprintf(stdout, "%c", (*root).data);
        gtree_print((*root).children);
        gtree_print((*root).siblings);
        fprintf(stdout, "\n");
    }
}
