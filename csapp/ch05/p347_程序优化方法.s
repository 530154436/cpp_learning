	.text
	.globl _new_vec
_new_vec:
LFB3:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$16, %edi
	call	_malloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	L2
	movl	$0, %eax
	jmp	L3
L2:
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	cmpq	$0, -24(%rbp)
	jle	L4
	movq	-24(%rbp), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_calloc
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	L5
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_free
	movl	$0, %eax
	jmp	L3
L5:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	jmp	L6
L4:
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
L6:
	movq	-8(%rbp), %rax
L3:
	leave
LCFI2:
	ret
LFE3:
	.globl _get_vec_element
_get_vec_element:
LFB4:
	pushq	%rbp
LCFI3:
	movq	%rsp, %rbp
LCFI4:
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -16(%rbp)
	js	L8
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jl	L9
L8:
	movl	$0, %eax
	jmp	L10
L9:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-16(%rbp), %rax
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movl	$1, %eax
L10:
	popq	%rbp
LCFI5:
	ret
LFE4:
	.globl _vec_length
_vec_length:
LFB5:
	pushq	%rbp
LCFI6:
	movq	%rsp, %rbp
LCFI7:
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
LCFI8:
	ret
LFE5:
	.globl _combine1
_combine1:
LFB6:
	pushq	%rbp
LCFI9:
	movq	%rsp, %rbp
LCFI10:
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movl	$0, (%rax)
	movq	$0, -8(%rbp)
	jmp	L14
L15:
	leaq	-12(%rbp), %rax
	movq	-8(%rbp), %rsi
	movq	-24(%rbp), %rcx
	movq	%rax, %rdx
	movq	%rcx, %rdi
	call	_get_vec_element
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movl	-12(%rbp), %eax
	addl	%eax, %edx
	movq	-32(%rbp), %rax
	movl	%edx, (%rax)
	addq	$1, -8(%rbp)
L14:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_vec_length
	cmpq	%rax, -8(%rbp)
	jl	L15
	nop
	leave
LCFI11:
	ret
LFE6:
	.globl _combine2
_combine2:
LFB7:
	pushq	%rbp
LCFI12:
	movq	%rsp, %rbp
LCFI13:
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_vec_length
	movq	%rax, -16(%rbp)
	movq	-48(%rbp), %rax
	movl	$0, (%rax)
	movq	$0, -8(%rbp)
	jmp	L17
L18:
	leaq	-20(%rbp), %rax
	movq	-8(%rbp), %rsi
	movq	-40(%rbp), %rcx
	movq	%rax, %rdx
	movq	%rcx, %rdi
	call	_get_vec_element
	movq	-48(%rbp), %rax
	movl	(%rax), %edx
	movl	-20(%rbp), %eax
	addl	%eax, %edx
	movq	-48(%rbp), %rax
	movl	%edx, (%rax)
	addq	$1, -8(%rbp)
L17:
	movq	-8(%rbp), %rax
	cmpq	-16(%rbp), %rax
	jl	L18
	nop
	leave
LCFI14:
	ret
LFE7:
	.globl _get_vec_start
_get_vec_start:
LFB8:
	pushq	%rbp
LCFI15:
	movq	%rsp, %rbp
LCFI16:
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	popq	%rbp
LCFI17:
	ret
LFE8:
	.globl _combine3
_combine3:
LFB9:
	pushq	%rbp
LCFI18:
	movq	%rsp, %rbp
