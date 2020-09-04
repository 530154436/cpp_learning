//
// Created by 郑楚彬 on 2020/8/27.
//
#include <cstdlib>
#include "SqStack.hpp"

void InitStack(SqStack &S){
    S.top = -1;
}

bool StackEmpty(SqStack S){
    return S.top == -1;             // 栈空与否
}

bool Push(SqStack &S, ElemType x){
    if(S.top>=MaxSize-1)            // 栈满
        return false;
    S.data[++S.top] = x;            // 指针先加 1，再入栈
    return true;
}

bool Pop(SqStack &S, ElemType &x){
    if(S.top==-1)                   // 栈空，报错
        return false;
    x = S.data[S.top--];            // 先出栈，指针再减 l
    return true;
}

bool GetTop(SqStack S, ElemType &x){
    if(S.top==-1)                   // 栈空，报错
        return false;
    x = S.data[S.top];
    return true;
}

void DestroyStack(SqStack &S){
    free(S.data);
    S.top = -1;
}

int StackLength(SqStack S){
    return S.top+1;
}