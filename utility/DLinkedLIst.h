//
// Created by 郑楚彬 on 2018/3/28.
//
#include <iostream>
using namespace std;

/**
 * 双链表结构
 */
typedef struct DLNode{
    int data;
    struct DLNode *next;
    struct DLNode *prior;
} DLNode;

/**
 * 采用尾插法建立双链表
 * @param L 链表
 * @param a 数组
 * @param n 长度
 */
void createDListR(DLNode *&L, int a[], int n){
    DLNode *s, *r;
    int i;

    // 头结点
    L = (DLNode *)malloc(sizeof(DLNode *));
    L->next = NULL;
    r = L;

    for(i=0; i<n; i++){
        s = (DLNode *)malloc(sizeof(DLNode *));
        s->data = a[i];
        // printf("%d\n", a[i]);

        // 将 s 插入在 L 的尾部并且 r 指向 s，
        r->next = s;
        s->prior = r;
        // printf(" %d ",s->data);

        r = s;
    }
    r->next = NULL;
}

/**
 * 查找结点
 *
 * 从第一个结点开始，边扫描边比较，若找到这样的结点，则返回结点指针，否则返回 NULL。
 *
 * @param L 链表
 * @param x 待查节点的值
 * @return
 */
DLNode* findNode(DLNode *L, int x){
    if(L==NULL){
        return NULL;
    }
    DLNode *tmp = L->next;
    while(tmp!=NULL){
        if(tmp->data == x){
            break;
        }
        tmp = tmp->next;
    }
    return tmp;  // 如果找到则 p 中内容是结点地址(循环因 break 结束)，
                 // 没找到 p 中内容是 NULL(循环因 p 等于 NULL 而结束)
}

/**
 * 插入节点
 *
 * 在双链表中 p 所指的结点之后插入一个结点 s
 *
 * @param C 被插入节点
 * @param s 待插入节点
 */
bool insertAfterNode(DLNode *&p, DLNode *&s){
    if(p==NULL || s==NULL){
        return false;
    }
    // 先将要插入的结点两边链接好，这样有什么好处?对了， 就是可以保证不会发生链断之后找不到结点的情况。
    s->next = p->next;
    s->prior = p;
    p->next = s;

    // p 不为最后一个元素
    if(s->next != NULL)
        s->next->prior = s;  // s 不是 p

    return true;
}

/**
 * 在 p 所指的节点之后删除节点 *q
 *
 * @param p
 * @param q
 * @return
 */
bool delAfterNode(DLNode *&p, DLNode *&q){
    if(p==NULL || q==NULL){
        return false;
    }
    p->next = q->next;
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

/**
 * 打印双链表(含头结点)
 *
 * @param a 链表指针
 */
void printDLinkedListH(DLNode *a){
    if(a==NULL){
        printf("双链表为空!!\n");
        return;
    }
    DLNode *tmp = a->next;
    printf("双链表: [");
    while(tmp!=NULL){
        printf(" %d ",tmp->data);
        tmp = tmp->next;
    }
    printf("]\n");
}