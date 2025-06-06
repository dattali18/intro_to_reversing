#include <stdio.h>
#include <string.h>

void level_4_func() {
    char Str[16]; // 16 bytes for the string
    unsigned int Str1;
    
    printf("Wait... I have something on the tip of ...\n");

    while (1) {
        unsigned int eax = 1;
        if (eax == 0) {
            break;
        }

        printf(" %u", Str1);
        /// if the input is not an unsigned number
        if (scanf(" %u", &Str1) != 1) {
            printf("Error - bad input. Try again.\r\n");
            continue;
        }

        // Initialize Str with specific values
        // Str[0] = 0x20; // 63756C20h
        // Str[4] = 0x6B; // 21216Bh
        // Str[8] = 0x47; // 646F6F47h

        *(uint32_t *)&Str[0] = 0x63756C20;
        *(uint32_t *)&Str[4] = 0x0021216B;
        *(uint32_t *)&Str[8] = 0x646F6F47;
        // Good luck!

        size_t maxCount = strlen(Str);
        if (strncmp(Str, (char *)&Str1, maxCount) != 0) {
            printf("Wrong!\r\n");
            continue;
        }

        break; // Exit the loop if the input is correct
    }


}

