	.file	"maze.c"
	.comm	stack,4096,32
.globl top
	.bss
	.align 4
	.type	top, @object
	.size	top, 4
top:
	.zero	4
	.text
.globl push
	.type	push, @function
push:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -16(%rbp)
	movl	top(%rip), %eax
	movslq	%eax, %rdx
	movq	-16(%rbp), %rcx
	movq	%rcx, stack(,%rdx,8)
	addl	$1, %eax
	movl	%eax, top(%rip)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	push, .-push
.globl pop
	.type	pop, @function
pop:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	top(%rip), %eax
	subl	$1, %eax
	movl	%eax, top(%rip)
	movl	top(%rip), %eax
	cltq
	movq	stack(,%rax,8), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	pop, .-pop
.globl is_empty
	.type	is_empty, @function
is_empty:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	top(%rip), %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	is_empty, .-is_empty
.globl maze
	.data
	.align 32
	.type	maze, @object
	.size	maze, 100
maze:
	.long	0
	.long	1
	.long	0
	.long	1
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1
	.long	1
	.long	1
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1
	.long	0
	.section	.rodata
.LC0:
	.string	"%d "
.LC1:
	.string	"*********"
	.text
.globl print_maze
	.type	print_maze, @function
print_maze:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L8
.L11:
	movl	$0, -4(%rbp)
	jmp	.L9
.L10:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movl	$.LC0, %eax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L9:
	cmpl	$4, -4(%rbp)
	jle	.L10
	movl	$10, %edi
	call	putchar
	addl	$1, -8(%rbp)
.L8:
	cmpl	$4, -8(%rbp)
	jle	.L11
	movl	$.LC1, %edi
	call	puts
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	print_maze, .-print_maze
.globl predecessor
	.data
	.align 32
	.type	predecessor, @object
	.size	predecessor, 200
predecessor:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.text
.globl visit
	.type	visit, @function
visit:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-20(%rbp), %eax
	movl	-24(%rbp), %edx
	movslq	%edx, %rcx
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	$2, maze(,%rax,4)
	movl	-20(%rbp), %eax
	movl	-24(%rbp), %edx
	movslq	%edx, %rcx
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	(%rax,%rcx), %rdx
	movq	-32(%rbp), %rax
	movq	%rax, predecessor(,%rdx,8)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	push
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	visit, .-visit
	.section	.rodata
.LC2:
	.string	"(%d, %d)\n"
.LC3:
	.string	"No path!"
	.text
.globl main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -16(%rbp)
	movl	$0, -12(%rbp)
	movl	-16(%rbp), %eax
	movl	-12(%rbp), %edx
	movslq	%edx, %rcx
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	$2, maze(,%rax,4)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	push
	jmp	.L16
.L23:
	call	pop
	movq	%rax, -16(%rbp)
	movl	-16(%rbp), %eax
	cmpl	$4, %eax
	jne	.L17
	movl	-12(%rbp), %eax
	cmpl	$4, %eax
	je	.L29
.L17:
	movl	-12(%rbp), %eax
	addl	$1, %eax
	cmpl	$4, %eax
	jg	.L19
	movl	-16(%rbp), %eax
	movl	-12(%rbp), %edx
	addl	$1, %edx
	movslq	%edx, %rcx
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	maze(,%rax,4), %eax
	testl	%eax, %eax
	jne	.L19
	movl	-12(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-16(%rbp), %eax
	movq	-16(%rbp), %rdx
	movl	%ecx, %esi
	movl	%eax, %edi
	call	visit
.L19:
	movl	-16(%rbp), %eax
	addl	$1, %eax
	cmpl	$4, %eax
	jg	.L20
	movl	-16(%rbp), %eax
	leal	1(%rax), %edx
	movl	-12(%rbp), %eax
	movslq	%eax, %rcx
	movslq	%edx, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	maze(,%rax,4), %eax
	testl	%eax, %eax
	jne	.L20
	movl	-12(%rbp), %eax
	movl	-16(%rbp), %edx
	leal	1(%rdx), %ecx
	movq	-16(%rbp), %rdx
	movl	%eax, %esi
	movl	%ecx, %edi
	call	visit
.L20:
	movl	-12(%rbp), %eax
	subl	$1, %eax
	testl	%eax, %eax
	js	.L21
	movl	-16(%rbp), %eax
	movl	-12(%rbp), %edx
	subl	$1, %edx
	movslq	%edx, %rcx
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	maze(,%rax,4), %eax
	testl	%eax, %eax
	jne	.L21
	movl	-12(%rbp), %eax
	leal	-1(%rax), %ecx
	movl	-16(%rbp), %eax
	movq	-16(%rbp), %rdx
	movl	%ecx, %esi
	movl	%eax, %edi
	call	visit
.L21:
	movl	-16(%rbp), %eax
	subl	$1, %eax
	testl	%eax, %eax
	js	.L22
	movl	-16(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-12(%rbp), %eax
	movslq	%eax, %rcx
	movslq	%edx, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	maze(,%rax,4), %eax
	testl	%eax, %eax
	jne	.L22
	movl	-12(%rbp), %eax
	movl	-16(%rbp), %edx
	leal	-1(%rdx), %ecx
	movq	-16(%rbp), %rdx
	movl	%eax, %esi
	movl	%ecx, %edi
	call	visit
.L22:
	movl	$maze, %edi
	call	print_maze
.L16:
	call	is_empty
	testl	%eax, %eax
	je	.L23
	jmp	.L18
.L29:
	nop
.L18:
	movl	-16(%rbp), %eax
	cmpl	$4, %eax
	jne	.L24
	movl	-12(%rbp), %eax
	cmpl	$4, %eax
	jne	.L24
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %ecx
	movl	$.LC2, %eax
	movl	%ecx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	jmp	.L25
.L26:
	movl	-16(%rbp), %eax
	movl	-12(%rbp), %edx
	movslq	%edx, %rcx
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movq	predecessor(,%rax,8), %rax
	movq	%rax, -16(%rbp)
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %ecx
	movl	$.LC2, %eax
	movl	%ecx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
.L25:
	movl	-16(%rbp), %eax
	movl	-12(%rbp), %edx
	movslq	%edx, %rcx
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	predecessor(,%rax,8), %eax
	cmpl	$-1, %eax
	jne	.L26
	jmp	.L27
.L24:
	movl	$.LC3, %edi
	call	puts
.L27:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-4)"
	.section	.note.GNU-stack,"",@progbits
