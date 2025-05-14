; Registry reader with enhanced debugging
include 'win32a.inc'

format PE console
entry start

section '.data' data readable writeable
    ; Registry data
    hkey_path db "Software\\Microsoft\\Windows\\CurrentVersion", 0
    value_name db "ProgramFilesDir", 0
    hkey dd 0
    data_size dd 1024
    data_buffer rb 1024
    data_type dd 0
    
    ; Messages
    msg_reading db "Reading from registry...", 13, 10, 0
    msg_success db "Success! Value: ", 0
    msg_open_result db "RegOpenKeyExA return value: ", 0
    msg_query_result db "RegQueryValueExA return value: ", 0
    msg_error db "Windows error code: ", 0
    msg_handle db "Handle: ", 0
    newline db 13, 10, 0

section '.code' code readable executable

start:
    ; Print starting message
    mov esi, msg_reading
    call print_str
    
    ; Open the registry key
    lea eax, [hkey]
    push eax                  ; phkResult
    push 0                    ; ulOptions
    push 0x20019              ; KEY_READ
    push hkey_path            ; lpSubKey
    push 0x80000001           ; HKEY_CURRENT_USER
    call [RegOpenKeyExA]
    
    ; Print the return value directly
    mov ebx, eax              ; Save return value
    mov esi, msg_open_result
    call print_str
    mov eax, ebx              ; Restore return value
    call print_eax
    mov esi, newline
    call print_str
    
    ; Check the return value (not using test/jnz)
    cmp eax, 0
    jne open_error
    
    ; Print handle
    mov esi, msg_handle
    call print_str
    mov eax, [hkey]
    call print_eax
    mov esi, newline
    call print_str
    
    ; Query the registry value
    lea eax, [data_type]
    push eax                  ; lpType
    lea eax, [data_buffer]
    push eax                  ; lpData
    lea eax, [data_size]
    push eax                  ; lpcbData
    push 0                    ; lpReserved
    push value_name           ; lpValueName
    push dword [hkey]         ; hKey
    call [RegQueryValueExA]
    
    ; Print the query result
    mov ebx, eax              ; Save return value
    mov esi, msg_query_result
    call print_str
    mov eax, ebx              ; Restore return value
    call print_eax
    mov esi, newline
    call print_str
    
    ; Check return value
    cmp eax, 0
    jne query_error
    
    ; Print success message
    mov esi, msg_success
    call print_str
    mov esi, data_buffer
    call print_str
    mov esi, newline
    call print_str
    
    ; Close the registry key
    push dword [hkey]
    call [RegCloseKey]
    jmp exit_program

open_error:
    mov ebx, eax              ; Save API return value
    mov esi, msg_error
    call print_str
    mov eax, ebx              ; Print API return value directly
    call print_eax
    mov esi, newline
    call print_str
    jmp exit_program

query_error:
    mov ebx, eax              ; Save API return value
    mov esi, msg_error
    call print_str
    mov eax, ebx              ; Print API return value directly
    call print_eax
    mov esi, newline
    call print_str
    
    ; Close the key
    push dword [hkey]
    call [RegCloseKey]

exit_program:
    push 0
    call [ExitProcess]

include 'training.inc'