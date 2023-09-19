bits 64

extern __errno_wrapper

section .text
	global ft_write

	ft_write:
		mov rax, 1

		mov rdi, rdi
		mov rsi, rsi
		mov rdx, rdx
		syscall

		cmp rax, 0
		jl label
		ret
	
	label:
		neg rax
		mov rdi, rax
		call __errno_wrapper
		mov [rax], rdi
		mov rax, -1
		ret
