format PE console
entry start

include 'win32a.inc'

section '.data' data readable writeable
    hConsole dd 0                        ; Handle to the console
    csbi db 22 dup(0)                    ; Console screen buffer info structure (22 bytes)
    charsWritten dd 0                    ; Number of characters written
    consoleSize dd 0                     ; Total size of the console screen buffer


section '.text' readable executable
start:
    ; Get handle to the console's standard output
    invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov [hConsole], eax

    ; Check if the handle is invalid
    cmp eax, INVALID_HANDLE_VALUE
    je exit

    ; Get console screen buffer information
    invoke GetConsoleScreenBufferInfo, [hConsole], csbi
    test eax, eax
    jz exit

    ; Calculate the size of the console buffer (width * height)
    movzx eax, word [csbi + 4]           ; Zero-extend csbi.dwSize.Y (offset 4, 2 bytes) into eax
    movzx ecx, word [csbi + 2]           ; Zero-extend csbi.dwSize.X (offset 2, 2 bytes) into ecx
    imul eax, ecx                        ; Multiply eax (height) by ecx (width)
    mov [consoleSize], eax               ; Store the result in consoleSize

    ; Fill the console with spaces
    mov eax, [consoleSize]               ; Total console size
    xor ecx, ecx                         ; Start at top-left corner (0, 0)
    lea edx, [csbi + 10]                 ; Address of csbi.dwCursorPosition
    invoke FillConsoleOutputCharacter, [hConsole], ' ', eax, edx, charsWritten

    ; Reset the console attributes
    mov eax, [consoleSize]               ; Total console size
    mov ecx, dword [csbi + 8]            ; csbi.wAttributes (offset 8)
    lea edx, [csbi + 10]                 ; Address of csbi.dwCursorPosition
    invoke FillConsoleOutputAttribute, [hConsole], ecx, eax, edx, charsWritten

    ; Move the cursor back to the top-left corner
    xor eax, eax
    mov word [csbi + 10], ax             ; csbi.dwCursorPosition.X (offset 10, 2 bytes)
    mov word [csbi + 12], ax             ; csbi.dwCursorPosition.Y (offset 12, 2 bytes)
    lea edx, [csbi + 10]                 ; Address of csbi.dwCursorPosition
    invoke SetConsoleCursorPosition, [hConsole], edx

exit:

    ; Exit the program
    invoke ExitProcess, 0

section '.idata' import data readable writeable
    library kernel32, 'kernel32.dll'

    import kernel32, \
           GetStdHandle, 'GetStdHandle', \
           GetConsoleScreenBufferInfo, 'GetConsoleScreenBufferInfo', \
           FillConsoleOutputCharacter, 'FillConsoleOutputCharacterA', \
           FillConsoleOutputAttribute, 'FillConsoleOutputAttribute', \
           SetConsoleCursorPosition, 'SetConsoleCursorPosition', \
           ExitProcess, 'ExitProcess'