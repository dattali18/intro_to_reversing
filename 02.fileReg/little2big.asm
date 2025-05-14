; uint32_t little2big(uint32_t x)
; x : in edi
; return : eax
; little2big : convert little-endian to big-endian
little2big:
    mov eax, edi
    shr eax, 24
    mov edx, edi
    sal edx, 24
    or eax, edx
    mov edx, edi
    shr edx, 8
    and edx, 0x00FF0000
    or eax, edx
    mov edx, edi
    sal edx, 8
    and edx, 0x0000FF00
    or eax, edx
    ret

little2big_intrinsic:
    ; This function uses the intrinsic function to convert little-endian to big-endian
    ; x : in edi
    ; return : eax
    mov eax, edi
    bswap eax
    ret
