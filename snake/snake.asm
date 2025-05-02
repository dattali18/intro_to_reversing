; Daniel Attali 14/04/2025
include 'win32a.inc'

format PE console
entry start

section '.data' data readable writeable
    hash_str     db "#", 0
    space_str    db " ", 0
    snake_str    db "O", 0
    newline_str  db 13, 10, 0     ; This is correct: CRLF only for newline
    x          dd 0
    y          dd 0
    buffer    db 2 dup(0)       ; Buffer for key input

section '.text' code readable executable
start:

    ; Set initial position (x = 5, y = 5)
    mov dword [x], 1
    mov dword [y], 1

.main_loop:
    call clear_screen

    mov edi, dword [x]    ; x into edi
    mov esi, dword [y]    ; y into esi
    call print_frame

    ; Wait for keypress
    xor eax, eax
    call get_key

    cmp al, 'q'         ; q for exit
    je .exit_program

    cmp al, 'w'
    jne .check_s
    ; check that y > 1
    cmp dword [y], 1
    jle .main_loop
    dec dword [y]
    jmp .main_loop

.check_s:
    cmp al, 's'
    jne .check_a
    ; check that y < 8
    cmp dword [y], 8
    jge .main_loop
    inc dword [y]
    jmp .main_loop

.check_a:
    cmp al, 'a'
    jne .check_d
    ; check that x > 1
    cmp dword [x], 1
    jle .main_loop
    dec dword [x]
    jmp .main_loop

.check_d:
    cmp al, 'd'
    jne .main_loop
    ; check that x < 8
    cmp dword [x], 8
    jge .main_loop
    inc dword [x]
    jmp .main_loop

.exit_program:
    push 0
    call [ExitProcess]

; print_frame(int x, int y)
; get the x, and y arguments from the data section
; and print the frame with the snake position
; x = head position (x coordinate) in edi
; y = head position (y coordinate) in esi
; The frame is 10x10, with '#' for the border and 'O' for the snake
; The rest of the frame is filled with spaces
; The frame is printed to the console
print_frame:
    push ebp
    mov ebp, esp
    push edi
    push esi
    push eax
    push ebx
    push ecx

    ; Load input parameters
    ; mov eax, dword[x]    ; x into esi
    ; mov edi, dword[y]    ; y into edi

    ; eax = x, edi = y
    mov eax, edi
    mov edi, esi

    xor ebx, ebx          ; row index (y loop)

.outer_loop:              ; For y in 0 to 9
    xor ecx, ecx          ; column index (x loop)

.inner_loop:              ; For x in 0 to 9
    ; If border: if i==0 || i==9 || j==0 || j==9 => '#'
    cmp ebx, 0
    je .print_hash
    cmp ebx, 9
    je .print_hash
    cmp ecx, 0
    je .print_hash
    cmp ecx, 9
    je .print_hash

    ; If head position: if i == y && j == x => 'O'
    cmp ecx, eax
    jne .print_space
    cmp ebx, edi
    jne .print_space

    ; Print 'O'
    mov esi, snake_str
    call print_str
    jmp .after_cell

.print_hash:
    mov esi, hash_str
    call print_str
    jmp .after_cell

.print_space:
    mov esi, space_str
    call print_str

.after_cell:
    inc ecx
    cmp ecx, 10
    jl .inner_loop

    ; Print newline after each row
    mov esi, newline_str
    call print_str

    inc ebx
    cmp ebx, 10
    jl .outer_loop

    ; return the control to the caller
    pop ecx
    pop ebx
    pop eax
    pop esi
    pop edi
    ; restore the stack frame
    mov esp, ebp
    pop ebp

    ret

; get_key()
; using the training.inc function read_line
; Returns: al = key pressed
get_key:
    push ebp
    mov ebp, esp
    push edi
    push ecx

    lea edi, [buffer]      ; buffer address
    mov ecx, 2
    call read_line        ; read line into buffer
    ; get the first character from buffer
    xor eax, eax
    mov al, byte [buffer] ; get the first character
    ; check if the character is a valid key (w, a, s, d)
    cmp al, 'w'
    je .valid_key
    cmp al, 'a'
    je .valid_key
    cmp al, 's'
    je .valid_key
    cmp al, 'd'
    je .valid_key
    cmp al, 'q'          ; ESC key
    je .valid_key

    ; If not a valid key, set eax to 0 (no key pressed)
    
    xor eax, eax

.valid_key:

    pop ecx
    pop edi
    mov esp, ebp
    pop ebp

    ret

clear_screen:
    push ebp
    mov ebp, esp
    pushad

    STD_OUTPUT_HANDLE equ -11

    ; Step 1: Get the handle to the standard output
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    call print_eax
    test eax, eax                 ; Check if the handle is valid
    js .error_exit                ; Exit if an error occurs
    mov esi, eax                  ; Store the handle in `esi`

    ; Step 2: Get console screen buffer info
    sub esp, 28                   ; Allocate space for CONSOLE_SCREEN_BUFFER_INFO (28 bytes)
    lea edi, [esp]                ; Use `edi` to point to the buffer
    push edi                      ; lpConsoleScreenBufferInfo
    push esi                      ; hConsoleOutput
    call [GetConsoleScreenBufferInfo]
    test eax, eax                 ; Check return value
    jz .error_exit                ; Exit if an error occurs

    ; Step 3: Calculate total cells to clear (width * height)
    movzx ecx, word [edi + 0x0C]  ; Screen width (dwSize.X)
    movzx edx, word [edi + 0x0E]  ; Screen height (dwSize.Y)
    imul ecx, edx                 ; Total cells = width * height
    mov ebx, ecx                  ; Store total cells in `ebx`

    ; Step 4: Fill the console with spaces
    mov eax, ' '                  ; ASCII space character
    lea ecx, [esp + 28]           ; Pointer to store the number of characters written
    push ecx                      ; lpNumberOfCharsWritten
    push ebx                      ; nLength (total cells)
    push eax                      ; cCharacter (' ')
    push esi                      ; hConsoleOutput
    call [FillConsoleOutputCharacter]
    test eax, eax                 ; Check return value
    jz .error_exit                ; Exit if an error occurs

    ; Step 5: Reset the cursor position to the top-left corner
    xor eax, eax                  ; X = 0
    xor edx, edx                  ; Y = 0
    mov word [edi], 0             ; Set X in COORD structure
    mov word [edi + 2], 0         ; Set Y in COORD structure
    push edi                      ; Pointer to COORD structure
    push esi                      ; hConsoleOutput
    call [SetConsoleCursorPosition]
    test eax, eax                 ; Check return value
    jz .error_exit                ; Exit if an error occurs

    ; Clean up and return
    add esp, 28                   ; Free allocated space for CONSOLE_SCREEN_BUFFER_INFO
    popad
    mov esp, ebp
    pop ebp
    ret

.error_exit:
    ; If an error occurs, clean up and return
    add esp, 22                   ; Free allocated space for CONSOLE_SCREEN_BUFFER_INFO
    popad
    mov esp, ebp
    pop ebp
    ret

include 'training.inc'
