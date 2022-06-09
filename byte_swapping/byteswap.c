#include <stdint.h>

uint16_t my_htons(uint16_t n)
{
    return (n >> 8) | (n << 8);
}

uint32_t my_htonl(uint32_t n)
{
    return ((n >> 24) & 0xff) | ((n << 8) & 0xff0000) | ((n >> 8) & 0xff00)
        | ((n << 24) & 0xff000000);
}
