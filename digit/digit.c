#include <stdio.h>

unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
        return 0;
    else
    {
        for (int i = 1; i <= k - 1; i++)
            n = n / 10;
        n = n % 10;
        return n;
    }
}
