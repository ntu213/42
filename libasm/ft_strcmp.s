bits 64

section .text
	global ft_strcmp

	ft_strcmp:
		mov rdi, rdi
		mov rsi, rsi
		mov rcx, 0

		loop:
			mov al, [rsi + rcx] ; &al == &rax; size(al) == 8, size(rax) == 64
			cmp byte [rdi + rcx], byte al
			jne loop_end ; si rdi[rcx] != rsi[rcx], loop_end

			cmp byte [rdi + rcx], 0
			je loop_end ; si rdi[rcx] == 0, loop_end

			inc rcx ; increment rcx
			jmp loop ; boucler
		
		loop_end:
			mov rax, 0
			mov al, [rdi + rcx]
			mov bl, [rsi + rcx]
			sub rax, rbx
			ret

			
