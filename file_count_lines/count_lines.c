#include <stdio.h>

int count_lines(const char *file_in)
{
    FILE *file;
    int e = 0;
    int c = 0;
    file = fopen(file_in, "r");
    if (!file)
        return -1;
    c = fgetc(file);
    if (c)
        e++;
    while (c != -1)
    {
        c = fgetc(file);
        if (e == 1 && c == '\n' && fgetc(file) == -1)
            break;
        if (c == '\n')
            e++;
    }
    fclose(file);
    return e;
}
