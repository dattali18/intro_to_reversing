; Daniel Attali 01/05/2025 - Registry Reader
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
    output_msg db "The number in the file is: 0x", 0
    output_0x db "The converted number is: 0x", 0
    error_msg db "Error accessing registry.", 13, 10, 0
    newline db 13, 10, 0

section '.code' code readable executable

start:
    ; Print the initial message
    mov esi, reg_msg
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
    push eax                    ; phkResult - Address to store the handle
    push 0x20019                ; samDesired - KEY_READ access right
    push 0                      ; ulOptions - Reserved, must be 0
    push registry_key           ; lpSubKey - Key name (relative path)
    push 0x80000001             ; hKey - HKEY_CURRENT_USER
    call [RegOpenKeyExA]

    ; Check if key opened successfully
    test eax, eax
    jnz .reg_error

    ; Read the registry value
    lea eax, [reg_value_size]
    push eax                    ; lpcbData
    lea eax, [reg_buffer]
    push eax                    ; lpData
    lea eax, [reg_type]
    push eax                    ; lpType
    push 0                      ; lpReserved
    push registry_value         ; lpValueName
    push dword [registry_handle] ; hKey
    call [RegQueryValueExA]

    ; Check if value read successfully
    test eax, eax
    jnz .reg_close_and_error

    ; Close the registry key
    push dword [registry_handle]
    call [RegCloseKey]

    ; Return the read value in eax
    mov eax, [reg_buffer]

    pop ebp
    ret

.reg_close_and_error:
    ; Close the key before exiting with error
    push dword [registry_handle]
    call [RegCloseKey]

.reg_error:
    ; Simple error message
    mov esi, error_msg
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