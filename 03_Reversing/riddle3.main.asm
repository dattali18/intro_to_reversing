; int __cdecl main(int argc, const char **argv, const char **envp)
_main proc near

var_C= dword ptr -0Ch
var_8= byte ptr -8
var_4= dword ptr -4
argc= dword ptr  8
argv= dword ptr  0Ch
envp= dword ptr  10h

push    ebp
mov     ebp, esp
sub     esp, 0Ch
mov     eax, ___security_cookie
xor     eax, ebp
mov     [ebp+var_4], eax
lea     eax, [ebp+var_8]
push    eax             ; char
push    offset aD       ; "%d"
call    sub_401190
add     esp, 8
mov     ecx, dword ptr [ebp+var_8]
push    ecx
call    sub_401060
add     esp, 4
mov     [ebp+var_C], eax
mov     edx, [ebp+var_C]
push    edx
mov     eax, dword ptr [ebp+var_8]
push    eax             ; char
push    offset Format   ; "Num %d took total %d iterations\n"
call    sub_401110
add     esp, 0Ch
xor     eax, eax
mov     ecx, [ebp+var_4]
xor     ecx, ebp        ; StackCookie
call    @__security_check_cookie@4 ; __security_check_cookie(x)
mov     esp, ebp
pop     ebp
retn
_main endp