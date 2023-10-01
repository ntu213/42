bits 64

extern fprintf
extern fopen

%define FILENAME "Grace_kid.s"
%define MAIN global main
%define MAIN_FUNC main:

section .data
	filename: db FILENAME, 0
	flag: db "w", 0
	str: db "bits 64%2$c%2$cextern fprintf%2$cextern fopen%2$c%2$c%%define FILENAME %3$cGrace_kid.s%3$c%2$c%%define MAIN global main%2$c%%define MAIN_FUNC main:%2$c%2$csection .data%2$c	filename: db FILENAME, 0%2$c	flag: db %3$cw%3$c, 0%2$c	str: db %3$c%1$s%3$c, 0%2$c%2$c%4$c hop la le p'tit commentaire%2$csection .text%2$c	MAIN%2$c%2$c	MAIN_FUNC%2$c		push rbx%2$c		mov rdi, filename%2$c		mov rsi, flag%2$c		call fopen%2$c%2$c		mov rdi, rax%2$c		mov rsi, str%2$c		mov rdx, str%2$c		mov rcx, 10%2$c		mov r8, 34%2$c		mov r9, 59%2$c		mov rax, 0%2$c		call fprintf%2$c		mov rax, 0%2$c		pop rbx%2$c		ret%2$c", 0

; hop la le p'tit commentaire
section .text
	MAIN

	MAIN_FUNC
		push rbx
		mov rdi, filename
		mov rsi, flag
		call fopen

		mov rdi, rax
		mov rsi, str
		mov rdx, str
		mov rcx, 10
		mov r8, 34
		mov r9, 59
		mov rax, 0
		call fprintf
		mov rax, 0
		pop rbx
		ret
