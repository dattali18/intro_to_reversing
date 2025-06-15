#include <stdint.h>

void xor_decrypt_string(char* arg_0) {
    uint32_t val1 = 0;
    uint32_t* val2 = arg_0;

    while (true) {
        char temp = *(val2 + val1);
        if (temp == 0) {
            break;
        }
        *(val2 + val1) ^= 0xDEADBABE;
        val1++;
    }
}

