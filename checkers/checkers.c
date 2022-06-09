#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;
    while (i <= 9)
    {
        if (i % 2 == 0)
        {
            int k = 0;
            while (k < 5)
            {
                putchar('O');
                putchar('X');
                k++;
            }
        }
        if (i % 2 == 1)
        {
            int j = 0;
            while (j < 5)
            {
                putchar('X');
                putchar('O');
                j++;
            }
        }
        i++;
        putchar('\n');
    }
}
