	.file	"sort.c"
	.text
	.p2align 4
	.globl	swap
	.type	swap, @function
swap:
.LFB0:
	.cfi_startproc
	endbr64
	movl	(%rdi), %eax
	movl	(%rsi), %edx
	movl	%edx, (%rdi)
	movl	%eax, (%rsi)
	ret
	.cfi_endproc
.LFE0:
	.size	swap, .-swap
	.p2align 4
	.globl	array_sort
	.type	array_sort, @function
array_sort:
.LFB1:
	.cfi_startproc
	endbr64
	movl	%edx, %ecx
	leal	-1(%rdx), %edx
	testl	%ecx, %ecx
	jle	.L4
	leaq	15(%rsi), %rax
	subq	%rdi, %rax
	cmpq	$30, %rax
	jbe	.L5
	cmpl	$3, %edx
	jbe	.L5
	movl	%ecx, %r8d
	xorl	%eax, %eax
	shrl	$2, %r8d
	salq	$4, %r8
	.p2align 4,,10
	.p2align 3
.L6:
	movdqu	(%rdi,%rax), %xmm0
	movups	%xmm0, (%rsi,%rax)
	addq	$16, %rax
	cmpq	%r8, %rax
	jne	.L6
	movl	%ecx, %eax
	andl	$-4, %eax
	testb	$3, %cl
	je	.L9
	movl	%eax, %r8d
	movl	(%rdi,%r8,4), %r9d
	movl	%r9d, (%rsi,%r8,4)
	leal	1(%rax), %r8d
	cmpl	%r8d, %ecx
	jle	.L9
	movslq	%r8d, %r8
	addl	$2, %eax
	movl	(%rdi,%r8,4), %r9d
	movl	%r9d, (%rsi,%r8,4)
	cmpl	%eax, %ecx
	jle	.L9
	cltq
	movl	(%rdi,%rax,4), %ecx
	movl	%ecx, (%rsi,%rax,4)
.L9:
	leaq	4(%rsi), %r9
	.p2align 4,,10
	.p2align 3
.L11:
	subl	$1, %edx
	movq	%rsi, %rax
	movq	%rdx, %r8
	leaq	(%r9,%rdx,4), %rdi
	.p2align 4,,10
	.p2align 3
.L13:
	movl	(%rax), %edx
	movl	4(%rax), %ecx
	cmpl	%ecx, %edx
	jle	.L12
	movl	%ecx, (%rax)
	movl	%edx, 4(%rax)
.L12:
	addq	$4, %rax
	cmpq	%rdi, %rax
	jne	.L13
	movl	%r8d, %edx
	testl	%r8d, %r8d
	jne	.L11
	ret
.L5:
	movl	%edx, %r8d
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L8:
	movl	(%rdi,%rax,4), %ecx
	movl	%ecx, (%rsi,%rax,4)
	movq	%rax, %rcx
	addq	$1, %rax
	cmpq	%r8, %rcx
	jne	.L8
.L4:
	testl	%edx, %edx
	jg	.L9
	ret
	.cfi_endproc
.LFE1:
	.size	array_sort, .-array_sort
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
