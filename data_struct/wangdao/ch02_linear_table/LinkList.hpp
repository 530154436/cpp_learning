//
// Created by Edward on 2020/9/3.
//
#ifndef TIANQINDATASTRUCT_LINKLIST_HPP
#define TIANQINDATASTRUCT_LINKLIST_HPP

#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * 单链表 (带头结点)
 */
typedef int ElemType;           // 元素数据类型
typedef struct LNode{
    ElemType data;              // 数据域
    struct LNode* next;         // 指针域
}LNode, *LinkList;

/**
 * 单链表的基本操作
 */
LinkList List_HeadInsert(LinkList &L, int a[], int n);  // 采用头插法建立单链表
LinkList List_TailInsert(LinkList &L, int a[], int n);  // 采用尾插法建立单链表
LNode *GetElem(LinkList L, int i);                      // 按位查找操作。获取表 L 中第 i 个位置的元素的值。
LNode *LocateElem(LinkList L, ElemType e);              // 按值查找操作。在表 L 中查找具有给定关键宇值的元素。
void PrintLinkList(LinkList L);                         // 输出操作。按前后顺序输出线性表 L 的所有元素值。
int Length(LinkList L);                                 // 求表长。返回线性表 L 的长度，即 L 中数据元素的个数。

/**
 * 双链表
 */
typedef struct DNode{           // 定义双链表结点类型
    ElemType data ;             // 数据域
    struct DNode *prior,*next;  // 前驱和后继

    int freq;                   // 频度域 => 练习 2.2线性表的链式表示第20题 p40-p44
}DNode, *DLinkList ;


#endif //TIANQINDATASTRUCT_SQLIST_HPP
