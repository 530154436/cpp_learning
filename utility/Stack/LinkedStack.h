//
// Created by 郑楚彬 on 2018/4/2.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/**
 * 链栈结点定义
 */
typedef struct LStackNode{
    int data;                   //数据项
    struct LStackNode *next;    //指针域
}LStackNode;

/**
 * 链栈的初始化算法
 *
 * @param lst
 */
void initLStackNode(LStackNode *&lst){
    lst = (LStackNode *)malloc(sizeof(LStackNode *));
    lst->next = NULL;
}

/**
 * 判断栈空算法
 *
 * @param lst
 * @return
 */
int isLStackEmpty(LStackNode *&lst){
    if(lst->next == NULL){
        return 0;
    }else{
        return 1;
    }
}

/**
 * 进栈算法
 *
 * @param lst
 * @param x
 * @return
 */
int pushLStack(LStackNode *&lst, int x){
    // 为进栈元素申请结点空间
    LStackNode *p;
    p = (LStackNode *) malloc(sizeof(LStackNode *));
    p->next = NULL;
    p->data = x;

    // 链表的头插法
    p->next = lst->next;
    lst->next = p;
}

/**
 * 出栈算法
 *
 * @param lst
 * @param x
 * @return
 */
int popLStack(LStackNode *&lst, int &x){
    //栈空则不能出栈返回 0
    if(lst->next == NULL){
        return 0;
    }

    // 单链表的删除操作
    LStackNode *p = lst->next;
    x = p->data;
    lst->next = p->next;
    free(p);
    return 1;
}


