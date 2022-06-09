#include "gtree.h"

#include <stdio.h>
#include <stdlib.h>

#include "search.h"

struct gtree *gtree_create_node(char data)
{
    struct gtree *n = malloc(sizeof(struct gtree));
    if (!n)
        return NULL;
    (*n).data = data;
    (*n).children = NULL;
    (*n).siblings = NULL;
    return n;
}
int gtree_add_child(struct gtree *parent, struct gtree *child)
{
    if (!parent || !child)
        return 0;
    if ((*parent).children)
    {
        struct gtree *s = (*parent).children;
        while ((*s).siblings)
            s = (*s).siblings;
        (*s).siblings = child;
    }
    else
        (*parent).children = child;
    return 1;
}
struct gtree *gtree_search_node(struct gtree *root, char data)
{
    struct gtree *t = NULL;
    if (!root)
        return NULL;
    if ((*root).data == data)
        return root;
    if ((*root).children)
        t = gtree_search_node((*root).children, data);
    struct gtree *s = root;
    while (s && t == NULL)
    {
        t = gtree_search_node((*root).children, data);
        s = (*s).siblings;
    }
    return t;
}
void gtree_free(struct gtree *root)
{
    if (root != NULL)
    {
        gtree_free((*root).children);
        gtree_free((*root).siblings);
        free(root);
        root = NULL;
    }
}
struct gtree *gtree_search_sibling(struct gtree *root, char data)
{
    struct gtree *t = NULL;
    if (!root)
        return NULL;
    if ((*root).children)
    {
        if ((*(*root).children).data == data)
            return root;
        t = gtree_search_sibling((*root).children, data);
    }
    if ((*root).siblings)
    {
        struct gtree *s = root;
        while (s && t == NULL)
        {
            if ((*(*s).siblings).data == data)
            {
                return s;
            }
            t = gtree_search_sibling((*s).siblings, data);
            s = (*s).siblings;
        }
    }
    return t;
}
int gtree_del_node(struct gtree *root, char data)
{
    if ((*root).data == data)
        return -1;
    struct gtree *supr_node = gtree_search_node(root, data);
    struct gtree *parent_node = gtree_search_sibling(root, data);
    if (supr_node)
    {
        (*parent_node).siblings = (*supr_node).siblings;
        gtree_free((*supr_node).children);
        free(supr_node);
    }
    else
        return 0;
    return 1;
}
