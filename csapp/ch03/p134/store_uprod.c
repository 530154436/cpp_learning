//
// Created by 郑楚彬 on 2020/3/12.
//
#include <inttypes.h>
/**
    dest in %rdi(第1个参数)、x in %rsi、y in %rdx

	movq	%rsi, %rax          // copy to multiplicand
	mulq	%rdx                // multiply by y
	movq	%rax, (%rdi)        // store lower 8 bytes at dest
	movq	%rdx, 8(%rdi)       // store upper 8 bytes at dest+8
	ret
 */
typedef unsigned __int128 uint128_t;

void store_uprod(uint128_t *dest, uint_fast64_t x, uint_fast64_t y){
    *dest = x*(uint128_t) y;
}
