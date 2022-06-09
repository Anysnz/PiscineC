#include <stdio.h>

unsigned int number_digits_rec(unsigned int n)
{
    int nbr = 0;
    unsigned int i = 1;
    if (n == 0 || n == 1)
        return 1;
    while (i < n)
    {
        i = 10 * i;
        nbr++;
    }
    return nbr;
}
