format PE console
entry start

include 'win32a.inc'

section '.data' data readable writeable

    ; String constants
    prompt_msg          db 'Enter a hexadecimal number (without 0x prefix): ', 0
    invalid_input_msg   db 'Invalid input. Please enter a valid hexadecimal number.', 13, 10, 0
    original_msg        db 'Original value:     0x%X', 13, 10, 0
    swapped_msg         db 'Byte-swapped value: 0x%X', 13, 10, 0
    file_open_error_msg db 'Could not open file: %s', 13, 10, 0
    file_input_error_msg db 'Invalid input in file. Please ensure it contains a valid hexadecimal number.', 13, 10, 0
    original_file_msg   db 'Original value from file:     0x%X', 13, 10, 0
    swapped_file_msg    db 'Byte-swapped value from file: 0x%X', 13, 10, 0
    reg_open_error_msg  db 'Could not open registry key: %s', 13, 10, 0
    reg_read_error_msg  db 'Could not read value from registry key: %s', 13, 10, 0
    original_reg_msg    db 'Original value from registry:     0x%X', 13, 10, 0
    swapped_reg_msg     db 'Byte-swapped value from registry: 0x%X', 13, 10, 0
    newline_msg         db 13, 10, 13, 10, 0
    
    ; File and registry constants
    filename            db 'input.txt', 0
    reg_key             db 'SOFTWARE\Assembly', 0
    reg_value_name      db 'input', 0
    file_mode_read      db 'r', 0
    hex_format          db '%x', 0
    
    ; Variables
    user_input          dd ?
    swapped_value       dd ?
    file_input          dd ?
    reg_value           dd ?
    file_handle         dd ?
    reg_key_handle      dd ?
    data_size           dd ?
    
section '.code' code readable executable

start:
    ; 1. Take user input as hex
    push prompt_msg
    call [printf]
    add esp, 4
    
    push user_input
    push hex_format
    call [scanf]
    add esp, 8
    
    cmp eax, 1
    je user_input_success
    
    ; Invalid input
    push invalid_input_msg
    call [printf]
    add esp, 4
    mov eax, 1
    jmp exit_program
    
user_input_success:
    ; Swap endian using bswap
    mov eax, [user_input]
    bswap eax
    mov [swapped_value], eax
    
    ; Print original value
    push [user_input]
    push original_msg
    call [printf]
    add esp, 8
    
    ; Print swapped value
    push [swapped_value]
    push swapped_msg
    call [printf]
    add esp, 8
    
    ; 2. Read from a .txt file
    push file_mode_read
    push filename
    call [fopen]
    add esp, 8
    
    mov [file_handle], eax
    test eax, eax
    jnz file_open_success
    
    ; Could not open file
    push filename
    push file_open_error_msg
    call [printf]
    add esp, 8
    mov eax, 1
    jmp exit_program
    
file_open_success:
    push file_input
    push hex_format
    push [file_handle]
    call [fscanf]
    add esp, 12
    
    cmp eax, 1
    je file_input_success
    
    ; Invalid input in file
    push file_input_error_msg
    call [printf]
    add esp, 4
    
    push [file_handle]
    call [fclose]
    add esp, 4
    
    mov eax, 1
    jmp exit_program
    
file_input_success:
    push [file_handle]
    call [fclose]
    add esp, 4
    
    ; Swap endian using bswap
    mov eax, [file_input]
    bswap eax
    mov [swapped_value], eax
    
    ; Print newlines
    push newline_msg
    call [printf]
    add esp, 4
    
    ; Print original value from file
    push [file_input]
    push original_file_msg
    call [printf]
    add esp, 8
    
    ; Print swapped value from file
    push [swapped_value]
    push swapped_file_msg
    call [printf]
    add esp, 8
    
    ; 3. Read from registry (Windows specific)
    push reg_key_handle
    push KEY_READ
    push 0
    push reg_key
    push HKEY_CURRENT_USER
    call [RegOpenKeyExA]
    
    test eax, eax
    jz reg_open_success
    
    ; Could not open registry key
    push reg_key
    push reg_open_error_msg
    call [printf]
    add esp, 8
    mov eax, 1
    jmp exit_program
    
reg_open_success:
    mov [data_size], 4  ; sizeof(uint)
    
    push data_size
    push reg_value
    push 0
    push 0
    push reg_value_name
    push [reg_key_handle]
    call [RegQueryValueExA]
    
    test eax, eax
    jz reg_read_success
    
    ; Could not read value from registry
    push reg_key
    push reg_read_error_msg
    call [printf]
    add esp, 8
    
    push [reg_key_handle]
    call [RegCloseKey]
    add esp, 4
    
    mov eax, 1
    jmp exit_program
    
reg_read_success:
    push [reg_key_handle]
    call [RegCloseKey]
    add esp, 4
    
    ; Swap endian using bswap
    mov eax, [reg_value]
    bswap eax
    mov [swapped_value], eax
    
    ; Print newlines
    push newline_msg
    call [printf]
    add esp, 4
    
    ; Print original value from registry
    push [reg_value]
    push original_reg_msg
    call [printf]
    add esp, 8
    
    ; Print swapped value from registry
    push [swapped_value]
    push swapped_reg_msg
    call [printf]
    add esp, 8
    
    mov eax, 0  ; Return 0 for success
    
exit_program:
    push eax
    call [ExitProcess]

section '.idata' import data readable writeable

    library kernel32,'KERNEL32.DLL',\
            msvcrt,'MSVCRT.DLL',\
            advapi32,'ADVAPI32.DLL'

    import kernel32,\
           ExitProcess,'ExitProcess'

    import msvcrt,\
           printf,'printf',\
           scanf,'scanf',\
           fopen,'fopen',\
           fclose,'fclose',\
           fscanf,'fscanf'

    import advapi32,\
           RegOpenKeyExA,'RegOpenKeyExA',\
           RegQueryValueExA,'RegQueryValueExA',\
           RegCloseKey,'RegCloseKey'

