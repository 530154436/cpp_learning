//
// Created by 郑楚彬 on 2020/8/30.
//
#ifndef TIANQINDATASTRUCT_UTIL_HPP
#define TIANQINDATASTRUCT_UTIL_HPP

#include "SqQueueTemplate.hpp"
#include <iostream>
using namespace std;

/**
 * 打印数组
 * @tparam ElemType
 * @param a
 * @param n
 */
template <typename ElemType >
void display(ElemType a[], int n){
    for(int i=0; i<n; i++)
        std::cout<<a[i]<<' ';
    std::cout<<std::endl;
}

/**
 * 打印二叉树、二叉排序树 (层次遍历)
 * @param T
 */
template <typename Tree>
void display(Tree T){
    SqQueue<Tree> Q;
    InitQueue(Q);
    Tree p;
    EnQueue(Q, T);
    while(!QueueEmpty(Q)){          // 队列不为空则循环
        DeQueue(Q, p);
        std::cout << p->data << ' ';
        if(p->lchild)
            EnQueue(Q, p->lchild);  // 左子树不空，则左子树根结点入队
        if(p->rchild)
            EnQueue(Q, p->rchild);  // 右子树不空，则右子树根结点入队
    }
    std::cout<<std::endl;
}

#endif //TIANQINDATASTRUCT_UTIL_HPP
