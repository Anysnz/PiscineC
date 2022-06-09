#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 0)
    {
        return 0;
    }
    for (int j = 1; j < argc; j++)
    {
        if ((j % 2) == 0)
        {
            puts("Hello Odd!");
        }
        else
            puts("Hello Even!");
        puts(argv[j]);
    }
}
