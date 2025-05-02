; Daniel Attali 14/04/2025
include 'win32a.inc'

format PE console
entry start

section '.data' data readable writeable
    x dd 0

section '.text' code readable executable
start:
    jmp .exit_program

    STD_OUTPUT_HANDLE equ -11
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    call print_eax
    mov esi, eax 
    sub esp, 28                   ; Allocate space for CONSOLE_SCREEN_BUFFER_INFO (28 bytes)
    lea edi, [esp]                ; Use `edi` to point to the buffer
    push edi                      ; lpConsoleScreenBufferInfo
    push esi                      ; hConsoleOutput
    call [GetConsoleScreenBufferInfo]
    call print_eax

    movzx ecx, word [edi + 0x0C]  ; Screen width (dwSize.X)
    movzx edx, word [edi + 0x0E]  ; Screen height (dwSize.Y)
    imul ecx, edx                 ; Total cells = width * height
    mov ebx, ecx
    mov eax, ' '                  ; ASCII space character
    lea ecx, [esp + 28]           ; Pointer to store the number of characters written
    push ecx                      ; lpNumberOfCharsWritten
    push ebx                      ; nLength (total cells)
    push eax                      ; cCharacter (' ')
    push esi                      ; hConsoleOutput
    call [FillConsoleOutputCharacter]
    call print_eax
       xor eax, eax                  ; X = 0
    xor edx, edx                  ; Y = 0
    mov word [edi], 0             ; Set X in COORD structure
    mov word [edi + 2], 0         ; Set Y in COORD structure
    push edi                      ; Pointer to COORD structure
    push esi                      ; hConsoleOutput
    call [SetConsoleCursorPosition]
    add esp, 28
.exit_program:
    push 0
    call [ExitProcess]

include 'training.inc'
