#include <stdio.h>

void my_rol_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    size_t tmp = 0;
    if (data_len == 0)
        return;
    unsigned char *bump = data;
    const unsigned char *clé = key;
    size_t a;
    size_t z = data_len - 1;
    if (data_len % key_len == 0)
    {
        a = key_len - 1;
    }
    else
    {
        a = data_len % key_len - 1;
    }
    while (z != 0)
    {
        bump[z] = bump[z] + clé[a] + tmp;
        if (clé[a] >= bump[z])
        {
            tmp = 1;
        }
        else
        {
            tmp = 0;
        }
        if (a != 0)
        {
            a--;
        }
        else
        {
            a = key_len - 1;
        }
        z--;
    }
    bump[0] = bump[0] + clé[0] + tmp;
}
