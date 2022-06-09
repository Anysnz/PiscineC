#include <stdio.h>

int my_strstr(const char *h, const char n)
{
    for (int i = 0; h[i] != '\0'; i++)
    {
        if (h[i] == n)
            return 1;
    }
    return 0;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    if (s == NULL || accept == NULL)
        return 0;
    while (s[i] != '\0' && my_strstr(accept, s[i]))
        i++;
    return i;
}
