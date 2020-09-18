//
// Created by Edward on 2020/3/12.
//
/**
    x in %rdi(第1个参数)、y in %rsi、z in %rdx

    leaq	(%rdi,%rsi,4), %rax     x+4*y
    leaq	(%rdx,%rdx,2), %rcx     z+2*z
    leaq	0(,%rcx,4), %rdx        4*(z+2*z) = 12z
    addq	%rdx, %rax              x+4*y+12z
    ret
 */
long scale(long x, long y, long z){
    long t = x + 4*y + 12*z;
    return t;
}