
include 'win32a.inc'

format PE console
entry start

section '.data' data readable writeable
buffer db 2 dup(0)
x dd 0

	
section '.text' code readable executable
start:
	lea edi, [buffer]
	mov ecx, 2
	call read_line
	mov esi, buffer
	call print_str
	push	0
	call	[ExitProcess]

include 'training.inc'
