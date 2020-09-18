//
// Created by Edward on 2020/3/12.
//
/**
    x in %rdi(第1个参数)、y in %rsi、z in %rdx

    xorq	%rsi, %rdi              x ^ y
	leaq	(%rdx,%rdx,2), %rdx     3z
	movq	%rdx, %rax
	salq	$4, %rax                4 << 3z = z*48
	andl	$252645135, %edi        t1 & 0x0F0F0F0F (long 为4个字节 => edi)
	subq	%rdi, %rax
	ret
 */
long arith(long x, long y, long z){
    long t1 = x ^ y;
    long t2 = z * 48;
    long t3 = t1 & 0x0F0F0F0F;
    long t4 = t2 - t3;
    return t4;
}