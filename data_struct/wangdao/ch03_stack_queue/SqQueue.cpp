//
// Created by 郑楚彬 on 2020/8/27.
//
#include "SqQueue.hpp"

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;               // 初始化队首、队尾指针
}

bool QueueEmpty(SqQueue Q) {
    return Q.front==Q.rear;             // 队空条件
}

bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1)%MaxSize==Q.front)     // 队满则报销
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1) % MaxSize;      // 队尾指针加 1 取模
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x){
    if(Q.front==Q.rear)                 // 队空则报销
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;    // 队头指针加 1 取模
    return true;
}

bool GetHead(SqQueue Q, ElemType &x){
    if(Q.front==Q.rear)                 // 队空则报销
        return false;
    x = Q.data[Q.front];
    return true;
}

int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+MaxSize)%MaxSize;
}
