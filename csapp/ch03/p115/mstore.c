//
// Created by Edward on 2020/3/15.
//

/**
    x in %rdi、y in %rsi、dest in %rdx

    mstore.o:	file format Mach-O 64-bit x86-64
    Disassembly of section __TEXT,__text:
    _multstore:
    0:	53 	            pushq	%rbx                    # save %rbx
    1:	48 89 d3 	    movq	%rdx, %rbx              # copy dest to %rbx
    4:	e8 00 00 00 00 	callq	0 <_multstore+0x9>      # call mult2(x,y)
    9:	48 89 03 	    movq	%rax, (%rbx)            # store result at *dest
    c:	5b 	            popq	%rbx                    # restore %rbx
    d:	c3 	            retq                            # return
 */
long mult2(long, long);

void multstore(long x, long y, long *dest){
    long t = mult2(x, y);
    *dest = t;
}
