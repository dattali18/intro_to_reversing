#include <cstdio>
#include <cstring>
#include <cctype>

// Simulated global lookup table (fill with your values)
int dword_740F4374[8] = {9, 5, 9, 6, 10, 9, 11, 7};

// The function returns 1 if password is valid, 0 otherwise
int check_password() {
    char input[16] = {0}; // allocate a bit more than 8 for safety
    int used[10] = {0};   // tracks if a digit 1-8 was used
    int vals[8] = {0};    // stores each digit (as int) in order
    int result = 1;

    // 1. Read input
    printf("Enter password: ");
    if (scanf("%8s", input) != 1) return 0;

    // 2. Check length
    if (strlen(input) != 8) return 0;

    // 3. Check all chars are digits 1-8 and no repeats
    for (int i = 0; i < 8; ++i) {
        if (!isdigit(input[i])) return 0;
        int digit = input[i] - '0';
        if (digit < 1 || digit > 8) return 0;
        if (used[digit]) return 0; // already used
        used[digit] = 1;
        vals[i] = digit - 1; // store 0-based for table lookup
    }

    // 4. Validate permutation order using lookup table
    for (int i = 1; i < 8; ++i) {
        int prev_val = dword_740F4374[vals[i-1]];
        int curr_val = dword_740F4374[vals[i]];
        if (curr_val >= prev_val) return 0; // must be strictly decreasing
    }

    return 1; // password is valid!
}