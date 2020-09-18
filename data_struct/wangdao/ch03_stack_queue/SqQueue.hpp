//
// Created by Edward on 2020/8/27.
//
#ifndef TIANQINDATASTRUCT_SQQUEUE_HPP
#define TIANQINDATASTRUCT_SQQUEUE_HPP

#define MaxSize 100                 // 定义队列中元素的最大个数

/**
 * 队列的顺序存储 (循环队列)
 */
typedef int ElemType;               // 元素数据类型
typedef struct SqQueue{
    ElemType data[MaxSize];         // 存放队列元素
    int front,rear;                 // 队头指针和队尾指针
} SqQueue;

/**
 * 队列的基本操作
 */
void InitQueue(SqQueue &Q);             // 初始化队列，构造一个空队列 Q
bool QueueEmpty(SqQueue Q);             // 判断队列空，若队列 Q 为空返回 true，否则返回 false。
bool EnQueue(SqQueue &Q, ElemType x);   // 入队，若队列 Q 未满，将 x 加入，使之成为新的队尾。
bool DeQueue(SqQueue &Q, ElemType &x);  // 出队，若队列 Q 非空，删除队头元素，并用 x 返回 。
bool GetHead(SqQueue Q, ElemType &x);   // 读队头元素，若队列 Q 非空，则将队头元素赋值给 X
int QueueLength(SqQueue Q);             // 队列长度

#endif //TIANQINDATASTRUCT_SQQUEUE_HPP
