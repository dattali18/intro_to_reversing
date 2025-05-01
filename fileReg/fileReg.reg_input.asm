; Daniel Attali 29/04/2025
include 'win32a.inc'

format PE console
entry start

section '.data' data readable writeable
    input_file_name db "input.txt", 0
    input_buffer  rb 9         ; 8 chars + null terminator
    output_buffer rb 11        ; "0x" + 8 hex chars + null
    file_handle   dd ?
    bytes_read    dd ?
    ; input_msg
    input_msg db "Reading from input.txt", 13, 10, 0
    output_msg db "The number in the file is: 0x", 0
    output_0x db "The converted number is: 0x", 0
    debug_msg_open db "[DEBUG]: File opened successfully.", 13, 10, 0
    debug_msg_read db "[DEBUG]: File read successfully.", 13, 10, 0
    debug_msg_close db "[DEBUG]: File closed successfully.", 13, 10, 0
    debug_error db "[DEBUG] Error: ", 13, 10, 0
    read_bytes_msg db "Bytes read: %d", 13, 10, 0
    error_code_msg db "Error Code: %d", 13, 10, 0
    ; Change this in your data section
    registry_key db "Software\\Assembly", 0
    registry_value db "input", 0
    registry_handle dd 0      ; Initialize to 0
    reg_value_size dd 4       ; Size of DWORD in bytes
    reg_buffer dd 0           ; Initialize to 0
    reg_type dd 0            ; To receive the value type
    reg_msg db "Reading from registry HKCU\Software\Assembly\input", 13, 10, 0
    debug_open_reg db "[DEBUG]: Registry key opened successfully.", 13, 10, 0
    debug_read_reg db "[DEBUG]: Registry value read successfully.", 13, 10, 0
    debug_reg_error db "[DEBUG]: Registry error occurred. Code:", 13, 10, 0


; In your text section, modify start: to include the registry reading option
start:
    ; Uncomment the part you want to run
    ; Option 1: Read from file
    ;lea esi, [input_msg]
    ;call print_str
    ;call read_hex_from_file
    
    ; Option 3: Read from registry
    mov esi, reg_msg
    call print_str
    call read_hex_from_registry
    
    ; The rest of your code remains the same
    mov esi, output_msg
    call print_str
    call print_eax
    ; result is now in eax
    mov edi, eax
    call little2big
    mov esi, output_0x
    call print_str
    call print_eax
  
.exit_program:
    push 0
    call [ExitProcess]

read_hex_from_registry:
    push ebp
    mov ebp, esp

    ; Open the registry key
    push registry_handle      ; Address to store the handle
    push 0x0000               ; Reserved, must be 0
    push 0x20019              ; KEY_READ access right
    push registry_key         ; Key name (relative path)
    push 0x80000001           ; HKEY_CURRENT_USER
    call [RegOpenKeyExA]

    ; Check if key opened successfully
    test eax, eax
    jnz .reg_open_error

    ; Debug message for successful key opening
    mov esi, debug_open_reg
    call print_str

    ; Read the registry value
    mov ecx, reg_type          ; Location to store the type
    push ecx                   ; lpType
    mov ecx, reg_buffer        ; Buffer for data
    push ecx                   ; lpData
    mov ecx, reg_value_size    ; Location storing buffer size
    push ecx                   ; lpcbData
    push 0                     ; lpReserved (NULL)
    push registry_value        ; Value name ("input")
    push dword [registry_handle] ; Key handle
    call [RegQueryValueExA]

    ; Check if value read successfully
    test eax, eax
    jnz .reg_query_error

    ; Debug message for successful value reading
    mov esi, debug_read_reg
    call print_str

    ; Close the registry key
    push dword [registry_handle]
    call [RegCloseKey]

    ; Return the read value in eax
    mov eax, [reg_buffer]

    pop ebp
    ret

.reg_open_error:
    call [GetLastError]        ; Retrieve error code immediately
    mov esi, eax               ; Save error code in esi
    call print_eax             ; Print error code for debugging
    mov esi, debug_reg_error   ; Error message format
    call print_str
    add esp, 4                 ; Clean stack
    jmp .exit_error

.reg_query_error:
    call [GetLastError]        ; Retrieve error code immediately
    mov esi, eax               ; Save error code in esi
    call print_eax             ; Print error code for debugging
    mov esi, debug_reg_error   ; Error message format
    call print_str
    add esp, 4                 ; Clean stack

    ; Close the registry key even though query failed
    push dword [registry_handle]
    call [RegCloseKey]
    jmp .exit_error

.exit_error:
    push 1
    call [ExitProcess]

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