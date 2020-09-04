//
// Created by 郑楚彬 on 2020/9/3.
//
#ifndef TIANQINDATASTRUCT_SQLIST_HPP
#define TIANQINDATASTRUCT_SQLIST_HPP

#include <iostream>
#include <cstdlib>
using namespace std;

#define MaxSize 50              // 定义线性袤的最大长度

/**
 * 线性表的顺序存储
 */
typedef int ElemType;           // 元素数据类型
typedef struct SqList{
    ElemType* data;             // 顺序表的元素(数组)
    int length;                 // 顺序表的当前长度
}SqList;                        // 顺序表的类型定义

/**
 * 线性表的基本操作
 */
bool InitList(SqList &L);                           // 初始化表。构造一个空的线性表 。
int Length(SqList L);                               // 求表长。返回线性表 L 的长度，即 L 中数据元素的个数。
int LocateElem(SqList L, ElemType e);               // 按值查找操作。在表 L 中查找具有给定关键宇值的元素。
ElemType GetElem(SqList L, int i);                  // 按位查找操作。获取表 L 中第 i 个位置的元素的值。
bool ListInsert(SqList &L, int i, ElemType e);      // 插入操作。在表 L 中的第 i 个位置上插入指定元素 e。
bool ListDelete(SqList &L, int i, ElemType &e);     // 删除操作。删除表 L 中第 i 个位置的元素，并用 e 返回删除元素的值。
void PrintList(SqList L);                           // 输出操作。按前后顺序输出线性表 L 的所有元素值。
bool Empty(SqList L);                               // 判空操作。若 L 为空表， 则返回 true，否则返回 false。
bool DestroyList(SqList &L);                        // 销毁操作。销毁线性表，井释放线性表 L 所占用的内存空间。

#endif //TIANQINDATASTRUCT_SQLIST_HPP
