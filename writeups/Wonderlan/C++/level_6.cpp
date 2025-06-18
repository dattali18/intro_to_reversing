
#include <cstdio>
#include <cstring>

// Function to transform the input string - first transformation
void level_6_transform_1(char* input_string) {
    char* current_char_ptr = input_string;
    
    // Iterate through each character until null terminator
    while (*current_char_ptr != '\0') {
        // Add 0x4E ('N') then XOR with 0xAA
        *current_char_ptr = ((*current_char_ptr + 0x4E) ^ 0xAA);
        current_char_ptr++;
    }
}

// Function to transform the input string - second transformation
void level_6_transform_2(char* input_string) {
    int string_length = strlen(input_string);
    
    // Get the lower 5 bits of the last character
    char previous_lower_5_bits = (input_string[string_length - 1]) & 0x1F;
    
    // Iterate through each character in the string
    for (int char_index = 0; char_index < string_length; char_index++) {
        // Get lower 5 bits of current character
        char current_lower_5_bits = input_string[char_index] & 0x1F;
        
        // Get upper 3 bits of current character (shift right by 5)
        char current_upper_3_bits = input_string[char_index] >> 5;
        
        // Combine: upper_3_bits + (previous_lower_5_bits * 8)
        input_string[char_index] = current_upper_3_bits + (previous_lower_5_bits * 8);
        
        // Update previous_lower_5_bits for next iteration
        previous_lower_5_bits = current_lower_5_bits;
    }
}

// Main level 6 function
void level_6() {
    char user_input_buffer[1028];  // 0x404 bytes as allocated in assembly
    const char* target_string;
    
    // Print greeting message
    printf("Hello! I'm the rabbit, and to get aroun...");
    
    // Infinite loop until correct answer
    while (true) {
        // Read user input from stdin
        fgets(user_input_buffer, 1023, stdin);  // 0x3FF = 1023 max characters
        
        // Remove newline character by setting the character at strlen position to null
        int input_length = strlen(user_input_buffer);
        user_input_buffer[input_length - 1] = '\0';
        
        // Apply first transformation
        level_6_transform_1(user_input_buffer);
        
        // Apply second transformation  
        level_6_transform_2(user_input_buffer);
        
        // Set target string to compare against
        target_string = "01 01 10 10";
        
        // Compare transformed input with target string
        if (strncmp(user_input_buffer, target_string, strlen(target_string)) == 0) {
            // Success case
            printf("Correct!\r\n");
            break;
        } else {
            // Failure case - continue loop
            printf("That's wrong.\r\n");
        }
    }
}

int main() {
    level_6();
}