#include <stdio.h>

void my_strupcase(char *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
}
