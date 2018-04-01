//
// Created by 郑楚彬 on 2018/3/27.
//
#include <iostream>
using namespace std;

/**
 * 单链表结构
 */
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode;

/**
 * 初始化
 * @param L
 * @return
 */
int init(LNode *&L){
    L = (LNode *) malloc(sizeof(LNode *));
    L -> next = NULL;
}

/**
 * 2. 初始化(头插法)
 *
 * @param C 链表指针
 * @param a 数组
 * @param n 长度
 */
void crateListF(LNode *&C, int a[], int n){
    LNode *s;

    C = (LNode *)malloc(sizeof(LNode *));
    C-> next = NULL;

    for(int i=0; i<n; i++){
        s = (LNode *) malloc(sizeof(LNode *));
        s->data = a[i];

        //s 所指新结点的指针域 next 指向 C 中的开始结点。
        s->next = C->next;

        //头结点的指针域 next 指向 s 结点，使得 s 成为了新的开始结点。
        C->next = s;
    }
}

/**
 * 1. 初始化(尾插法)
 *    假设有 n 个元素已经存储在数组 a 中，用尾插法建立链表 C。
 *
 * @param C 链表指针
 * @param a 数组
 * @param n 长度
 */
void createListR(LNode *&C, int a[], int n){
    //s用来指向新申请的结点，r始终指向C的终端结点。s
    LNode *s,*r;

    //申请 C 的头结点空间。
    C = (LNode *) malloc(sizeof(LNode *));
    C->next = NULL;
    r = C;

    for(int i=0; i<n; i++){
        // 指向新申请的结点
        s = (LNode *)malloc(sizeof(LNode *));
        s->data = a[i];
        // 不赋初值的话会出现 Segmentation fault
        s->next = NULL;

        //用 r 来接纳新结点。
        r->next = s;

        //r 指向终端结，点以便于接纳下一个到来的结点。
        r = r->next;
    }
    r->next = NULL;
}

/**
 * 获取链表长度
 * @param L
 * @return
 */
int getLength(LNode *&L){
    int length=0;
    // 指向第一个节点
    LNode *p = L->next;
    while(p!=NULL){
        length++;
        p = p->next;
    }
    return length;
}

/**
 * ﻿指定位置插入节点元素
 *
 * @param L
 * @param p
 * @param data
 * @return
 */
int insertLinkedList(LNode *&L, int p, int data){
    LNode *q = L, *s;
    // 当前遍历到第 i 个节点
    int i = 0;
    // 找到第 p-1 个节点
    while(q->next!=NULL && i<p-1){
        q = q->next;
        i++;
    }
    // 第 p-1 个节点为空，返回错误
    if(q == NULL){
        return 0;
    }
    // 在第 p 个节点出插入节点
    s = (LNode *) malloc(sizeof(LNode *));
    s->data = data;
    s->next = q->next;
    q->next = s;
    return 1;
}

/**
 * ﻿删除指定位置的节点
 *
 * @param L
 * @param p
 * @return
 */
int delElem(LNode *&L, int p, int &data){
    if(L->next==NULL){
        return 0;
    }
    int i=0;
    LNode *q = L, *s;

    // 找到第 p-1 个节点
    while(q->next!=NULL && i<p-1){
        q = q->next;
        i++;
    }

    // 第 p 个节点为空，返回错误
    if(q->next == NULL){
        return 0;
    }

    // 删除第 p 个节点
    s = q->next;
    q->next = s->next;
    data = s->data;
    free(s);
    return 1;
}

/**
 * ﻿获取指定位置处的节点元素
 *
 * @param L
 * @param p
 * @param data
 * @return
 */
int findElem(LNode *&L, int p, int &data) {
    // 链表为空
    if (L->next==NULL || p<1) {
        return 0;
    }
    int i = 0;
    LNode *q = L, *s;

    // 找到第 p 个节点
    while (q->next!=NULL && i<p) {
        q = q->next;
        i++;
    }
    if(q!=NULL){
        data = q->data;
        return 1;
    }else{
        return 0;
    }
}

/**
 * 打印单链表(含头结点)
 * @param tmp
 * @param len
 */
void printLinkedListH(char* name, LNode *a){
    if(a==NULL){
        printf("单链表为空!!\n");
        return;
    }
    LNode *tmp;
    tmp = a->next;
    printf("单链表 %s : [", name);
    while(tmp){
        printf(" %d ",tmp->data);
        tmp = tmp->next;
    }
    printf("]\n");
}