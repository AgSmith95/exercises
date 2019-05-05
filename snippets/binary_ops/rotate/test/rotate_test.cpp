#include <stdint.h>   // for uint32_t
#include <assert.h>
#include "rotate.h"

int main() {
    assert(rotl32a(0x80000000, 1) == 0x00000001);
    assert(rotl32a(0x80000001, 1) == 0x00000003);

    assert(rotr32a(0x00000001, 1) == 0x80000000);
    assert(rotr32a(0x00000003, 1) == 0x80000001);
}