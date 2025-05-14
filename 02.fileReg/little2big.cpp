#include <stdio.h>

using uint32_t = unsigned int;

uint32_t little2big(uint32_t x) {
    return ((x & 0x000000FF) << 24) | // Move byte 0 to byte 3
           ((x & 0x0000FF00) << 8)  | // Move byte 1 to byte 2
           ((x & 0x00FF0000) >> 8)  | // Move byte 2 to byte 1
           ((x & 0xFF000000) >> 24);   // Move byte 3 to byte 0
}
