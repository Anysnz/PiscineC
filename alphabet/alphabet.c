#include <stdio.h>

int main(void)
{
    for (char i = 'a'; i <= 'z'; i++)
    {
        putchar(i);
        if (i != 'z')
            putchar(' ');
    }
    putchar('\n');
    return (0);
}
