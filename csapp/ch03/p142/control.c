//
// Created by 郑楚彬 on 2020/3/12.
//
/***
 gcc-8 -Og -S control.c

 寄存器  用途
  %rdi  参数y
  %rsi  参数x
  %rax  返回值

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


    _cmovdiff:
    LFB2:
        movq	%rsi, %rdx
        subq	%rdi, %rdx  # y-x
        movq	%rdi, %rax
        subq	%rsi, %rax  # x-y
        cmpq	%rdi, %rsi
        jle	L7
        movq	%rdx, %rax
    L7:
        ret
 */

#include <inttypes.h>

long absdiff(long x, long y){
    // 条件控制
    long result;
    if(x<y){
        result = y-x;
    }else{
        result = x-y;
    }
    return result;
}

long goto_absdiff(long x, long y){
    long result;
    if(x>=y)
        goto Else; // absdiff中的else
    result = y-x;
    goto Done;

    Else:
        result = x-y;
    Done:
        return result;
}

long cmovdiff(long x, long y){
    // 条件传送
    long rval = y-x;
    long eval = x-y;
    long ntest = x>=y;
    if(ntest) rval = eval;
    return rval;
}