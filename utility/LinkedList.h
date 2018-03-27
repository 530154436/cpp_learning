//
// Created by 郑楚彬 on 2018/3/27.
//
#include <stdio.h>

/**
 * 单链表结构
 */
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode;

/**
 * 打印单链表(含头结点)
 * @param tmp
 * @param len
 */
void printLinkedListH(LNode *a){
    if(a==NULL){
        printf("单链表为空!!\n");
        return;
    }
    LNode *tmp;
    tmp = a->next;
    printf("单链表: [");
    while(tmp){
        printf(" %d ",tmp->data);
        tmp = tmp->next;
    }
    printf("]\n");
}