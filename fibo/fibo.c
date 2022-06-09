#include <stdio.h>

unsigned long fibonacci(unsigned long n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    else
    {
        return (fibonacci(n - 2) + fibonacci(n - 1));
    }
}
