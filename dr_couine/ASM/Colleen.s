bits 64

extern printf

section .data
	str: db "bits 64%2$c%2$cextern printf%2$c%2$csection .data%2$c	str: db %3$c%1$s%3$c, 0%2$c%2$c%4$c hop la le p'tit commentaire%2$csection .text%2$c	global main%2$c%2$c	ft:%2$c		ret%2$c%2$c	main: %4$c et voici le main%2$c		push rbp%2$c		call ft%2$c		lea rdi, [str]%2$c		lea rsi, [str]%2$c		mov rdx, 10%2$c		mov rcx, 34%2$c		mov r8, 59%2$c		mov rax, 0%2$c		call printf%2$c		pop rbp%2$c		ret%2$c", 0

; hop la le p'tit commentaire
section .text
	global main

	ft:
		ret

	main: ; et voici le main
		push rbp
		call ft
		lea rdi, [str]
		lea rsi, [str]
		mov rdx, 10
		mov rcx, 34
		mov r8, 59
		mov rax, 0
		call printf
		pop rbp
		ret
