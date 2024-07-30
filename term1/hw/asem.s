.global _start

section .text:
		mov $0x4, %exa
		mov $1, %ebx
		mov message, %ecx
		mov message_lenth, %edx
		int 0x80

section .data:
		message: db "Hello World!", 0xA
		message_lenth equ $-message


