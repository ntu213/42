bits 64

extern ft_strlen

section .text
	global ft_atoi_base

	ft_getpos:

		push r14 ; increment
		push r13 ; cache

		mov r14, -1
		mov r13, 0

		myloop:
			inc r14
			cmp byte [rdi + r14], 0
			je mystop
			mov al, [rdi]
			cmp byte [rdi + r14], al
			je mystop
			jmp myloop

		mystop:
			mov rax, r14
			pop r13
			pop r14
			ret

	ft_atoi_base_recursive:

		push r15 ; count
		push r14 ; increment
		push r13 ; cache

		mov r15, 0
		mov r14, -1

		rec_loop:
			inc r14
			cmp byte [rdi + r14], 0
			je stop_recursive
			call ft_getpos
			mov r13, rax
			cmp r13, r12
			je stop_recursive
			mov rax, r15
			mul r12
			mov r15, rax
			add r15, r13
			jmp rec_loop

		stop_recursive:
			mov rax, r15
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
		je ft_exit
		cmp rsi, 0
		je ft_exit

		mov r15, 0
		mov r14, -1
		mov r13, 1
		mov rbx, rdi
		mov rcx, rsi
		mov rdi, rsi
		call ft_strlen
		mov r12, rax

		check_illegual:
			inc r14
			cmp byte [rsi + r14], 0 ; '\0'
			je breaker
			cmp byte [rsi + r14], 32 ; ' '
			je ft_exit
			cmp byte [rsi + r14], 9 ; '\t'
			je ft_exit
			cmp byte [rsi + r14], 10 ; '\n'
			je ft_exit
			cmp byte [rsi + r14], 11 ; '\v'
			je ft_exit
			cmp byte [rsi + r14], 12 ; '\f'
			je ft_exit
			cmp byte [rsi + r14], 13 ; '\r'
			je ft_exit
			cmp byte [rsi + r14], 45 ; '-'
			je ft_exit
			cmp byte [rsi + r14], 43 ; '+'
			je ft_exit

		breaker:
			nop

		mov r14, -1

		loop0:
			inc r14
			cmp byte [rdi + r14], 32 ; ' '
			je loop0
			cmp byte [rdi + r14], 9 ; '\t'
			je loop0
			cmp byte [rdi + r14], 10 ; '\n'
			je loop0
			cmp byte [rdi + r14], 11 ; '\v'
			je loop0
			cmp byte [rdi + r14], 12 ; '\f'
			je loop0
			cmp byte [rdi + r14], 13 ; '\r'
			je loop0

		dec r14

		invert:
			imul r13, -1
			jmp loop1

		loop1:
			inc r14
			cmp byte [rdi + r14], 45 ; '-'
			je invert
			cmp byte [rdi + r14], 43 ; '+'
			je loop0
		
		dec r14

		call ft_atoi_base_recursive
		imul rax, r13

		ft_exit:
			pop rcx
			pop rbx
			pop r12
			pop r13
			pop r14
			pop r15
			ret
