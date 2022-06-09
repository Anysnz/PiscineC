#include <stddef.h>
#include <stdio.h>

int my_atoi(const char *str)
{
    int nbr = 0;
    int i = 0;
    int negatif = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '-')
    {
        i++;
        negatif = 1;
    }
    else if (str[i] == '+')
    {
        i++;
    }
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            nbr = nbr * 10 + (str[i] - '0');
            i++;
        }
        else
            return 0;
    }
    if (negatif)
        return -nbr;
    return nbr;
}
