// xor function based on assembly
void xor_decrypt_string(char* str) {
    int i = 0;
    while (str[i] != 0) {
        // In assembly: xor eax, 0DEADBABEh but only mov [edi+ecx], al
        // This means only the lowest byte after XOR is stored
        str[i] = (str[i] ^ 0xBE); // 0xBE is lowest byte of 0xDEADBABE
        i++;
    }
}

char* generate_password(const char* username) {
    // Validate username length
    int username_len = strlen(username);
    if (username_len < 4 || username_len > 15) {
        return NULL;
    }
    
    // Check if username starts with space
    if (username[0] == ' ') {
        return NULL;
    }

    // Process username using exact assembly algorithm
    char transformed[16];
    uint32_t accumulator = 0;
    
    for (int i = 0; i < username_len; i++) {
        uint32_t counter = i + 1;
        uint32_t val = (uint8_t)username[i];
        
        // From assembly: imul eax, esi / add eax, esi
        val = val * counter + counter;
        
        // From assembly: shl eax, 0DEh / shr eax, 0ADh
        // These shift amounts are modulo 32 (register size)
        // 0xDE % 32 = 30, 0xAD % 32 = 13
        val = ((val << 30) >> 13) & 0xFFFFFFFF;
        
        // From assembly: xor eax, esi / add al, 35h
        val = val ^ counter;
        val = (val + 0x35) & 0xFF;
        
        transformed[i] = (uint8_t)val;
        accumulator += val;
    }
    
    // From assembly: imul edx, dword_401055 / not edx
    uint32_t hash = accumulator * transformed[0];
    hash = ~hash; // Bitwise NOT
    
    // Convert hash to string
    char buffer[64];
    sprintf(buffer, "%i", hash);
    
    // Create password copy
    char* password = strdup(buffer);
    if (!password) return NULL;
    
    // Apply XOR decryption
    xor_decrypt_string(password);
    
    return password;
}