#include <stdio.h>

#include "heap.h"

void add(struct heap *heap, int val)
{
    int taille;
    int pere;
    taille = (*heap).size;
    (*heap).size++;
    (*heap).array[taille] = val;
    pere = (taille - 1) / 2;
    while (taille != 0 && (*heap).array[pere] < val)
    {
        (*heap).array[taille] = (*heap).array[pere];
        (*heap).array[pere] = val;
        taille = pere;
        pere = (taille - 1) / 2;
    }
}
