#define _GNU_SOURCE

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int csv(const char *s)
{
    FILE *file = fopen(s, "r");
    if (!file)
    {
        return 1;
    }
    size_t tail = 4096;
    char *exp = NULL;
    int v = -65536;
    int tmp;
    while ((tmp = getline(&exp, &tail, file)) != -1)
    {
        char *rec = exp;
        char *arg;
        while ((arg = strtok_r(rec, ",", &rec)))
        {
            if (v < atoi(arg))
            {
                v = atoi(arg);
            }
        }
        printf("%d\n", v);
        v = -65536;
    }
    if (exp != NULL)
    {
        free(exp);
        exp = NULL;
    }
    fclose(file);
    return 0;
}
int main(int argc, char *argv[])
{
    if (argc > 2)
        return 1;
    return csv(argv[1]);
}
