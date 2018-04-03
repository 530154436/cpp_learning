//
// Created by 郑楚彬 on 2018/4/2.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define Max 100

/**
 * 顺序栈定义
 */
typedef struct SqStack{
    int data[Max];  // 存放栈中元素
    int top;        // 栈顶指针
};

/**
 * 初始化栈
 *
 * @param st
 */
void initStack(SqStack &st){
    // 栈空状态
    st.top = -1;
}

/**
 * 判断栈空
 * @param st
 * @return
 */
int isStackEmpty(SqStack &st){
    if(st.top == -1){
        return 1;
    }else{
        return 0;
    }
}

/**
 * 进栈算法
 *
 * @param st
 * @param x
 * @return
 */
int pushStack(SqStack &st, int x){
    //这里要注意，栈满不能进栈。
    if(st.top == Max-1){
        return 0;
    }
    //先移动指针，再进栈
    st.top ++;
    st.data[st.top] = x;
    return 1;
}

/**
 * 出栈算法
 *
 * @param st
 * @param x
 * @return
 */
int popStack(SqStack &st, int &x){
    //注意，如果栈空则不能出栈
    if(st.top == -1){
        return 0;
    }
    //先取出元素，再移动指针
    x = st.data[st.top];
    st.top--;
    return 1;
}
