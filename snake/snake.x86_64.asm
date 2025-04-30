print_frame(int, int):
 push   rbp
 mov    rbp,rsp
 sub    rsp,0x10
 mov    DWORD PTR [rbp-0x4],edi
 mov    DWORD PTR [rbp-0x8],esi
 mov    DWORD PTR [rbp-0xc],0x0
 cmp    DWORD PTR [rbp-0xc],0xa
 jae    12ac <print_frame(int, int)+0xec>
 mov    DWORD PTR [rbp-0x10],0x0
 cmp    DWORD PTR [rbp-0x10],0xa
 jae    128b <print_frame(int, int)+0xcb>
 mov    eax,DWORD PTR [rbp-0xc]
 cmp    eax,DWORD PTR [rbp-0x8]
 jne    1220 <print_frame(int, int)+0x60>
 mov    eax,DWORD PTR [rbp-0x10]
 cmp    eax,DWORD PTR [rbp-0x4]
 jne    1220 <print_frame(int, int)+0x60>
 mov    rdi,QWORD PTR [rip+0x2dc1]        # 3fd0 <std::cout@GLIBCXX_3.4>
 lea    rsi,[rip+0xe4a]        # 2060 <_IO_stdin_used+0x60>
 call   1040 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>
 jmp    1278 <print_frame(int, int)+0xb8>
 cmp    DWORD PTR [rbp-0xc],0x0
 je     1248 <print_frame(int, int)+0x88>
 cmp    DWORD PTR [rbp-0xc],0x9
 je     1248 <print_frame(int, int)+0x88>
 cmp    DWORD PTR [rbp-0x10],0x0
 je     1248 <print_frame(int, int)+0x88>
 cmp    DWORD PTR [rbp-0x10],0x9
 jne    1260 <print_frame(int, int)+0xa0>
 mov    rdi,QWORD PTR [rip+0x2d81]        # 3fd0 <std::cout@GLIBCXX_3.4>
 lea    rsi,[rip+0xe0c]        # 2062 <_IO_stdin_used+0x62>
 call   1040 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>
 jmp    1273 <print_frame(int, int)+0xb3>
 mov    rdi,QWORD PTR [rip+0x2d69]        # 3fd0 <std::cout@GLIBCXX_3.4>
 lea    rsi,[rip+0xdf6]        # 2064 <_IO_stdin_used+0x64>
 call   1040 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>
 jmp    1278 <print_frame(int, int)+0xb8>
 jmp    127d <print_frame(int, int)+0xbd>
 mov    eax,DWORD PTR [rbp-0x10]
 add    eax,0x1
 mov    DWORD PTR [rbp-0x10],eax
 jmp    11e6 <print_frame(int, int)+0x26>
 mov    rdi,QWORD PTR [rip+0x2d3e]        # 3fd0 <std::cout@GLIBCXX_3.4>
 mov    rsi,QWORD PTR [rip+0x2d27]        # 3fc0 <std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)@GLIBCXX_3.4>
 call   1050 <std::ostream::operator<<(std::ostream& (*)(std::ostream&))@plt>
 mov    eax,DWORD PTR [rbp-0xc]
 add    eax,0x1
 mov    DWORD PTR [rbp-0xc],eax
 jmp    11d5 <print_frame(int, int)+0x15>
 add    rsp,0x10
 pop    rbp
 ret
 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
main:
 push   rbp
 mov    rbp,rsp
 sub    rsp,0x20
 mov    DWORD PTR [rbp-0x4],0x0
 mov    DWORD PTR [rbp-0x8],0x1
 mov    DWORD PTR [rbp-0xc],0x1
 mov    eax,DWORD PTR [rbp-0x8]
 mov    DWORD PTR [rbp-0x10],eax
 mov    eax,DWORD PTR [rbp-0xc]
 mov    DWORD PTR [rbp-0x14],eax
 mov    edi,DWORD PTR [rbp-0x10]
 mov    esi,DWORD PTR [rbp-0x14]
 call   11c0 <print_frame(int, int)>
 mov    rdi,QWORD PTR [rip+0x2ce5]        # 3fe0 <std::cin@GLIBCXX_3.4>
 lea    rsi,[rbp-0x15]
 call   1060 <std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)@plt>
 movsx  eax,BYTE PTR [rbp-0x15]
 add    eax,0xffffff9f
 mov    ecx,eax
 mov    QWORD PTR [rbp-0x20],rcx
 sub    eax,0x16
 ja     1396 <main+0xd6>
 mov    rax,QWORD PTR [rbp-0x20]
 lea    rcx,[rip+0xcdf]        # 2004 <_IO_stdin_used+0x4>
 movsxd rax,DWORD PTR [rcx+rax*4]
 add    rax,rcx
 jmp    rax
 cmp    DWORD PTR [rbp-0x14],0x1
 jle    1341 <main+0x81>
 mov    eax,DWORD PTR [rbp-0x14]
 add    eax,0xffffffff
 mov    DWORD PTR [rbp-0x14],eax
 jmp    13bd <main+0xfd>
 cmp    DWORD PTR [rbp-0x14],0x8
 jae    1359 <main+0x99>
 mov    eax,DWORD PTR [rbp-0x14]
 add    eax,0x1
 mov    DWORD PTR [rbp-0x14],eax
 jmp    13bd <main+0xfd>
 cmp    DWORD PTR [rbp-0x10],0x1
 jle    1371 <main+0xb1>
 mov    eax,DWORD PTR [rbp-0x10]
 add    eax,0xffffffff
 mov    DWORD PTR [rbp-0x10],eax
 jmp    13bd <main+0xfd>
 cmp    DWORD PTR [rbp-0x10],0x8
 jae    1389 <main+0xc9>
 mov    eax,DWORD PTR [rbp-0x10]
 add    eax,0x1
 mov    DWORD PTR [rbp-0x10],eax
 jmp    13bd <main+0xfd>
 xor    eax,eax
 add    rsp,0x20
 pop    rbp
 ret
 mov    rdi,QWORD PTR [rip+0x2c33]        # 3fd0 <std::cout@GLIBCXX_3.4>
 lea    rsi,[rip+0xcc2]        # 2066 <_IO_stdin_used+0x66>
 call   1040 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>
 mov    rdi,rax
 mov    rsi,QWORD PTR [rip+0x2c0d]        # 3fc0 <std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)@GLIBCXX_3.4>
 call   1050 <std::ostream::operator<<(std::ostream& (*)(std::ostream&))@plt>
 jmp    12e9 <main+0x29>
 jmp    12e9 <main+0x29>