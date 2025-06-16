format PE console
entry start

include 'win32a.inc'

section '.data' data readable writeable

    ; Constants
    width           dd 10
    height          dd 10
    
    ; Game state variables
    init_x_pos      dd 1
    init_y_pos      dd 1
    x_pos           dd 1
    y_pos           dd 1
    input           db 0
    
    ; Console handles and buffers
    hConsole        dd 0
    coord           dd 0    ; COORD structure (X=0, Y=0)
    written         dd 0
    csbi            db 22 dup(0)  ; CONSOLE_SCREEN_BUFFER_INFO structure
    
    ; String constants
    snake_head      db 'O', 0
    wall_char       db '#', 0
    empty_char      db '.', 0
    newline         db 13, 10, 0
    invalid_msg     db 'Invalid input', 13, 10, 0
    input_format    db '%c', 0

section '.code' code readable executable

start:
    call snake_game
    
    ; Exit program
    push 0
    call [ExitProcess]

snake_game:
    push ebp
    mov ebp, esp
    
    ; Initialize position variables
    mov eax, [init_x_pos]
    mov [x_pos], eax
    mov eax, [init_y_pos]
    mov [y_pos], eax
    
game_loop:
    ; Clear the console on Windows
    call clear_console
    
    ; Print frame with current position
    push [y_pos]
    push [x_pos]
    call print_frame
    add esp, 8
    
    ; Read input character
    push 1
    push input
    push input_format
    call [scanf]
    add esp, 12
    
    ; Check input character
    mov al, [input]
    
    cmp al, 'w'
    je move_up
    cmp al, 's'
    je move_down
    cmp al, 'a'
    je move_left
    cmp al, 'd'
    je move_right
    cmp al, 'q'
    je quit_game
    
    ; Invalid input
    push invalid_msg
    call [printf]
    add esp, 4
    jmp game_loop
    
move_up:
    ; if (y_pos > 1) y_pos--;
    mov eax, [y_pos]
    cmp eax, 1
    jle game_loop
    dec eax
    mov [y_pos], eax
    jmp game_loop
    
move_down:
    ; if (y_pos < height - 2) y_pos++;
    mov eax, [y_pos]
    mov ebx, [height]
    sub ebx, 2
    cmp eax, ebx
    jge game_loop
    inc eax
    mov [y_pos], eax
    jmp game_loop
    
move_left:
    ; if (x_pos > 1) x_pos--;
    mov eax, [x_pos]
    cmp eax, 1
    jle game_loop
    dec eax
    mov [x_pos], eax
    jmp game_loop
    
move_right:
    ; if (x_pos < width - 2) x_pos++;
    mov eax, [x_pos]
    mov ebx, [width]
    sub ebx, 2
    cmp eax, ebx
    jge game_loop
    inc eax
    mov [x_pos], eax
    jmp game_loop
    
quit_game:
    mov esp, ebp
    pop ebp
    ret

print_frame:
    push ebp
    mov ebp, esp
    push esi
    push edi
    push ebx
    
    ; Parameters: [ebp+8] = x, [ebp+12] = y
    mov esi, 0  ; i counter
    
outer_loop:
    cmp esi, [height]
    jge print_frame_end
    
    mov edi, 0  ; j counter
    
inner_loop:
    cmp edi, [width]
    jge print_newline
    
    ; Check if current position is snake head (i == y && j == x)
    mov eax, [ebp+12]  ; y parameter
    cmp esi, eax
    jne check_wall
    mov eax, [ebp+8]   ; x parameter
    cmp edi, eax
    jne check_wall
    
    ; Print snake head
    push snake_head
    call [printf]
    add esp, 4
    jmp next_char
    
check_wall:
    ; Check if wall (i == 0 || i == height-1 || j == 0 || j == width-1)
    cmp esi, 0
    je print_wall
    mov eax, [height]
    dec eax
    cmp esi, eax
    je print_wall
    cmp edi, 0
    je print_wall
    mov eax, [width]
    dec eax
    cmp edi, eax
    je print_wall
    
    ; Print empty space
    push empty_char
    call [printf]
    add esp, 4
    jmp next_char
    
print_wall:
    push wall_char
    call [printf]
    add esp, 4
    
next_char:
    inc edi
    jmp inner_loop
    
print_newline:
    push newline
    call [printf]
    add esp, 4
    inc esi
    jmp outer_loop
    
print_frame_end:
    pop ebx
    pop edi
    pop esi
    mov esp, ebp
    pop ebp
    ret

clear_console:
    push ebp
    mov ebp, esp
    push ebx
    push esi
    push edi
    
    ; Get console handle
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hConsole], eax
    
    ; Set coordinate to (0,0)
    mov dword [coord], 0
    
    ; Get console screen buffer info
    push csbi
    push [hConsole]
    call [GetConsoleScreenBufferInfo]
    
    ; Calculate buffer size (csbi.dwSize.X * csbi.dwSize.Y)
    ; csbi.dwSize is at offset 0 in the structure
    movzx eax, word [csbi]      ; X coordinate
    movzx ebx, word [csbi+2]    ; Y coordinate
    mul ebx                     ; eax = X * Y
    
    ; Fill console with spaces
    push written
    push dword [coord]
    push eax                    ; size
    push ' '                    ; character
    push [hConsole]
    call [FillConsoleOutputCharacterA]
    
    ; Set cursor position to (0,0)
    push dword [coord]
    push [hConsole]
    call [SetConsoleCursorPosition]
    
    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret

section '.idata' import data readable writeable

library kernel32,'KERNEL32.DLL',\
        msvcrt,'MSVCRT.DLL'

import kernel32,\
       ExitProcess,'ExitProcess',\
       GetStdHandle,'GetStdHandle',\
       GetConsoleScreenBufferInfo,'GetConsoleScreenBufferInfo',\
       FillConsoleOutputCharacterA,'FillConsoleOutputCharacterA',\
       SetConsoleCursorPosition,'SetConsoleCursorPosition'

import msvcrt,\
       printf,'printf',\
       scanf,'scanf'

