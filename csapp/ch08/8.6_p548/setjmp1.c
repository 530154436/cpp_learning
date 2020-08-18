//
// Created by 郑楚彬 on 2020/8/13.
//
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>

jmp_buf buf;
int error1 = 0;
int error2 = 1;

void foo(void), bar(void);

int main()
{
    int flag = setjmp(buf);
    printf("%d\n", flag);

    switch(flag) {
        case 0:
            foo();
            break;
        case 1:
            printf("Detected an error1 condition in foo\n");
            break;
        case 2:
            printf("Detected an error2 condition in foo\n");
            break;
        default:
            printf("Unknown error condition in foo\n");
    }
    exit(0);
}

/* Deeply nested function foo */
void foo(void)
{
    if (error1)
        longjmp(buf, 1);
    bar();
}

void bar(void)
{
    if (error2)
        longjmp(buf, 2);
}