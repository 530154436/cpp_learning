	.text
	.globl _absdiff
_absdiff:
LFB0:
	cmpq	%rsi, %rdi
	jge	L2
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
L2:
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
LFE0:
	.globl _goto_absdiff
_goto_absdiff:
LFB1:
	cmpq	%rsi, %rdi
	jl	L5
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
L5:
	movq	%rsi, %rax
	subq	%rdi, %rax
L6:
	ret
LFE1:
	.globl _cmovdiff
_cmovdiff:
LFB2:
	movq	%rsi, %rdx
	subq	%rdi, %rdx
	movq	%rdi, %rax
	subq	%rsi, %rax
	cmpq	%rdi, %rsi
	jle	L7
	movq	%rdx, %rax
L7:
	ret
LFE2:
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
	.quad	LFB0-.
	.set L$set$2,LFE0-LFB0
	.quad L$set$2
	.byte	0
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$3,LEFDE3-LASFDE3
	.long L$set$3
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB1-.
	.set L$set$4,LFE1-LFB1
	.quad L$set$4
	.byte	0
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$5,LEFDE5-LASFDE5
	.long L$set$5
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB2-.
	.set L$set$6,LFE2-LFB2
	.quad L$set$6
	.byte	0
	.align 3
LEFDE5:
	.subsections_via_symbols
