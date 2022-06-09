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
size_t my_strcspn(const char *s, const char *r)
{
    size_t i = 0;
    if (s == NULL || r == NULL)
    {
        return 0;
    }
    while (s[i] != '\0')
    {
        if (my_strstr(r, s[i]))
            break;
        i++;
    }
    return i;
}
size_t my_strspn(const char *s, const char *a)
{
    size_t i = 0;
    if (s == NULL || a == NULL)
        return 0;
    while (s[i] != '\0' && my_strstr(a, s[i]))
        i++;
    return i;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (!str)
        str = *saveptr;
    if (*str == '\0')
        return NULL;
    str += my_strspn(str, delim);
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    char *end = str + my_strcspn(str, delim);
    if (*end == '\0')
    {
        *saveptr = end;
        return str;
    }
    *end = '\0';
    *saveptr = end + 1;
    return str;
}
