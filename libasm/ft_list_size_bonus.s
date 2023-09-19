bits 64

section .text
	global ft_list_size

	ft_list_size:
		push rbx ; compteur
		push rcx ; pointeur structure
		mov rbx, 0
		mov rcx, rdi

		loop:
			cmp rcx, 0
			je loop_end
			inc rbx
			mov rcx, qword [rcx + 8] ; qword [rcx + 8] ~= (t_lst *)rcx->next; [rcx] = *rcx
			jmp loop

		loop_end:
			mov rax, rbx
			pop rcx
			pop rbx
			ret
