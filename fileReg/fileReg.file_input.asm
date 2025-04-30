; Daniel Attali 29/04/2025
include 'win32a.inc'


format PE console
entry start

; section '.data' data readable writeable
section '.data' data readable writeable
    input_file_name db "input.txt", 0
    input_buffer  rb 9         ; 8 chars + null terminator
    output_buffer rb 11        ; "0x" + 8 hex chars + null
    file_handle   dd ?
    bytes_read    dd ?
    ; input_msg
    input_msg db "Reading from input.txt", 13, 10, 0
    output_msg db "The number in big-endian is: 0x", 0
    output_0x db "0x", 0
    debug_msg_open db "[DEBUG]: File opened successfully.", 13, 10, 0
    debug_msg_read db "[DEBUG]: File read successfully.", 13, 10, 0
    debug_msg_close db "[DEBUG]: File closed successfully.", 13, 10, 0
    debug_error db "[DEBUG] Error: ", 13, 10, 0
    read_bytes_msg db "Bytes read: %d", 13, 10, 0
    error_code_msg db "Error Code: %d", 13, 10, 0



section '.text' code readable executable
start:
    ; in this program we wil read the first number from the file input.txt
    ; and we will convert it from little-endian to big-endian
    ; and output it to the console
    ; Open the file
    lea esi, [input_msg]
    call print_str

    call read_hex_from_file
    lea esi, [output_msg]
    call print_str
    call print_eax
    ; result is now in eax
    mov edi, eax
    call little2big
    lea esi, [output_0x]
    call print_str
    call print_eax
  
.exit_program:
    push 0
    call [ExitProcess]


read_hex_from_file:
    ; This function reads a hex number from the file input.txt
    ; and returns it in eax

    push ebp
    mov ebp, esp

    ; Open the file
    push 0                     ; hTemplateFile = NULL
    push 80h                   ; dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL
    push 3                     ; dwCreationDisposition = OPEN_EXISTING
    push 0                     ; lpSecurityAttributes = NULL
    push 1                     ; dwShareMode = FILE_SHARE_READ
    push 80000000h             ; dwDesiredAccess = GENERIC_READ
    push input_file_name       ; lpFileName
    call [CreateFileA]
    
    ; Check if file opened successfully
    cmp eax, -1                ; INVALID_HANDLE_VALUE
    je .get_error
    
    ; Store file handle
    mov [file_handle], eax
    
    ; [DEBUG]
    lea esi, [debug_msg_open]
    call print_str

    ; Read the file
    mov ebx, [file_handle]     ; Preserve file handle in ebx
    push 0                     ; lpOverlapped = NULL
    lea edx, [bytes_read]      ; Get address of bytes_read
    push edx                   ; lpNumberOfBytesRead
    push 8                     ; nNumberOfBytesToRead = 8 bytes
    push input_buffer          ; lpBuffer
    push ebx                   ; hFile
    call [ReadFile]
    
    ; Check if read succeeded
    test eax, eax
    jz .get_error
    
    ; Check if we read any bytes
    cmp dword [bytes_read], 0
    je .get_error
    
    ; [DEBUG]
    lea esi, [debug_msg_read]
    call print_str
    
    ; Close the file
    push [file_handle]
    call [CloseHandle]
    
    ; Check if close succeeded
    test eax, eax
    jz .get_error
    
    ; [DEBUG]
    lea esi, [debug_msg_close]
    call print_str

    ; Convert the hex string to a number
    lea eax, [input_buffer]
    call hex_to_int

    pop ebp
    ret

.get_error:
    ; Get the error code
    call [GetLastError]
    ; (Optionally) print the error code for debugging
    push eax
    push error_code_msg
    call [printf]           ; Assuming printf is available
    add esp, 8
    
    ; Continue to read_error
    jmp .read_error

.read_error:
    ; Handle read error
    lea esi, [debug_error]
    call print_str
    push 1
    call [ExitProcess]

; uint32_t hex_to_int(char *str)
hex_to_int:
    ; This function converts a hex string to an integer
    ; str : in eax
    ; return : eax

    xor ecx, ecx            ; Clear ecx (used as the result accumulator)
    xor edx, edx            ; Clear edx (used as a temporary register)

convert_loop:
    mov dl, [eax]           ; Load the current character from the string
    test dl, dl             ; Check if it's the null terminator
    jz done                 ; If null terminator, exit the loop

    shl ecx, 4              ; Shift the result left by 4 bits (multiply by 16)

    cmp dl, '0'             ; Check if the character is a digit (0-9)
    jl invalid_char         ; If less than '0', it's invalid
    cmp dl, '9'
    jg check_alpha          ; If greater than '9', check if it's a letter
    sub dl, '0'             ; Convert '0'-'9' to 0-9
    jmp store_value

check_alpha:
    cmp dl, 'A'             ; Check if the character is an uppercase letter (A-F)
    jl invalid_char         ; If less than 'A', it's invalid
    cmp dl, 'F'
    jg check_lowercase      ; If greater than 'F', check lowercase
    sub dl, 'A'             ; Convert 'A'-'F' to 10-15
    add dl, 10
    jmp store_value

check_lowercase:
    cmp dl, 'a'             ; Check if the character is a lowercase letter (a-f)
    jl invalid_char         ; If less than 'a', it's invalid
    cmp dl, 'f'
    jg invalid_char         ; If greater than 'f', it's invalid
    sub dl, 'a'             ; Convert 'a'-'f' to 10-15
    add dl, 10

store_value:
    add ecx, edx            ; Add the converted value to the result
    inc eax                 ; Move to the next character
    jmp convert_loop        ; Repeat the loop

invalid_char:
    xor ecx, ecx            ; If an invalid character is found, return 0
    jmp done

done:
    mov eax, ecx            ; Move the result into eax
    ret


; uint32_t little2big(uint32_t x)
; x : in edi
; return : eax
; little2big : convert little-endian to big-endian
little2big:
        mov     eax, edi        ; copy input to eax
        shr     eax, 24         ; get byte 3 -> byte 0

        mov     edx, edi
        sal     edx, 24         ; get byte 0 -> byte 3
        or      eax, edx

        mov     edx, edi
        shr     edx, 8
        and     edx, 65280      ; mask byte 2 -> byte 1
        or      eax, edx

        sal     edi, 8
        and     edi, 16711680   ; mask byte 1 -> byte 2
        or      eax, edi

        ret

little2big_intrinsic:
    ; This function uses the intrinsic function to convert little-endian to big-endian
    ; x : in edi
    ; return : eax
    mov eax, edi
    bswap eax
    ret

    
include 'training.inc'