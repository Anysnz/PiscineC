#include <stdio.h>
#include <stdlib.h>

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    char *don = data;
    size_t i = 0;
    const char *keyo = key;
    while (i < data_len)
    {
        don[i] = don[i] ^ keyo[i % key_len];
        i++;
    }
}
