	.file	"fileSort.c"
	.text
	.globl	file
	.bss
	.align 32
	.type	file, @object
	.size	file, 1000
file:
	.zero	1000
	.globl	n
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.zero	4
	.text
	.globl	lower
	.type	lower, @function
lower:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	cmpb	$64, -4(%rbp)
	jle	.L2
	cmpb	$90, -4(%rbp)
	jg	.L2
	movzbl	-4(%rbp), %eax
	addl	$32, %eax
	jmp	.L3
.L2:
	movzbl	-4(%rbp), %eax
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	lower, .-lower
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%s"
	.text
	.globl	takein
	.type	takein, @function
takein:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	n(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -4(%rbp)
	jmp	.L5
.L6:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	file(%rip), %rdx
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	addl	$1, -4(%rbp)
.L5:
	movl	n(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L6
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	takein, .-takein
	.globl	len
	.type	len, @function
len:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L8
.L9:
	addl	$1, -4(%rbp)
.L8:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L9
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	len, .-len
	.globl	notcopy
	.type	notcopy, @function
notcopy:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L12
.L13:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	leaq	-1(%rdx), %rcx
	movq	-32(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	addl	$1, -4(%rbp)
.L12:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	len
	cmpl	%eax, -4(%rbp)
	jl	.L13
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	notcopy, .-notcopy
	.globl	morePriority
	.type	morePriority, @function
morePriority:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$152, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-152(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-160(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jne	.L15
	movq	-152(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L15
	movl	$0, %eax
	jmp	.L21
.L15:
	movq	-152(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %ecx
	movq	-160(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, %edx
	negl	%edx
	cmovns	%edx, %eax
	cmpl	$32, %eax
	je	.L17
	movq	-152(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	lower
	movl	%eax, %ebx
	movq	-160(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	lower
	cmpb	%al, %bl
	jge	.L18
	movl	$1, %eax
	jmp	.L21
.L18:
	movq	-152(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	lower
	movl	%eax, %ebx
	movq	-160(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	lower
	cmpb	%al, %bl
	jle	.L19
	movl	$0, %eax
	jmp	.L21
.L17:
	movq	-152(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-160(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jge	.L20
	movl	$1, %eax
	jmp	.L21
.L20:
	movq	-152(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-160(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jle	.L19
	movl	$0, %eax
	jmp	.L21
.L19:
	movq	$0, -144(%rbp)
	movq	$0, -136(%rbp)
	movq	$0, -128(%rbp)
	movq	$0, -120(%rbp)
	movq	$0, -112(%rbp)
	movq	$0, -104(%rbp)
	movw	$0, -96(%rbp)
	movq	$0, -80(%rbp)
	movq	$0, -72(%rbp)
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movw	$0, -32(%rbp)
	leaq	-144(%rbp), %rdx
	movq	-152(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	notcopy
	leaq	-80(%rbp), %rdx
	movq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	notcopy
	leaq	-80(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	morePriority
.L21:
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L22
	call	__stack_chk_fail@PLT
.L22:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	morePriority, .-morePriority
	.globl	sort
	.type	sort, @function
sort:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -76(%rbp)
	movl	$0, -72(%rbp)
	movl	$0, -68(%rbp)
	movl	$0, -68(%rbp)
	jmp	.L24
.L28:
	movl	-68(%rbp), %eax
	movl	%eax, -76(%rbp)
	movl	-68(%rbp), %eax
	movl	%eax, -72(%rbp)
	jmp	.L25
.L27:
	movl	-76(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	file(%rip), %rdx
	leaq	(%rax,%rdx), %rcx
	movl	-72(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	file(%rip), %rdx
	addq	%rdx, %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	morePriority
	testb	%al, %al
	je	.L26
	movl	-72(%rbp), %eax
	movl	%eax, -76(%rbp)
.L26:
	addl	$1, -72(%rbp)
.L25:
	movl	n(%rip), %eax
	cmpl	%eax, -72(%rbp)
	jl	.L27
	movl	-68(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	file(%rip), %rdx
	addq	%rax, %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
	movl	-76(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	file(%rip), %rdx
	leaq	(%rax,%rdx), %rcx
	movl	-68(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	file(%rip), %rdx
	addq	%rdx, %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
	movl	-76(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	file(%rip), %rdx
	addq	%rax, %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	strcpy@PLT
	addl	$1, -68(%rbp)
.L24:
	movl	n(%rip), %eax
	cmpl	%eax, -68(%rbp)
	jl	.L28
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L29
	call	__stack_chk_fail@PLT
.L29:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	sort, .-sort
	.section	.rodata
.LC2:
	.string	"%s "
	.text
	.globl	output
	.type	output, @function
output:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	jmp	.L31
.L32:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	file(%rip), %rdx
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L31:
	movl	n(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L32
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	output, .-output
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	call	takein
	movl	$0, %eax
	call	sort
	movl	$0, %eax
	call	output
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits
