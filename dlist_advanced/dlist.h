#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct dlist_item
{
    int data;
    struct dlist_item *next;
    struct dlist_item *prev;
};

struct dlist
{
    size_t size;
    struct dlist_item *head;
    struct dlist_item *tail;
};
// Threshold 1.adv
struct dlist *dlist_init(void);
void dlist_print(const struct dlist *list);
int dlist_push_front(struct dlist *list, int element);
int dlist_push_back(struct dlist *list, int element);
size_t dlist_size(const struct dlist *list);

// Threshold 2.adv
int dlist_get(struct dlist *list, size_t index);
int dlist_insert_at(struct dlist *list, int element, size_t index);
int dlist_find(const struct dlist *list, int element);
int dlist_remove_at(struct dlist *list, size_t index);

// Threshold 3.adv
void dlist_map_square(struct dlist *list);
void dlist_reverse(struct dlist *list);
struct dlist *dlist_split_at(struct dlist *list, size_t index);
void dlist_concat(struct dlist *list1, struct dlist *list2);

// Threshold 4.adv
void dlist_clear(struct dlist *list);
void dlist_shift(struct dlist *list, int offset);
int dlist_add_sort(struct dlist *list, int element);
int dlist_remove_eq(struct dlist *list, int element);
struct dlist *dlist_copy(const struct dlist *list);

// Threshold 5.adv
void dlist_sort(struct dlist *list);
void dlist_merge(struct dlist *list1, struct dlist *list2);

// Threshold 6.adv
unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2);

#endif // DLIST_H
