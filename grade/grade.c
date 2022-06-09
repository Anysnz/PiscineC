#include <stdio.h>

void grade(char q)
{
    switch (q)
    {
    case 'A':
        puts("Excellent\n");
        break;
    case 'B':
        puts("Good\n");
        break;
    case 'C':
        puts("Not so bad\n");
        break;
    case 'D':
        puts("Could be worse\n");
        break;
    case 'E':
        puts("No comment\n");
        break;
    case 'F':
        puts("Call a wild ACU\n");
        break;
    }
}
