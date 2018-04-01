//
// Created by 郑楚彬 on 2018/3/26.
//
#include "../utility/LinearTable/LinkedList.h"

/**
 * (尾插法)
 * 例题 1.1  A和B是两个单链表(带表头结点)，其中元素递增有序。设计一个算法将A 和 B 归并成
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
 * 例题 1.2  A和B是两个单链表(带表头结点)，其中元素递增有序。设计一个算法将A 和 B 归并成
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

/**
 * 查找链表 C(带头结点)中是否存在一个值为 x 的结点，存在就删除之并返回 1，否则返回 0。
 *
 * ps. 程序中之所以要使 p 指向所要删除结点的前驱结点而不是直接指向所
 *     要删除结点本身，是因为要删除一个结点必须知道其前驱结点的位置
 *
 * @param C 链表指针
 * @param x 值
 * @return
 */
int SearchAndDelete(LNode *&C,int x){
    if(C==NULL){
        return 0;
    }

    // 查找部分
    LNode *p, *q;
    p = C;
    while(p->next != NULL){
        if(p->next->data == x){
            break;
        }
        p = p->next;
    }

    // 删除部分
    if(p->next == NULL){
        return 0;
    }else{
        q = p->next;
        p->next = p->next->next;
        free(q);
        return 1;
    }
}

// =========== 测试 =========== //
void test01(){
    LNode *A, *B, *C;
    int a[10] = {1,3,5,7};
    int b[10] = {2,4,6,8,10};

    createListR(A, a, 4);
    createListR(B, b, 5);

    printLinkedListH("归并前-A", A);
    printLinkedListH("归并前-B", B);

    mergeR(A, B, C);
    printLinkedListH("归并后-C", C);
}

void test02(){
    LNode *A, *B, *C, *D;
    int a[10] = {1,3,5,7};
    int b[10] = {2,4,6,8,10};

    createListR(A, a, 4);
    createListR(B, b, 5);

    printLinkedListH("归并前-A", A);
    printLinkedListH("归并前-C", B);

    mergeF(A, B, D);
    printLinkedListH("归并后-D", D);

}

void test03(){
    // 查找链表
    LNode *A, *B, *C, *D;
    int a[10] = {1,3,5,7};
    createListR(A, a, 4);
    printLinkedListH("删除前-A", A);
    SearchAndDelete(A, 5);
    printLinkedListH("删除后-A", A);

}

void test04(){
    // 获取链表长度
    LNode *A;
    int a[10] = {1,3,5,7};
    createListR(A, a, 4);
    printLinkedListH("A", A);
    int len = getLength(A);
    printf("%d", len);
}

void test05(){
    // 指定位置插入节点元素
    LNode *A;
    int a[10] = {1,3,5,7};
    createListR(A, a, 4);
    printLinkedListH("A", A);
    insertLinkedList(A, 6, 10);
    printLinkedListH("A", A);
}

void test06(){
    // 删除指定位置的节点
    LNode *A;
    int a[10] = {1,3,5,7};
    createListR(A, a, 4);
    printLinkedListH("A", A);
    int del=0;
    delElem(A, 2, del);
    printLinkedListH("A", A);
    printf("%d", del);
}

void test07(){
    // 获取指定位置处的节点元素
    LNode *A;
    int a[10] = {1,3,5,7};
    createListR(A, a, 4);
    printLinkedListH("A", A);
    int data=0;
    findElem(A, 4, data);
    printf("%d", data);
}
// =========== 测试 =========== //

int main(){
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    test07();
}

