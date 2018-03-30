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