bits 64

%define tab r15
%define ref r14
%define cmp_ft r13
%define free_ft r12
%define current r11
%define prev r10
%define cache r9


section .text
	global ft_list_remove_if

	ft_realloc:
		mov qword [tab], cache
		jmp rm2
	
	ft_edit:
		mov qword [prev + 8], cache
		jmp rm2

	remove:
		mov cache, qword [current + 8]
		cmp current, qword [tab]
		je ft_realloc
		jmp ft_edit

		rm2:
		mov rdi, current
		call free_ft
		mov current, cache
		cmp current, 0
		je ft_exit
		jmp loop

	ft_list_remove_if:

		push r15
		push r14
		push r13
		push r12
		push r11
		push r10
		push r9

		checker:
		cmp rdi, 0
		je ft_exit
		cmp rsi, 0
		je ft_exit
		cmp rdx, 0
		je ft_exit
		cmp rcx, 0
		je ft_exit
		cmp qword [rdi], 0
		je ft_exit

		mov tab, rdi
		mov ref, rsi
		mov cmp_ft, rdx
		mov free_ft, rcx
		mov current, qword [rdi]
		mov prev, 0

		loop:
			mov rdi, qword [current]
			mov rsi, ref
			call cmp_ft
			cmp rax, 1
			je remove
			mov prev, current
			mov current, qword [current + 8]
			cmp current, 0
			je ft_exit
			jmp loop

		ft_exit:
			pop r9
			pop r10
			pop r11
			pop r12
			pop r13
			pop r14
			pop r15
			ret
