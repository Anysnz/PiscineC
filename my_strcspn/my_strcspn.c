#include <stdio.h>

size_t my_strcspn(const char *s, const char *reject)
{
    const char *p = s;
    const char *i;
    while (*s)
    {
        for (i = reject; *i; i++)
        {
            if (*s == *i)
                break;
        }
        if (*i)
            break;
        s++;
    }
    return s - p;
}
