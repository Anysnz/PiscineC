#inlude < stdio.h>

void insert_sort(int *tab, unsigned count)
{
    unsigned i;
    int key, j;
    for (i = 1; i < count; i++)
    {
        key = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > key)
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = key;
    }
}
void insert_sort_cmp(int *tab, unsigned count, int (*cmp)(int a, int b))
{
    unsigned i;
    int key, j;
    for (i = 1; i < count; i++)
    {
        key = tab[i];
        j = i - 1;
        while (j >= 0 && cmp(tab[j], key) == 1)
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = key;

        unsigned long cmp_count;

        int increasing(int a, int b)
        {
            ++cmp_count;
            if (a < b)
                return -1;
            return a > b;
        }
        void insertion_sort(void **array, f_cmp comp)
        {}
        typedef int (*f_cmp)(const void *, const void *)
        {
            int a;
            int b;
        }
        f_cmp;
