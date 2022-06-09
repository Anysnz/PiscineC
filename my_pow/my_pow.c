#include <stdio.h>

int my_pow(int a, int b)
{
    int resultat = 1;
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a;
    }
    else
    {
        if (b % 2 == 0)
        {
            int moy = b / 2;
            for (int i = 0; i < moy; i++)
            {
                resultat = resultat * a * a;
            }
        }
        else if (b % 2 == 1)
        {
            int moy = b / 2;
            for (int i = 0; i < moy; i++)
            {
                resultat = resultat * a * a * a;
            }
        }
        return resultat;
    }
}
