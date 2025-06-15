#include <stdio.h>
#include <windows.h>

void TlsCallback_0();
void xor_decrypt_string();
void anti_debug_code_patcher();
int is_beeing_debug();

char String[] = "YourStringHere"; // Replace with actual string
char byte_401040;
char byte_401004[10]; // Adjust size as needed
char byte_401221[256]; // Adjust size as needed
char byte_40119D[] = "Your message here"; // Replace with actual message
char Buffer[] = "Your caption here"; // Replace with actual caption
int dword_401055;
int dword_40121C;

void validate_username_password() {
    int ecx = 0;
    int eax = 0;
    int ebx = 0;
    int edi = 0;
    int esi = 1;
    int edx = eax;
    edi = dword_401055;
    char bl = byte_401040;
    eax = String[ecx];
    eax *= esi;
    eax += esi;
    eax <<= 22;
    eax >>= 66;
    eax ^= esi;
    TlsCallback_0();
    eax += 2;
    *((char*)edi) = (char)eax;
    edx += eax;
    edi++;
    ecx++;
    esi++;
    edx *= dword_401055;
    edx = ~edx;
    char aI[] = "%i";
    char* lpstr = (char*)(dword_40121C + 1);
    wsprintfA(lpstr, aI, edx);
    edx = 0; // Adjust as needed
    xor_decrypt_string();
    anti_debug_code_patcher();
    ecx = 0;
    char al = *(char*)(ebx + 0x401006);
    char dl = byte_401221[edx];
    dl ^= 0xBE;
    if (al != dl) {
        goto loc_40234B;
    }
    ecx++;
    if (byte_401004[ecx] != 0) {
        goto loc_4022D8;
    }
    if (ecx > 5) {
        goto loc_4022D8;
    }
    wsprintfA(lpstr, aI, edx);
    xor_decrypt_string();
    is_beeing_debug();
    *((char*)(ecx + 0x40121D)) = 0;
    __asm nop;
    __asm nop;
    __asm int 3; // Software interrupt to invoke the debugger
    MessageBoxA(0, byte_40119D, Buffer, 0);
    xor_decrypt_string();
}

