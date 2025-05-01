; Daniel Attali 01/05/2025 - Fixed Registry Reader
include 'win32a.inc'

format PE console
entry start

section '.data' data readable writeable
    ; Registry-related data
    registry_key db "SOFTWARE\\Assembly", 0
    registry_value db "input", 0
    registry_handle dd 0
    reg_value_size dd 4
    reg_buffer dd 0
    reg_type dd 0
    ; Messages
    reg_msg db "Reading from registry HKCU\\Software\\Assembly\\input", 13, 10, 0
    debug_key db "Trying registry key: ", 0
    debug_value db "Looking for value: ", 0
    debug_open_reg db "[DEBUG]: Registry key opened successfully.", 13, 10, 0
    debug_read_reg db "[DEBUG]: Registry value read successfully.", 13, 10, 0
    debug_reg_error db "[DEBUG]: Registry error occurred. Code: ", 0
    debug_error_desc db "[DEBUG]: Error description: ", 0
    debug_handle db "Registry handle: ", 0
    output_msg db "The number in the file is: 0x", 0
    output_0x db "The converted number is: 0x", 0
    newline db 13, 10, 0
    debug_msg db "[DEBUG]: ", 0 
    ; Error messages
    err_not_found db "Key or value not found", 0
    err_access_denied db "Access denied", 0
    err_invalid_param db "Invalid parameter", 0
    err_unknown db "Unknown error", 0

section '.code' code readable executable

start:
    ; Print the initial message
    mov esi, reg_msg
    call print_str
    
    ; Debug: Show key and value we're looking for
    mov esi, debug_key
    call print_str
    mov esi, registry_key
    call print_str
    mov esi, newline
    call print_str
    
    mov esi, debug_value
    call print_str
    mov esi, registry_value
    call print_str
    mov esi, newline
    call print_str

    ; Attempt to read the registry value
    call read_hex_from_registry

    ; If we get here, the registry read was successful
    ; Print the result
    mov esi, output_msg
    call print_str
    call print_eax

    ; Convert the number from little-endian to big-endian
    mov edi, eax
    call little2big

    ; Print the converted number
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
    lea eax, [registry_handle]
    push eax                    ; Address to store the handle
    push 0                      ; Reserved, must be 0
    push 0x20019                ; KEY_READ access right
    push registry_key           ; Key name (relative path)
    push 0x80000001             ; HKEY_CURRENT_USER
    call [RegOpenKeyExA]

    ; Store return value for error reporting
    mov ebx, eax
    
    ; Check if key opened successfully
    test eax, eax
    jnz .reg_open_error

    ; Debug message for successful key opening
    mov esi, debug_open_reg
    call print_str

    ; Debug: Print the handle value
    mov esi, debug_handle
    call print_str
    mov eax, dword [registry_handle]
    call print_eax
    mov esi, newline
    call print_str

    ; Read the registry value
    lea eax, [reg_type]
    push eax                   ; lpType
    lea eax, [reg_buffer]
    push eax                   ; lpData
    lea eax, [reg_value_size]
    push eax                   ; lpcbData
    push 0                     ; lpReserved
    push registry_value        ; Value name
    push dword [registry_handle] ; Key handle
    call [RegQueryValueExA]

    ; Store return value for error reporting
    mov ebx, eax
    
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
    ; Error message
    mov esi, debug_reg_error
    call print_str
    mov eax, ebx               ; Restore API return value
    call print_eax
    mov esi, newline
    call print_str
    
    ; Show error description
    mov esi, debug_error_desc
    call print_str
    
    ; Choose error message based on error code
    cmp ebx, 2                 ; ERROR_FILE_NOT_FOUND
    je .show_not_found
    cmp ebx, 5                 ; ERROR_ACCESS_DENIED
    je .show_access_denied
    cmp ebx, 0xBB              ; ERROR_INVALID_PARAMETER
    je .show_invalid_param
    jmp .show_unknown
    
.reg_query_error:
    ; Close the registry key
    push dword [registry_handle]
    call [RegCloseKey]

    ; Error message
    mov esi, debug_reg_error
    call print_str
    mov eax, ebx               ; Restore API return value
    call print_eax
    mov esi, newline
    call print_str
    
    ; Show error description
    mov esi, debug_error_desc
    call print_str
    
    ; Choose error message based on error code
    cmp ebx, 2                 ; ERROR_FILE_NOT_FOUND
    je .show_not_found
    cmp ebx, 5                 ; ERROR_ACCESS_DENIED
    je .show_access_denied
    cmp ebx, 0xBB              ; ERROR_INVALID_PARAMETER
    je .show_invalid_param
    jmp .show_unknown

.show_not_found:
    mov esi, err_not_found
    call print_str
    jmp .exit_error
    
.show_access_denied:
    mov esi, err_access_denied
    call print_str
    jmp .exit_error
    
.show_invalid_param:
    mov esi, err_invalid_param
    call print_str
    jmp .exit_error
    
.show_unknown:
    mov esi, err_unknown
    call print_str
    
.exit_error:
    mov esi, newline
    call print_str
    push 1
    call [ExitProcess]

; uint32_t little2big(uint32_t x)
; x : in edi
; return : eax
; Convert little-endian to big-endian
little2big:
    mov     eax, edi        ; Copy input to eax
    shr     eax, 24         ; Get byte 3 -> byte 0

    mov     edx, edi
    sal     edx, 24         ; Get byte 0 -> byte 3
    or      eax, edx

    mov     edx, edi
    shr     edx, 8
    and     edx, 65280      ; Mask byte 2 -> byte 1
    or      eax, edx

    sal     edi, 8
    and     edi, 16711680   ; Mask byte 1 -> byte 2
    or      eax, edi

    ret

include 'training.inc'