bits 64

section .text
	global ft_list_sort

	ft_swap_1: ; rdi = 1st elem de la chaine

		cmp rdi, 0 ; t_lst **
		je ft_exit1
		cmp rsi, 0 ; arg1
		je ft_exit1
		cmp rdx, 0 ; arg1->next
		je ft_exit1

		mov rax, qword [rdx + 8]
		mov qword [rsi + 8], rax
		mov qword [rdi], rdx
		mov qword [rdx + 8], rsi

		ft_exit1:
			ret

	ft_swap_2: ; rdi = prev

		cmp rdi, 0 ; prev
		je ft_exit2
		cmp rsi, 0 ; arg1
		je ft_exit2
		cmp rdx, 0 ; arg1->next
		je ft_exit2

		mov qword [rdi + 8], rdx
		mov rax, qword [rdx + 8]
		mov qword [rsi + 8], rax
		mov qword [rdx + 8], rsi

		ft_exit2:
			ret

	check_swapped:
		mov rcx, qword [r15]
		mov rbx, qword [rcx + 8]
		loop1:
			mov rdi, qword [rcx]
			mov rsi, qword [rbx]
			call r14
			cmp rax, 0
			jne ft_exit4
			mov rcx, qword [rcx + 8]
			mov rbx, qword [rbx + 8]
			cmp rbx, 0
			je ft_exit3
			jmp loop1

		ft_exit3:
			mov rax, 0
			ret

		ft_exit4:
			mov rax, 1
			ret

	ft_list_sort:
		; rdi = t_lst **
		; rsi = (*ft)()
		push rbx
		push rcx
		push rdx
		push r15
		push r14
		push r13
		push r12

		checker:
			cmp rdi, 0
			je ft_exit
			cmp rsi, 0
			je ft_exit
			cmp qword [rdi], 0
			je ft_exit

		mov r15, rdi
		mov r14, rsi
		reset:
			mov r13, qword [r15] ; pointeur actuel
			mov r12, qword [r13 + 8] ; r13->next
			mov r11, 0 ; r13->prev

		cmp r12, 0
		je ft_exit

		call check_swapped
		cmp rax, 0
		je ft_exit

		; tests
		; mov rdi, rdi
		; mov rsi, r13
		; mov rdx, qword [r13 + 8]
		; call ft_swap_1

		; mov rdi, r13
		; mov rsi, qword [r13 + 8]
		; mov rdx, qword [rsi + 8]
		; call ft_swap_2

		loop:
			mov rdi, qword [r13]
			mov rsi, qword [r12]
			call r14
			cmp rax, 0 ; si r14(r13->data, r12->data) > 0, swap
			jg swapper
			mov r11, r13
			mov r13, r12
			mov r12, qword [r12 + 8]
			cmp r12, 0
			je reset
			jmp loop

		ft_swap_1_0:
			call ft_swap_1
			jmp loop

		swapper: ; choisir quel swap utiliser
			mov rdi, r15
			mov rsi, r13
			mov rdx, r12
			cmp rsi, qword [r15]
			je ft_swap_1_0
			mov rdi, r11
			call ft_swap_2
			jmp reset

		ft_exit:
			pop r12
			pop r13
			pop r14
			pop r15
			pop rdx
			pop rcx
			pop rbx
			ret
