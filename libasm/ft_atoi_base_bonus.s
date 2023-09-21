bits 64

extern ft_strlen
extern ft_test

section .text
	global ft_atoi_base

	ft_getpos:

		mov rax, rsi
		mov bl, al
		mov rax, 0

		myloop:

			cmp byte [rdi + rax], 0
			je mystop
			cmp byte [rdi + rax], bl
			je mystop
			inc rax
			jmp myloop
		
		mystop:
			ret

	ft_atoi_base_recursive:

		push r15 ; count
		push r14 ; increment
		push r13 ; cache
		push r12 ; len

		mov r15, 0
		mov r13, rdi
		mov rdi, rsi
		call ft_strlen
		mov r12, rax

		rec_loop:
			cmp byte [r13 + r14], 0
			je stop_recursive
			mov rsi, [r13 + r14]
			call ft_getpos
			cmp rax, r12
			je stop_recursive
			imul r15, r12
			add r15, rax
			inc r14
			jmp rec_loop

		stop_recursive:
			mov rax, r15
			pop r12
			pop r13
			pop r14
			pop r15
			ret

	ft_atoi_base:
		
		push r15 ; int res
		push r14 ; increment
		push r13 ; negative
		push r12 ; length
		push rbx ; arg 0
		push rcx ; arg 1
		mov rax, 0

		cmp rdi, 0 ; ft_list_push_front(A, B); if !A || !B then return
		je ft_error
		cmp rsi, 0
		je ft_error

		mov r15, 0
		mov r14, -1
		mov r13, 1
		mov rbx, rdi
		mov rcx, rsi
		mov rdi, rsi
		push rcx
		call ft_strlen
		pop rcx
		mov r12, rax

		check_illegual:
			inc r14
			cmp byte [rsi + r14], 0 ; '\0'
			je breaker
			cmp byte [rsi + r14], 32 ; ' '
			je ft_error
			cmp byte [rsi + r14], 9 ; '\t'
			je ft_error
			cmp byte [rsi + r14], 10 ; '\n'
			je ft_error
			cmp byte [rsi + r14], 11 ; '\v'
			je ft_error
			cmp byte [rsi + r14], 12 ; '\f'
			je ft_error
			cmp byte [rsi + r14], 13 ; '\r'
			je ft_error
			cmp byte [rsi + r14], 45 ; '-'
			je ft_error
			cmp byte [rsi + r14], 43 ; '+'
			je ft_error
			jmp check_illegual

		breaker:
			nop

		mov r14, -1

		loop0:
			inc r14
			cmp byte [rbx + r14], 32 ; ' '
			je loop0
			cmp byte [rbx + r14], 9 ; '\t'
			je loop0
			cmp byte [rbx + r14], 10 ; '\n'
			je loop0
			cmp byte [rbx + r14], 11 ; '\v'
			je loop0
			cmp byte [rbx + r14], 12 ; '\f'
			je loop0
			cmp byte [rbx + r14], 13 ; '\r'
			je loop0

		dec r14
		jmp loop1

		invert:
			neg r13
			jmp loop1

		loop1:
			inc r14
			cmp byte [rbx + r14], 45 ; '-'
			je invert
			cmp byte [rbx + r14], 43 ; '+'
			je loop1

		mov rdi, rbx
		mov rsi, rcx
		call ft_atoi_base_recursive
		imul rax, r13
		jmp ft_exit

		ft_error:
			mov rax, 0
			jmp ft_exit

		ft_exit:
			pop rcx
			pop rbx
			pop r12
			pop r13
			pop r14
			pop r15
			ret
