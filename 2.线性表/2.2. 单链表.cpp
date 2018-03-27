//
// Created by 郑楚彬 on 2018/3/26.
//
#include <stdio.h>
#include <iostream>
#include "../utility/LinkedList.h"
using namespace std;

/**
 * 1. 初始化(尾插法)
 * 假设有 n 个元素已经存储在数组 a 中，用尾插法建立链表 C。
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
 * 2. 初始化(头插法)
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
 * (尾插法)
 * 例题 1  A和B是两个单链表(带表头结点)，其中元素递增有序。设计一个算法将A 和 B 归并成
 *        一个按元素递增有序的链表 C，C 由 A 和 B 中的结点组成。
 */
void merge(LNode *&A, LNode *&B, LNode *&C){
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r;
    C = A;
    C->next = NULL;
    free(B);
    r = C;

    // A、B 同时不为空时，比较数据域大小
    while(p!=NULL & q!=NULL){
        if(p->data > q->data){
            r->next = q;
            q = q->next;
        }else{
            r->next = p;
            p = p->next;
        }
        r = r->next;
    }
    r->next=NULL;

    // A不为空则将A剩余的节点拼接到C，反之亦然
    if(p != NULL)
        r->next = p;
    if(q != NULL)
        r->next = q;
}

void test01(){
    LNode *A, *B, *C;
    int a[10] = {1,3,5,7,9};
    int b[10] = {2,4,6,8,10};

    createListR(A, a, 5);
    createListR(B, b, 5);

    printLinkedListH(A);
    printLinkedListH(B);
    merge(A, B, C);
    printLinkedListH(C);
}

int main(){
    test01();
}

