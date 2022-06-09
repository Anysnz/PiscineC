#ifndef INT_VECTOR_MIN_H
#define INT_VECTOR_MIN_H

#define INT_VECTOR_LENGTH 64

#include <stddef.h>

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

int int_vector_min(struct int_vector vec);

#endif /* !INT_VECTOR_MIN_H */
