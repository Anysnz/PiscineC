#include <stdlib.h>

char *my_strncpy(char *dest, const char *source, size_t num)
{
    size_t i = 0;
    while (source[i] != '\0' && i < num)
    {
        dest[i] = source[i];
        i++;
    }
    while (i < num)
    {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
