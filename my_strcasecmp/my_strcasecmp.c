#include <stdio.h>

int my_strcasecmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] <= '\0')
    {
        if (s1[i] != s2[i])
        {
            return 0;
        }
        else if (s1[i] == s2[i])
        {
            i++;
        }
    }
    return 1;
}
