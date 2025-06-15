
#include <windows.h>
#include <stdio.h>

// External variables and functions referenced in the code
extern BYTE byte_4011E7;
extern CHAR Buffer[256];
extern CHAR Text[256];
extern CHAR Caption[256];
extern CHAR String[256];
extern BYTE byte_401040;
extern CHAR byte_401004[256];
extern CHAR byte_401169[256];
extern DWORD dword_401000;
extern CHAR byte_401140[256];
extern CHAR aUsernameCannot[256];
extern CHAR aUsernameMustHa[256];
extern CHAR byte_401119[256];
extern DWORD dword_401055;
extern CHAR aI[256];
extern DWORD dword_40121C;
extern CHAR byte_40119D[256];
extern CHAR byte_4011C4[256];
extern WORD word_40106E;
extern WORD word_40106A;

// External function declarations
extern void xor_decrypt_string(CHAR* str);
extern void is_beeing_debug(void);
extern void anti_debug_code_patcher(CHAR* str);
extern INT_PTR CALLBACK DialogFunc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

INT_PTR CALLBACK username_password_checker(HWND hDlg, UINT arg_4, WPARAM arg_8, LPARAM lParam)
{
    DWORD nSize;
    DWORD ecx, eax, ebx, edi, esi, edx;
    BYTE al, bl, dl;
    BYTE cl;
    
    // Compare arg_4 with 0x110 (WM_INITDIALOG)
    if (arg_4 == 0x110) {
        ecx = 0x32; // '2'
        if (byte_4011E7 == 1) {
            goto loc_402107;
        }
        
        // Call GetComputerNameA
        nSize = sizeof(Buffer);
        GetComputerNameA(Buffer, &nSize);
        
        // Check if Buffer starts with "NI"
        if (*(DWORD*)Buffer != 0x494E) {
            goto loc_40217E;
        }
        
        // Check word_40106E == 0x4552 ("RE")
        if (word_40106E != 0x4552) {
            goto loc_40217E;
        }
        
        // Check word_40106A == 0x5448 ("TH")
        if (word_40106A != 0x5448) {
            goto loc_40217E;
        }
        
        // Decrypt and show message
        xor_decrypt_string(Text);
        MessageBoxA(0, Text, Caption, 0x1040);
        xor_decrypt_string(Text);
        is_beeing_debug();
        goto loc_402107;
        
loc_40217E:
        xor_decrypt_string(byte_401169);
        MessageBoxA(0, byte_401169, Buffer, 0x1040);
        xor_decrypt_string(byte_401169);
        goto loc_402171;
    }
    
    // Compare arg_4 with 0x111 (WM_COMMAND)
    if (arg_4 == 0x111) {
        // Check different command IDs
        if (arg_8 == 0xC9) {
            goto loc_40210E;
        }
        if (arg_8 == 0xCA) {
            goto loc_402171;
        }
        if (arg_8 == 0xCB) {
            goto loc_4021AB;
        }
        goto loc_402107;
        
loc_40210E:
        // Get dialog item text for username
        eax = GetDlgItemTextA(hDlg, 0x12D, String, 0x15);
        
        // Check username length
        if (eax < 4) {
            goto loc_4021FD;
        }
        if (eax > 0xF) {
            goto loc_4021FD;
        }
        
        byte_401040 = (BYTE)eax;
        al = String[0];
        
        // Check if first character is space
        if (al == 0x20) { // ' '
            goto loc_4021CF;
        }
        
        is_beeing_debug();
        
        // Get dialog item text for password
        eax = GetDlgItemTextA(hDlg, 0x12E, byte_401004, 0x15);
        
        if (eax > 0x10) {
            goto loc_40234B;
        }
        goto loc_402269;
        
loc_4021CF:
        xor_decrypt_string(byte_401140);
        SetDlgItemTextA(hDlg, 0x12E, byte_401140, 0x20);
        xor_decrypt_string(byte_401140);
        goto loc_402107;
        
loc_4021FD:
        if (eax == 0) {
            goto loc_40223B;
        }
        if (eax < 6) {
            goto loc_402221;
        }
        
        SetDlgItemTextA(hDlg, 0x12E, aUsernameCannot, 0x20);
        goto loc_402107;
        
loc_402221:
        SetDlgItemTextA(hDlg, 0x12E, aUsernameMustHa, 0x20);
        goto loc_402107;
        
loc_40223B:
        xor_decrypt_string(byte_401119);
        SetDlgItemTextA(hDlg, 0x12E, byte_401119, 0x20);
        xor_decrypt_string(byte_401119);
        goto loc_402107;
        
loc_402269:
        // Initialize variables
        ecx = 0;
        eax = 0;
        ebx = 0;
        edi = 0;
        esi = 0;
        edx = eax;
        edi = (DWORD)&dword_401055;
        esi = 1;
        bl = byte_401040;
        
loc_402285:
        // Username processing loop
        al = String[ecx];
        eax = al * esi;
        eax = eax + esi;
        eax = eax << 0xDE;
        eax = eax >> 0xAD;
        eax = eax ^ esi;
        al = (BYTE)eax + 0x35; // '5'
        *((BYTE*)edi) = al;
        edx = edx + eax;
        edi++;
        ecx++;
        esi++;
        cl = (BYTE)ecx;
        if (cl != bl) {
            goto loc_402285;
        }
        
        // Calculate hash
        edx = edx * dword_401055;
        edx = ~edx;
        
        // Format string
        wsprintfA((CHAR*)(&dword_40121C + 1), aI, edx);
        
        // Decrypt comparison string
        xor_decrypt_string((CHAR*)(0x40121D));
        anti_debug_code_patcher((CHAR*)(0x40121D));
        
        ecx = 0;
        
loc_4022D8:
        // Password comparison loop
        al = byte_401004[ecx];
        dl = *((BYTE*)(ecx + 0x40121D));
        dl = dl ^ 0xBE;
        if (al != dl) {
            goto loc_40234B;
        }
        ecx++;
        if (byte_401004[ecx] != 0) {
            goto loc_4022D8;
        }
        if (*((BYTE*)(ecx + 0x40121D)) != 0) {
            goto loc_4022D8;
        }
        if (ecx <= 5) {
            goto loc_4022D8;
        }
        
        // Success case
        wsprintfA((CHAR*)(&dword_40121C + 1), aI, 0); // Push esp equivalent
        xor_decrypt_string(byte_40119D);
        is_beeing_debug();
        MessageBoxA(0, byte_40119D, Buffer, 0x1040);
        xor_decrypt_string(byte_40119D);
        return 1;
        
loc_40234B:
        // Failure case
        xor_decrypt_string(byte_4011C4);
        SetDlgItemTextA(hDlg, 0x12E, byte_4011C4, 0x20);
        xor_decrypt_string(byte_4011C4);
        return 1;
        
loc_4021AB:
        // Create new dialog
        dword_401000 = (DWORD)GetModuleHandleA(NULL);
        DialogBoxParamA((HINSTANCE)dword_401000, MAKEINTRESOURCE(7), 0, DialogFunc, 0);
        goto loc_402107;
        
loc_402171:
        // Close dialog
        EndDialog(hDlg, 0);
        goto loc_402107;
    }
    
    // Compare arg_4 with 0x10 (WM_CLOSE)
    if (arg_4 == 0x10) {
        EndDialog(hDlg, 0);
    }
    
loc_402107:
    // Function cleanup and return
    return 0;
}

