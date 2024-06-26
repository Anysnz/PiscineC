#include <stdio.h>

size_t my_strlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int my_strcmp(const char *s1, const char *s2)
{
    int i;
    for (i = 0; s1[i] && s2[i]; ++i)
    {
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
            continue;
        else
            break;
    }
    if (s1[i] == s2[i])
        return 0;
    if ((s1[i] | 32) < (s2[i] | 32))
        return -1;
    return 1;
}
