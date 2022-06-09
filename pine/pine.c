#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
    {
        return 1;
    }
    else
    {
        for (unsigned int i = 1; i <= n; i++)
        {
            int b = 0;
            int c = 0;
            int w = n - i;
            int s = 1 + 2 * (i - 1);
            while (c < w)
            {
                putchar(' ');
                c++;
            }
            while (b < s)
            {
                putchar('*');
                b++;
            }
            putchar('\n');
        }
        for (unsigned int i = 1; i <= n / 2; i++)
        {
            int c = 0;
            int w = n - 1;
            while (c < w)
            {
                putchar(' ');
                c++;
            }
            putchar('*');
            putchar('\n');
        }
    }
    return 0;
}
