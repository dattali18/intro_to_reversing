; push MB_OK
push 0

; setup caption string "Injected"
sub esp, 10h                ; make space on stack
mov dword ptr [esp], 0x7463656A  ; 'ject'
mov dword ptr [esp+4], 0x64656E49 ; 'Ined'
mov byte ptr [esp+8], 0      ; null terminator

lea eax, [esp]
push eax                    ; push caption pointer

; setup message string "Injected by Daniel"
sub esp, 20h                ; more space
mov dword ptr [esp], 0x6A62696E   ; 'nibj' (reverse)
mov dword ptr [esp+4], 0x20746563 ; 'cet '
mov dword ptr [esp+8], 0x20627920 ; ' yb '
mov dword ptr [esp+0Ch], 0x6C656E69 ; 'inel'
mov dword ptr [esp+10h], 0x61442079 ; 'y Da'
mov byte ptr [esp+14h], 0         ; null terminator

lea eax, [esp]
push eax                    ; push text pointer

; push hWnd
push 0

; call MessageBoxA (use IAT address if needed)
mov eax, [0x404020]         ; replace with actual IAT address of MessageBoxA
call eax

; Clean stack space if needed (not critical unless more code follows)
