section .data
	msg db "hello world", 0x0A

section .text
		global _main
		global _ft_strlen

_ft_strlen:
	mov rax, 0
	jmp count

count: 
	cmp BYTE [rdi + rax], 0
	je	end
	inc rax
	jmp count

end:
	ret

_main :
		mov rax, 0x2000004
		mov rdi, 1
		mov rsi, msg
		mov rdx, 12
		syscall
		mov rax, 0x2000004
		
		mov rax, 0x2000001
		mov rdi, 0
		syscall
