//
// Created by Edward on 2018/4/4.
//
#include "../Printer.h"

/**
  1.为了充分利用空间，顺序栈 S0,S1 共享一个存储区 elem[0....MAX-1]。试设计
     共享栈 S0,S1 以及有关入栈和出栈操作的算法，假设栈中元素为 int 型。要求:
   (1)给出基 设计思想。
   (2)根据设计思想，采用C或C++语言描述算法(对于共享栈要写出其结构定义)，关 键之处给出注释。

  设计思想:
  1) 顺序栈栈底固定不变，因此将栈底设在存储区的两端，即 S0 栈底设在 0 处，s1 栈
     底设在 MAX-1 处，栈顶在 0~MAX-1 之间变动。当两栈栈顶相遇时为栈满，这样可以尽可 能的利用空间。
  2) s0 的栈顶为 top0。s0 入栈操作为:top0 先自增 1，然后存入元素;出栈操作为: 先取出栈顶元素，top0 再自减 1。
     s1 的栈顶为 top1，s2 入栈操作为:top1 先自减 1， 然后存入元素;出栈操作为:先取出栈顶元素，top1 再自增 1。
 */
#define MAX 10

/**
 * 共享栈定义
 */
typedef struct shareStack{
    int data[MAX];
    int top0;
    int top1;
} ShareStack;

/**
 * 初始化
 * @param ss
 */
void initShareStack(ShareStack &ss){
    ss.top0 = -1;
    ss.top1 = MAX;
    for(int i=0; i<MAX; i++){
        ss.data[i] = 0;
    }
}

/**
 * 判断栈空
 *
 * @param ss
 * @param flag
 * @return
 */
int isSStackEmpty(shareStack &ss, int flag){
    // S0 为空
    if(flag == 0){
        if(ss.top0 == -1){
            return 1;
        }else{
            return 0;
        }
    }else if(flag == 1){
        // S1 为空
        if(ss.top1 == MAX){
            return 1;
        }else{
            return 0;
        }
    }else{
        // 栈编号输入有误返回-1。
        return -1;
    }
}

/**
 * 判断栈满
 *
 * @param ss
 * @return
 */
int isSStackFull(shareStack &ss){
    // 栈满
    if(ss.top0+1 >= ss.top1){
        return 1;
    }else{
        return 0;
    }
}

/**
 * 入栈操作
 *
 * @param ss
 * @param flag  栈标记，0->S0, 1->S1
 * @param x
 * @return
 */
int pushShareStack(ShareStack &ss, int flag, int x){
    // 栈满
    if(ss.top0+1 >= ss.top1){
        return 0;
    }
    if(flag==0){
        ss.data[++ss.top0] = x; // 入栈 S0
        return 1;
    }else if(flag==1){
        ss.data[--ss.top1] = x; // 入栈 S0
    }else{
        return -1;
    }
}

/**
 * 出栈操作
 *
 * @param ss
 * @param flag  栈标记，0->S0, 1->S1
 * @param x
 * @return
 */
int popShareStack(ShareStack &ss, int flag, int &x){
    if(flag == 0){
        // S0 为空
        if(ss.top0 == -1){
            return 0;
        }
        x = ss.data[ss.top0--];
        return 1;
    }else if(flag == 1){
        // S1 为空
        if(ss.top1 == MAX){
            return 0;
        }
        x = ss.data[ss.top1++];
        return 1;
    }else{
        // 栈编号输入有误返回-1。
        return -1;
    }
}

/**
 * 打印共享栈
 *
 * @param ss
 */
void printSharedStack(ShareStack ss){
    printf("共享栈 [");
    for(int i=0; i<=ss.top0; i++){
        printf(" %d ", ss.data[i]);
    }
    for(int i=ss.top0+1; i<ss.top1; i++){
        printf(" %s ", "NULL");
    }
    for(int i=ss.top1; i<MAX; i++){
        printf(" %d ", ss.data[i]);
    }
    printf("]\n");
}

void test04(){
    ShareStack ss;
    int x;
    initShareStack(ss);
    printSharedStack(ss);

    pushShareStack(ss, 0, 1);
    pushShareStack(ss, 0, 2);
    pushShareStack(ss, 0, 3);
    pushShareStack(ss, 0, 4);
    printSharedStack(ss);

    pushShareStack(ss, 0, 1);
    printSharedStack(ss);

    popShareStack(ss, 0, x);
    printSharedStack(ss);

    pushShareStack(ss, 1, 2);
    printSharedStack(ss);
}