global _start:
	

section .data
message: db 'Hello!', 10

section .text
_start:
	mov rax, 1		; write system call
	mov rdi, 1		; file descriptor (stdin 0, stdout 1, stderr 2)
	mov rsi, message	; memory address of the text
	mov rdx, 7		; Number of bytes 
	syscall
	mov rax, 60		; exit system call
	xor rdi,rdi		; rdi =0
	syscall
	
	
;  Syscall calling convention
;  Syscall number -> rax
;  Maximum 6 arguments. And in the exact order:
;  rdi, rsi, rdx, r10, r8. r9
;  Return value in rax
;  Syscall changes these two registers (clobbers):
;  rcx, r11
;
;  On Ubuntu, syscall name -> number mapping: /usr/include/x86_64-linux-gnu/asm/unistd_64.h


