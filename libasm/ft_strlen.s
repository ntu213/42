bits 64

section .text
	global ft_strlen

	ft_strlen:
		mov rdi, rdi
		mov rcx, 0

		cmp rdi, 0
		je loop_end

		loop:
			cmp byte [rdi + rcx], 0 ; comparer les 8 premiers bits de rdi[rcx] et 0
			je loop_end ; si ==, executer loop_end

			inc rcx ; incrementer rcx
			jmp loop ; revenir au debut de loop

		loop_end:
			mov rax, rcx ; rax = rcx
			ret ; return (rax)
