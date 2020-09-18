//
// Created by Edward on 2020/3/15.
//
#include <stdio.h>
/**
 p114- p116

 + "-S (source)"选项: GCC 运行编译器，产生一个汇编文件
 gcc-8 -Og -S mstore.c  => mstore.s (汇编代码文件)

 + "-c (Compiling)"选项: GCC 会编译并汇编该代码，产生一个目标代码文件。
 gcc-8 -Og -c mstore.c  => mstore.o (目标代码文件)

 + "-o (object)"选项: GCC 会编译、汇编，并对目标代码文件运行链接器，生成一个可执行文件。
 gcc-8 -Og -o main main.c mstore.c  =>  生成可执行文件 prog + 反汇编器

 + 反汇编器

  objdump -d mstore.o

    mstore.o:	file format Mach-O 64-bit x86-64
    Disassembly of section __TEXT,__text:
    _multstore:
           0:	53 	            pushq	%rbx
           1:	48 89 d3 	    movq	%rdx, %rbx
           4:	e8 00 00 00 00 	callq	0 <_multstore+0x9>
           9:	48 89 03 	    movq	%rax, (%rbx)
           c:	5b 	            popq	%rbx
           d:	c3 	            retq

 objdump -d main
    _multstore:
        100000ee4:	53 	            pushq	%rbx
        100000ee5:	48 89 d3 	    movq	%rdx, %rbx
        100000ee8:	e8 ef ff ff ff 	callq	-17 <_mult2>
        100000eed:	48 89 03 	    movq	%rax, (%rbx)
        100000ef0:	5b 	            popq	%rbx
        100000ef1:	c3 	            retq
 */

void multstore(long, long, long *);

int main(){
    long d;
    multstore(2, 3, &d);
    printf("2*3 --> %ld\n", d);
    return 0;
}

long mult2(long a, long b){
    long s = a*b;
    return s;
}