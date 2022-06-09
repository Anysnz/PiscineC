#include <stdio.h>

void rac(int *n, int pre, int der)
{
    int k;
    int l;
    int pi;
    int tmp;
    if (pre < der)
    {
        pi = pre;
        k = pre;
        l = der;
        while (k < l)
        {
            while (n[k] <= n[pi] && k < der)
                k++;
            while (n[l] > n[pi])
                l--;
            if (k < l)
            {
                tmp = n[k];
                n[k] = n[l];
                n[l] = tmp;
            }
        }
        tmp = n[pi];
        n[pi] = n[l];
        n[l] = tmp;
        rac(n, pre, l - 1);
        rac(n, l + 1, der);
    }
}
void quicksort(int *tab, int len)
{
    rac(tab, 0, len - 1);
}
