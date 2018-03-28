//
// Created by 郑楚彬 on 2018/3/26.
//
#include "../utility/LinkedList.h"

/**
 * (尾插法)
 * 例题 1  A和B是两个单链表(带表头结点)，其中元素递增有序。设计一个算法将A 和 B 归并成
 *        一个按元素递增有序的链表 C，C 由 A 和 B 中的结点组成。
 */
void mergeR(LNode *A, LNode *B, LNode *&C){
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r;

    C = (LNode*) malloc(sizeof(LNode *));
    C->next = NULL;
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

/**
 * (头插法)
 * 例题 1  A和B是两个单链表(带表头结点)，其中元素递增有序。设计一个算法将A 和 B 归并成
 *        一个按元素递减有序的链表 C，C 由 A 和 B 中的结点组成。
 */
void mergeF(LNode *A, LNode*B, LNode *&C){
    LNode *p, *q;
    p = A->next;
    q = B->next;
    LNode *tmp;
    C = A;
    C->next = NULL;
    while(p!=NULL & q!=NULL){
        if(q->data > p->data){
            // printf("%d\n", p->data);
            // 头插法
            tmp = p;
            p = p->next;
            tmp->next = C->next;
            C->next = tmp;
        }else{
            // printf("%d\n", q->data);
            tmp = q;
            q = q->next;
            tmp->next = C->next;
            C->next = tmp;
        }
    }

    // 将剩余元素逐个插入 C 的头部
    while(p!=NULL){
        tmp = p;
        p = p->next;
        tmp->next = C->next;
        C->next = tmp;
    }

    while(q!=NULL){
        tmp = q;
        q = q->next;
        tmp->next = C->next;
        C->next = tmp;
    }
}

// =========== 测试 =========== //
void test01(){
    LNode *A, *B, *C, *D;
    int a[10] = {1,3,5,7};
    int b[10] = {2,4,6,8,10};

    createListR(A, a, 4);
    createListR(B, b, 5);

    printLinkedListH(A);
    printLinkedListH(B);

    mergeR(A, B, C);
    printLinkedListH(C);
}

void test02(){
    LNode *A, *B, *C, *D;
    int a[10] = {1,3,5,7};
    int b[10] = {2,4,6,8,10};

    createListR(A, a, 4);
    createListR(B, b, 5);

    printLinkedListH(A);
    printLinkedListH(B);

    mergeF(A, B, D);
    printLinkedListH(D);

}

void test03(){
    LNode *A, *B, *C, *D;
    int a[10] = {1,3,5,7};
    createListR(A, a, 4);
    printLinkedListH(A);
    SearchAndDelete(A, 5);
    printLinkedListH(A);

}
// =========== 测试 =========== //

int main(){
    // test01();
    // test02();
    test03();
}

