//
// Created by Edward on 2020/8/27.
//
#ifndef TIANQINDATASTRUCT_SQQUEUE_TEMPLATE_HPP
#define TIANQINDATASTRUCT_SQQUEUE_TEMPLATE_HPP

#define MaxSize 100                 // 定义队列中元素的最大个数

/**
 * 队列的顺序存储 (循环队列)
 */
template<typename ElemType>
struct SqQueue{                     // 队列 => 必须先 InitQueue(q); 否则报 Segmentation fault (core dumped)
    ElemType data[MaxSize];         // 存放队列元素
    int front,rear;                 // 队头指针和队尾指针
};

/**
 * 初始化队列，构造一个空队列 Q
 */
template<typename ElemType>
void InitQueue(SqQueue<ElemType> &Q){
    Q.front = Q.rear = 0;               // 初始化队首、队尾指针
}

/**
 * 判断队列是否为空，若队列 Q 为空返回 true，否则返回 false。
 */
template<typename ElemType>
bool QueueEmpty(SqQueue<ElemType> Q){
    return Q.front==Q.rear;             // 队空条件
}

/**
 * 入队，若队列 Q 未满，将 x 加入，使之成为新的队尾。
 */
template<typename ElemType>
bool EnQueue(SqQueue<ElemType> &Q, ElemType x){
    if((Q.rear+1)%MaxSize==Q.front)     // 队满则报销
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1) % MaxSize;      // 队尾指针加 1 取模
    return true;
}

/**
 * 出队，若队列 Q 非空，删除队头元素，并用 x 返回 。
 */
template<typename ElemType>
bool DeQueue(SqQueue<ElemType> &Q, ElemType &x){
    if(Q.front==Q.rear)                 // 队空则报销
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;    // 队头指针加 1 取模
    return true;
}

/**
 * 读队头元素，若队列 Q 非空，则将队头元素赋值给 X
 */
template<typename ElemType>
bool GetHead(SqQueue<ElemType> Q, ElemType &x){
    if(Q.front==Q.rear)                 // 队空则报销
        return false;
    x = Q.data[Q.front];
    return true;
}

/**
 * 返回 Q 的元素个数，即队列长度
 * @tparam ElemType
 * @param Q
 * @return
 */
template<typename ElemType>
int QueueLength(SqQueue<ElemType> Q){
    return (Q.rear-Q.front+MaxSize)%MaxSize;
}

#endif //TIANQINDATASTRUCT_SQQUEUE_TEMPLATE_HPP
