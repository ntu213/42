bits 64

extern __malloc_wrapper

section .text
	global ft_list_push_front

	ft_list_push_front:
		mov rdi, rdi
		mov rsi, rsi
		push rbx ; pointeur old first
		push rcx ; pointeur new first
		push r8 ; cache arg 0
		push r9 ; cache arg 1

;		cmp rdi, 0 ; ft_list_push_front(A, B); if !A || !B then return
;		je ft_exit
		cmp rsi, 0
		je ft_exit

		mov r8, rdi
		mov r9, rsi

		push r8
		push r9

		mov qword rdi, 16
		call __malloc_wrapper
		mov rcx, rax

		pop r9
		pop r8

		mov qword [rcx], r9

		mov rbx, qword [r8]
		mov qword [r8], rcx
		mov qword [rcx + 8], rbx

		ft_exit:
			pop r9
			pop r8
			pop rcx
			pop rbx
			ret
