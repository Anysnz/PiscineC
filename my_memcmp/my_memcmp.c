#include <stddef.h>
#include <stdio.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const char *s1o = s1;
    const char *s2o = s2;
    while (num > 0)
    {
        if (*s1o != *s2o)
            return (*s1o - *s2o);
        num--;
        s1o++;
        s2o++;
    }
    return 0;
}
