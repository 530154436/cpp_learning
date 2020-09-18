//
// Created by Edward on 2018/4/4.
//
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

/**
 * 队结点类型定义
 */
typedef struct QNode{
    int data;           // 数据域
    struct QNode *next; // 指针域
}QNode;

/**
 * 链队类型定义
 */
typedef struct LiQueue{
    QNode *front;       // 队头指针
    QNode *rear;        // 队尾指针
}LiQueue;

/**
 * 初始化链队
 *
 * @param lqu
 */
void initLiQueue(LiQueue *&lqu){
    lqu = (LiQueue *) malloc(sizeof(LiQueue *));
    lqu->front = lqu->rear = NULL;
}

/**
 * 判断队空
 *
 * @param lqu
 * @return
 */
int isLiQueueEmpty(LiQueue *lqu){
    if(lqu->front==NULL || lqu->rear==NULL){
        return 1;
    }else{
        return 0;
    }
}

/**
 * 入队
 *
 * @param lqu
 * @param x
 */
void enLiQueue(LiQueue *&lqu, int x){
    QNode *p = (QNode *)malloc(sizeof(QNode *));
    p->data = x;
    p->next = NULL;

    //若队列为空，则新结点是队首结点，也是队尾结点
    if(lqu->rear == NULL){
        lqu->front = lqu->rear = p;
    }else{
        // 将新结点链接到队尾，rear指向它
        lqu->rear->next = p;
        lqu->rear = p;
    }
}

/**
 * 出队
 *
 * @param lqu
 * @param x
 * @return
 */
int deLiQueue(LiQueue *&lqu, int &x){
    // 队空不能出队
    if(lqu->front==NULL || lqu->rear==NULL){
        return 0;
    }

    QNode *p = lqu->front;
    x = p->data;

    // 队列中只有一个结点时的出队操作需特殊处理
    if(lqu->front == lqu->rear){
        lqu->front = lqu->rear = NULL;
    }else{
        lqu->front = lqu->front->next;
    }
    free(p);
    return 1;
}