; Daniel Attali 29/04/2025
include 'win32a.inc'

format PE console
entry start

section '.data' data readable writeable
input_msg db "Enter a number in hex format: ", 13, 10, 0
output_msg db "The number in big-endian format is: 0x", 0


section '.text' code readable executable
start:
    ; Print the input message
    lea esi , [input_msg] ; load the address of the input message into esi
    call print_str ; call the function to print the string
    ; Read the input value in hex format
    call read_hex
    ; Convert the input value from little-endian to big-endian
    mov edi, eax ; move the input value to edi for the function call
    call little2big ; call the function to convert little-endian to big-endian
    lea esi , [output_msg] ; load the address of the output message into esi
    call print_str ; call the function to print the string
    ; call print eax
    call print_eax ; print the result in eax

.exit_program:
    push 0
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