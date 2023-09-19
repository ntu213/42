bits 64

extern ft_strlen
extern ft_strcpy
extern __malloc_wrapper

section .text
	global ft_strdup

	ft_strdup:
		mov rbx, rdi
		call ft_strlen
		inc rax
		mov rdi, rax
		call __malloc_wrapper
		mov rdi, rax
		mov rsi, rbx
		call ft_strcpy
		ret
