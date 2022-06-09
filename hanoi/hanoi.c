#include <stdio.h>

void hanoi_rec(unsigned n, int x, int y, int z)
{
    if (n == 1)
    {
        putchar(x + '0');
        putchar('-');
        putchar('>');
        putchar(y + '0');
        putchar('\n');
    }
    else
    {
        hanoi_rec(n - 1, x, z, y);
        putchar(x + '0');
        putchar('-');
        putchar('>');
        putchar(y + '0');
        putchar('\n');
        hanoi_rec(n - 1, z, y, x);
    }
}
void hanoi(unsigned n)
{
    hanoi_rec(n, 1, 3, 2);
}
