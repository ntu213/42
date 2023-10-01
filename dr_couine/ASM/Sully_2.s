bits 64

extern fprintf
extern sprintf
extern printf
extern access
extern system
extern fopen
extern fclose

section .data
	specific_name: db "Sully_5.s", 0
	execname: db "Sully_%d", 0
	filename: db "%s.s", 0
	command: db "nasm -f elf64 %1$s && gcc -no-pie %2$s.o -o %2$s -lm && ./%2$s", 0
	flag: db "w", 0
	str: db "bits 64%1$c%1$cextern fprintf%1$cextern sprintf%1$cextern printf%1$cextern access%1$cextern system%1$cextern fopen%1$cextern fclose%1$c%1$csection .data%1$c	specific_name: db %3$cSully_5.s%3$c, 0%1$c	execname: db %3$cSully_%%d%3$c, 0%1$c	filename: db %3$c%%s.s%3$c, 0%1$c	command: db %3$cnasm -f elf64 %%1$s && gcc -no-pie %%2$s.o -o %%2$s -lm && ./%%2$s%3$c, 0%1$c	flag: db %3$cw%3$c, 0%1$c	str: db %3$c%2$s%3$c, 0%1$c%1$csection .bss%1$c	exec: resb 15%1$c	file: resb 15%1$c	cmd: resb 255%1$c	res: resb 1%1$c%1$csection .text%1$c	global main%1$c%1$c	main:%1$c		push rbx%1$c		mov rbx, %4$d%1$c		cmp rbx, 0%1$c		je exit%1$c	execute_acces:%1$c		lea rdi, [specific_name]%1$c		mov rsi, 4%1$c		call access%1$c		mov [res], rax%1$c		cmp dword [res], -1%1$c		je skip%1$c		sub rbx, 1%1$c	skip:%1$c		lea rdi, [exec]%1$c		lea rsi, [execname]%1$c		mov rdx, rbx%1$c		call sprintf%1$c		lea rdi, [file]%1$c		lea rsi, [filename]%1$c		mov rdx, exec%1$c		call sprintf%1$c	opener:%1$c		mov rdi, file%1$c		mov rsi, flag%1$c		call fopen%1$c	writer:%1$c		mov rdi, rax%1$c		mov r15, rax%1$c		mov rsi, str%1$c		mov rdx, 10%1$c		mov rcx, str%1$c		mov r8, 34%1$c		mov r9, rbx%1$c		mov rax, 0%1$c		call fprintf%1$c		mov rdi, r15%1$c		call fclose%1$c	execute:%1$c		lea rdi, [cmd]%1$c		lea rsi, [command]%1$c		mov rdx, file%1$c		mov rcx, exec%1$c		call sprintf%1$c		lea rdi, [cmd]%1$c		call system%1$c	exit:%1$c		pop rbx%1$c		ret%1$c", 0

section .bss
	exec: resb 15
	file: resb 15
	cmd: resb 255
	res: resb 1

section .text
	global main

	main:
		push rbx
		mov rbx, 2
		cmp rbx, 0
		je exit
	execute_acces:
		lea rdi, [specific_name]
		mov rsi, 4
		call access
		mov [res], rax
		cmp dword [res], -1
		je skip
		sub rbx, 1
	skip:
		lea rdi, [exec]
		lea rsi, [execname]
		mov rdx, rbx
		call sprintf
		lea rdi, [file]
		lea rsi, [filename]
		mov rdx, exec
		call sprintf
	opener:
		mov rdi, file
		mov rsi, flag
		call fopen
	writer:
		mov rdi, rax
		mov r15, rax
		mov rsi, str
		mov rdx, 10
		mov rcx, str
		mov r8, 34
		mov r9, rbx
		mov rax, 0
		call fprintf
		mov rdi, r15
		call fclose
	execute:
		lea rdi, [cmd]
		lea rsi, [command]
		mov rdx, file
		mov rcx, exec
		call sprintf
		lea rdi, [cmd]
		call system
	exit:
		pop rbx
		ret