LCFI19:
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_vec_length
	movq	%rax, -16(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_get_vec_start
	movq	%rax, -24(%rbp)
	movq	-48(%rbp), %rax
	movl	$0, (%rax)
	movq	$0, -8(%rbp)
	jmp	L22
L23:
	movq	-48(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	addl	%eax, %edx
	movq	-48(%rbp), %rax
	movl	%edx, (%rax)
	addq	$1, -8(%rbp)
L22:
	movq	-8(%rbp), %rax
	cmpq	-16(%rbp), %rax
	jl	L23
	nop
	leave
LCFI20:
	ret
LFE9:
	.globl _combine4
_combine4:
LFB10:
	pushq	%rbp
LCFI21:
	movq	%rsp, %rbp
LCFI22:
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_vec_length
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_get_vec_start
	movq	%rax, -32(%rbp)
	movl	$0, -12(%rbp)
	movq	$0, -8(%rbp)
	jmp	L25
L26:
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	addl	%eax, -12(%rbp)
	addq	$1, -8(%rbp)
L25:
	movq	-8(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jl	L26
	movq	-48(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	nop
	leave
LCFI23:
	ret
LFE10:
	.globl _main
_main:
LFB11:
	pushq	%rbp
LCFI24:
	movq	%rsp, %rbp
LCFI25:
	movl	$0, %eax
	popq	%rbp
LCFI26:
	ret
LFE11:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB3-.
	.set L$set$2,LFE3-LFB3
	.quad L$set$2
	.byte	0
	.byte	0x4
	.set L$set$3,LCFI0-LFB3
	.long L$set$3
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$6,LEFDE3-LASFDE3
	.long L$set$6
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB4-.
	.set L$set$7,LFE4-LFB4
	.quad L$set$7
	.byte	0
	.byte	0x4
	.set L$set$8,LCFI3-LFB4
	.long L$set$8
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$9,LCFI4-LCFI3
	.long L$set$9
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$10,LCFI5-LCFI4
	.long L$set$10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$11,LEFDE5-LASFDE5
	.long L$set$11
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB5-.
	.set L$set$12,LFE5-LFB5
	.quad L$set$12
	.byte	0
	.byte	0x4
	.set L$set$13,LCFI6-LFB5
	.long L$set$13
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$14,LCFI7-LCFI6
	.long L$set$14
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$15,LCFI8-LCFI7
	.long L$set$15
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE5:
LSFDE7:
	.set L$set$16,LEFDE7-LASFDE7
	.long L$set$16
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB6-.
	.set L$set$17,LFE6-LFB6
	.quad L$set$17
	.byte	0
	.byte	0x4
	.set L$set$18,LCFI9-LFB6
	.long L$set$18
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$19,LCFI10-LCFI9
	.long L$set$19
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$20,LCFI11-LCFI10
	.long L$set$20
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE7:
LSFDE9:
	.set L$set$21,LEFDE9-LASFDE9
	.long L$set$21
LASFDE9:
	.long	LASFDE9-EH_frame1
	.quad	LFB7-.
	.set L$set$22,LFE7-LFB7
	.quad L$set$22
	.byte	0
	.byte	0x4
	.set L$set$23,LCFI12-LFB7
	.long L$set$23
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$24,LCFI13-LCFI12
	.long L$set$24
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$25,LCFI14-LCFI13
	.long L$set$25
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE9:
LSFDE11:
	.set L$set$26,LEFDE11-LASFDE11
	.long L$set$26
LASFDE11:
	.long	LASFDE11-EH_frame1
	.quad	LFB8-.
	.set L$set$27,LFE8-LFB8
	.quad L$set$27
	.byte	0
	.byte	0x4
	.set L$set$28,LCFI15-LFB8
	.long L$set$28
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$29,LCFI16-LCFI15
	.long L$set$29
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$30,LCFI17-LCFI16
	.long L$set$30
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE11:
LSFDE13:
	.set L$set$31,LEFDE13-LASFDE13
	.long L$set$31
LASFDE13:
	.long	LASFDE13-EH_frame1
	.quad	LFB9-.
	.set L$set$32,LFE9-LFB9
	.quad L$set$32
	.byte	0
	.byte	0x4
	.set L$set$33,LCFI18-LFB9
	.long L$set$33
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$34,LCFI19-LCFI18
	.long L$set$34
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$35,LCFI20-LCFI19
	.long L$set$35
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE13:
LSFDE15:
	.set L$set$36,LEFDE15-LASFDE15
	.long L$set$36
LASFDE15:
	.long	LASFDE15-EH_frame1
	.quad	LFB10-.
	.set L$set$37,LFE10-LFB10
	.quad L$set$37
	.byte	0
	.byte	0x4
	.set L$set$38,LCFI21-LFB10
	.long L$set$38
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$39,LCFI22-LCFI21
	.long L$set$39
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$40,LCFI23-LCFI22
	.long L$set$40
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE15:
LSFDE17:
	.set L$set$41,LEFDE17-LASFDE17
	.long L$set$41
LASFDE17:
	.long	LASFDE17-EH_frame1
	.quad	LFB11-.
	.set L$set$42,LFE11-LFB11
	.quad L$set$42
	.byte	0
	.byte	0x4
	.set L$set$43,LCFI24-LFB11
	.long L$set$43
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$44,LCFI25-LCFI24
	.long L$set$44
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$45,LCFI26-LCFI25
	.long L$set$45
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE17:
	.subsections_via_symbols
