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
template<typename ElemType>
struct LNode{
    ElemType data;              // 数据域
    struct LNode<ElemType>* next;         // 指针域
};

/**
 * 采用头插法建立单链表
 * @param L
 * @return
 */
template<typename ElemType>
LNode<ElemType>* List_HeadInsert(LNode<ElemType> *&L, ElemType a[], int n){
    L = (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));      // 创建头结点
    L->next = NULL;                         // 初始为空链表

    LNode<ElemType> *s;
    for(int i=0; i<n; i++){
        s = (LNode<ElemType> *)malloc(sizeof(LNode<ElemType>));  // 创建新结点
        s->data = a[i];
        s->next = L->next;                  // 将新结点插入表中， L 为头指针
        L->next = s;
    }
    return L;
}

/**
 * 采用尾插法建立单链表
 * @param L
 * @return
 */
template<typename ElemType>
LNode<ElemType>* List_TailInsert (LNode<ElemType> *&L, ElemType a[], int n){
    L = (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));      // 创建头结点
    L->data = 0;
    L->next = NULL;

    LNode<ElemType> *s,*r=L;
    for(int i=0; i<n; i++){
        s = (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));  // 创建新结点
        s->data = a[i];

        r->next = s;                        // r 指向新的表尾结点
        r = s;
    }
    r->next = NULL;
    return L;
}

/**
 * 按位查找操作。获取表 L 中第 i 个位置的元素的值。
 * @param L
 * @param i
 * @return
 */
template<typename ElemType>
LNode<ElemType>*GetElem(LNode<ElemType>*L, int i){
    if(i<0)
        return NULL;
    int k=0;
    while(L && k<i){
        L = L->next;
        k++;
    }
    return L;
}

/**
 * 按值查找操作。在表 L 中查找具有给定关键宇值的元素。
 * @param L
 * @param e
 * @return
 */
template<typename ElemType>
LNode<ElemType>*LocateElem(LNode<ElemType>* L, ElemType e){
    L = L->next;
    while(L){
        if(L->data==e)
            break;
        L = L->next;
    }
    return L;
}

/**
 * 获取链表长度
 * @param L
 * @return
 */
template<typename ElemType>
int Length(LNode<ElemType> *L){
    int length=0;
    LNode<ElemType> *p = L->next; // 指向第一个节点
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

/**
 * 输出操作。按前后顺序输出线性表 L 的所有元素值。
 * @param name
 * @param a
 */
template<typename ElemType>
void PrintLinkList(LNode<ElemType> *L){
    L = L->next;
    while(L){
        std::cout<<L->data<<" ";
        L = L->next;
    }
    std::cout<<std::endl;
}

#endif //TIANQINDATASTRUCT_SQLIST_HPP
