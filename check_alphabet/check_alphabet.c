#include <stdio.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL)
    {
        return 1;
    }
    for (int i = 0; alphabet[i] != '\0'; i++)
    {
        int j = 0;
        int f = 0;
        while (str[j] != '\0')
        {
            if (str[j] == alphabet[i])
            {
                f = 1;
                break;
            }
            j++;
        }
        if (f == 0)
        {
            return 0;
        }
    }
    return 1;
}
