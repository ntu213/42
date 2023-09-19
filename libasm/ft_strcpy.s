bits 64

section .text
	global ft_strcpy

	ft_strcpy:
		mov rdi, rdi
		mov rsi, rsi
		mov rcx, 0

		loop:
			cmp byte [rsi + rcx], 0
			je loop_end

			mov al, [rsi, rcx]
			mov [rdi + rcx], al
			inc rcx
			jmp loop
		
		loop_end:
			mov byte [rdi + rcx], 0
			mov rax, rdi
			ret