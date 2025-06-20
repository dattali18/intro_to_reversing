#include <stdio.h>
#include <string.h>

void level_7_helper(char *str);

void level_7() {
    char user_input[1024];
    char *Str1;
    
    printf("You must walk through the Queen's mansi...\n");

    while (1) {
        fgets(user_input, sizeof(user_input), stdin);
        level_7_helper(user_input);
        
        Str1 = user_input;
        if (Str1 == NULL) {
            printf("You're lost. Try again.\r\n");
            continue;
        }

        if (strncmp(Str1, "The Queen's Room", strlen("The Queen's Room")) == 0) {
            printf("You've found the Queen!\r\n");
            break;
        } else {
            printf("You're lost. Try again.\r\n");
        }
    }
}

void level_7_helper(char *str) {
    char var_C;
    char* current;
    uint32_t var_4 = 0;

    // var_4 = (uint32_t)&off_404090; // Assuming off_404090 is defined elsewhere
    var_4 = 0x404090; // Assuming off_404090 is defined elsewhere
    current = str;

    while (1) {
        current++;
        if (*current == '\0') {
            break;
        }
        var_C = *current;
        if (var_C == 'L') {
            var_4 = var_4 + 4;
        } else if (var_C == 'R') {
            var_4 = var_4;
        } else {
            return; // not successful
        }
    }

