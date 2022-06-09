#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int my_strlen(const char *a)
{
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    return i;
}
void sf(int a, char *new)
{
    if (a < 10)
    {
        sprintf(new, "0%d", a);
    }
    else
        sprintf(new, "%d", a);
}
void rec(struct tm *days, char *new, const char *format)
{
    int smlc = 0;
    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == 'M')
        {
            sf(days->tm_mon + 1, new + smlc);
            smlc = smlc + 2;
        }
        else if (format[i] == 'D')
        {
            sf(days->tm_mday, new + smlc);
            smlc = smlc + 2;
        }
        else if (format[i] == 'Y')
        {
            sf(days->tm_year + 1900, new + smlc);
            smlc = smlc + 4;
        }
        else
        {
            sprintf(new + smlc, "%c", format[i]);
            smlc = smlc + 1;
        }
    }
}
char *date_format(const char *format)
{
    int tmp = my_strlen(format);
    if ((tmp != 5)
        || (format[0] != 'M' && format[0] != 'Y' && format[0] != 'D'))
        return NULL;
    time_t day = time(NULL);
    struct tm *days = gmtime(&day);
    char *new = calloc(11, sizeof(char));
    rec(days, new, format);
    return new;
}
