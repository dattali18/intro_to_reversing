#include <stdint.h>

void anti_debug_code_patcher(uint32_t* arg_0) {
    uint32_t ecx = 0;
    uint32_t edi = 0;
    uint8_t* ptr = (uint8_t*)arg_0;

    while (1) {
        uint8_t al = ptr[ecx];
        if (al == 0) {
            *((uint16_t*)(ptr + ecx + 0x40121D)) = 0xF293;
            ecx += 2;
            *((uint16_t*)(ptr + ecx + 0x40121D)) = 0xFBFB;
            ecx += 2;
            *((uint8_t*)(ptr + ecx + 0x40121D)) = 0xEA;
            edi = 0x3A666B;
            return;
        }
        if (al <= 0x8E) {
            // Do nothing, continue loop
        } else if (al == 0x8F) {
            // Do nothing, continue loop
        } else if (al == 0x93) {
            *((uint8_t*)(ptr + ecx + 0x40121D)) = 0x8D;
            ecx++;
            continue;
        } else {
            *((uint8_t*)(ptr + 0x40121D + ecx)) -= 1;
            ecx++;
        }
    }
}