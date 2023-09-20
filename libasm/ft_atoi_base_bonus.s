bits 64

extern ft_strlen

section .text
	global ft_atoi_base
	global ft_atoi_base_recursive

; ft_getpos:
;         push    rbp
;         mov     rbp, rsp
;         mov     QWORD [rbp-24], rdi
;         mov     eax, esi
;         mov     BYTE [rbp-28], al
;         mov     DWORD [rbp-4], 0
;         jmp     .L2
; .L4:
;         add     DWORD [rbp-4], 1
; .L2:
;         mov     eax, DWORD [rbp-4]
;         movsx   rdx, eax
;         mov     rax, QWORD [rbp-24]
;         add     rax, rdx
;         movzx   eax, BYTE [rax]
;         test    al, al
;         je      .L6
;         mov     eax, DWORD [rbp-4]
;         movsx   rdx, eax
;         mov     rax, QWORD [rbp-24]
;         add     rax, rdx
;         movzx   eax, BYTE [rax]
;         cmp     BYTE [rbp-28], al
;         jne     .L4
;         nop
; .L6:
;         nop
;         pop     rbp
;         ret

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
		mov r14, 0
		; mov r14, rdx
		mov r13, rdi
		mov rdi, rsi
		call ft_strlen
		mov r12, rax

		rec_loop:
			cmp byte [r13 + r14], 0
			je stop_recursive
			imul r15, r12
			mov rsi, [r13 + r14]
			call ft_getpos
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

		dec r14

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
		jmp loop1

		invert:
			imul r13, -1
			jmp loop1

		loop1:
			inc r14
			cmp byte [rdi + r14], 45 ; '-'
			je invert
			cmp byte [rdi + r14], 43 ; '+'
			je loop1

		mov rdi, rbx
		mov rsi, rcx
		push rdx
		mov rdx, 0
		mov rdx, r14
		call ft_atoi_base_recursive
		pop rdx
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
