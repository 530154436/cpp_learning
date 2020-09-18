//
// Created by Edward on 2020/3/12.
//
#include <inttypes.h>
/**
    CSAPP
    x in %rdi(第1个参数)、y in %rsi、qp in %rdx、rp in %rcx

    movq	%rdx, %r8           copy qp
    movq	%rdi, %rax          Move x to lower 8 bytes of dividend
	cqto                        sign-extend to upper 8 bytes of dividend
	idivq	%rsi                divide by y
	movq	%rax, (%r8)         store 商 at qp
	movq	%rdx, (%rcx)        store 余数 at rp
	ret
	ret
 */
void remdiv(long x, long y, long *qp, long *rp){
    long q = x/y;
    long r = x%y;
    *qp = q;
    *rp = r;
}
