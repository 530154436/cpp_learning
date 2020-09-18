//
// Created by Edward on 2020/8/27.
//
#ifndef TIANQINDATASTRUCT_SQSTACK_TEMPLATE_HPP
#define TIANQINDATASTRUCT_SQSTACK_TEMPLATE_HPP

#include <cstdlib>

#define MaxStackSize 100                 // 定义栈中元素的最大个数

/**
 * 栈的顺序存储
 */
template<typename ElemType>
struct SqStack {
    ElemType data[MaxStackSize];    // 存放栈中元素
    int top;                        // 栈顶指针
};

/**
 * 初始化一个空栈
 */
template<typename ElemType>
void InitStack(SqStack<ElemType> &S){
    S.top = -1;
}

/**
 * 判断一个栈是否为空， 若找 s 为空则返回 true，否则返回 false。
 */
template<typename ElemType>
bool StackEmpty(SqStack<ElemType> S){
    return S.top == -1;             // 栈空与否
}

/**
 * 进栈，若栈 s 未满，则将 x 压入栈
 */
template<typename ElemType>
bool Push(SqStack<ElemType> &S, ElemType x){
    if(S.top>=MaxStackSize-1)            // 栈满
        return false;
    S.data[++S.top] = x;            // 指针先加 1，再入栈
    return true;
}

/**
 * 出栈，若栈 S 非空，则弹出栈顶元素， 并用 x 返回。
 */
template<typename ElemType>
bool Pop(SqStack<ElemType> &S, ElemType &x){
    if(S.top==-1)                   // 栈空，报错
        return false;
    x = S.data[S.top--];            // 先出栈，指针再减 l
    return true;
}

/**
 * 读栈顶元素，若栈 s 非空，则用 x 返回栈顶元素。
 */
template<typename ElemType>
bool GetTop(SqStack<ElemType> S, ElemType &x){
    if(S.top==-1)                   // 栈空，报错
        return false;
    x = S.data[S.top];
    return true;
}

/**
 * 销毁栈，并释放栈 s 占用的存储空间(“&” 表示引用调用)。
 */
template<typename ElemType>
void DestroyStack(SqStack<ElemType> &S){
    free(S.data);
    S.top = -1;
}

template<typename ElemType>
int StackLength(SqStack<ElemType> S){
    return S.top+1;
}

/**
 * 判断栈是否满
 * @param S
 * @return
 */
template<typename ElemType>
bool StackOverflow(SqStack<ElemType> S){
    return S.top+1>=MaxStackSize-1;
}

#endif //TIANQINDATASTRUCT_SQSTACK_TEMPLATE_HPP