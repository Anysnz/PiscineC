#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
char *reallocbis(char *string, size_t size)
{
    string = realloc(string, size);
    if (string == NULL)
        return NULL;
    return string;
}
char *string_replace(char c, const char *str, const char *pattern)
{
    if (str == NULL)
        return NULL;
    int pos_newstr = 1;
    char *mot = malloc(sizeof(char));
    if (mot == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c && pattern != NULL)
        {
            int j = 0;
            while (pattern[j] != '\0')
            {
                mot = reallocbis(mot, sizeof(char) + pos_newstr);
                mot[pos_newstr - 1] = pattern[j];
                pos_newstr++;
                j++;
            }
        }
        else if (str[i] != c)
        {
            mot = reallocbis(mot, sizeof(char) + pos_newstr);
            mot[pos_newstr - 1] = str[i];
            pos_newstr++;
        }
    }
    mot = reallocbis(mot, sizeof(char) + pos_newstr);
    mot[pos_newstr - 1] = '\0';
    return mot;
}
