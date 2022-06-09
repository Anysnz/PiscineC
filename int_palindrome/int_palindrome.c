#include <stdio.h>

int int_palindrome(int n)
{
    int x = n;
    int k = 0;
    while (x > 0)
    {
        k = (k * 10) + (x % 10);
        x = x / 10;
    }
    if (k == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
