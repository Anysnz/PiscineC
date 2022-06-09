#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "node.h"

void insert_sort(int *tab, int count)
{
    int key = 0;
    for (int i = 1; i < count; i++)
    {
        key = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > key)
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = key;
    }
}
void node_insert(int nod[], int *count, struct bst_node *branch)
{
    nod[*count] = (*branch).data;
    *count = *count + 1;
    if ((*branch).right)
        node_insert(nod, count, (*branch).right);
    if ((*branch).left)
        node_insert(nod, count, (*branch).left);
    else
        return;
}
int find_pair(struct bst_node *root, int k)
{
    if (root == NULL)
        return 0;
    int i = 0;
    int flr = 0;
    int count = 0;
    int *indx = &count;
    int *tmp = malloc(4096 * sizeof(int));
    if (tmp == NULL)
        return 0;
    node_insert(tmp, indx, root);
    insert_sort(tmp, count);
    while (i < count)
    {
        int local = tmp[i];
        for (int j = i; j < count; j++)
        {
            if (local + tmp[j] == k)
            {
                flr++;
                printf("%d ", local);
                printf("%d\n", tmp[j]);
            }
        }
        i++;
    }
    if (flr == 0)
        return 0;
    return 1;
}
