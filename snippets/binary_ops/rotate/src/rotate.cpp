#include <stdint.h>   // for uint32_t

uint32_t rotl32a(uint32_t x, uint32_t n)
{
    return (x<<n) | (x>>(32-n));
}

uint32_t rotr32a(uint32_t x, uint32_t n)
{
    return (x>>n) | (x<<(32-n));
}
