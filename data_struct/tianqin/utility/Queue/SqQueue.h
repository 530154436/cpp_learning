//
// Created by Edward on 2018/4/4.
//
#define MAX 100

/**
 * 顺序队列的定义 (改进 --> 循环队列)
 */
typedef struct SqQueue{
    int data[MAX];
    int front;  // 队首指针
    int rear;   // 队尾指针
}SqQueue;

/**
 * 初始化队列
 *
 * @param qu
 */
void initQueue(SqQueue &qu){
    //队首队尾指针重合，且指向0
    qu.front = qu.rear = 0;
}

/**
 * 判断队空
 *
 * @param qu
 * @return
 */
int isSqQueueEmpty(SqQueue &qu){
    // 只要两者重合，即为队空
    if(qu.front==qu.rear){
        return 1;
    } else{
        return 0;
    }
}

/**
 * 判断队满
 *
 * @param qu
 * @return
 */
int isSqQueueFull(SqQueue &qu){
    if(qu.front == (qu.rear+1)%MAX){
        return 1;
    }else{
        return 0;
    }
}

/**
 * 元素进队
 *
 * @param qu
 * @param x
 * @return
 */
int enSqQueue(SqQueue &qu, int x){
    // 队满，入队失败
    if((qu.rear+1)%MAX == qu.front){
        return 0;
    }
    qu.rear = (qu.rear + 1)%MAX;    // 先移动指针
    qu.data[qu.rear] = x;           // 再取出元素
    return 1;
}

/**
 * 元素出队
 *
 * @param qu
 * @param x
 * @return
 */
int deSqQueue(SqQueue &qu, int &x){
    // 队空，出队失败
    if(qu.front == qu.rear){
        return 0;
    }
    qu.front = (qu.front+1)%MAX;    // 先移动指针
    x = qu.data[qu.front];          // 再取出元素
    return 1;
}