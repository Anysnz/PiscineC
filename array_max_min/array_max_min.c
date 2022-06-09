#include <stdio.h>

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    int maxi = 0;
    int mini = 0;
    if (len != 0 && tab != NULL)
    {
        for (size_t i = 1; i < len; i++)
        {
            if (tab[maxi] < tab[i])
            {
                maxi = i;
            }
        }
        for (size_t k = 1; k < len; k++)
        {
            if (tab[mini] > tab[k])
            {
                mini = k;
            }
        }
        *min = tab[mini];
        *max = tab[maxi];
    }
}
