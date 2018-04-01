//
// Created by 郑楚彬 on 2018/3/27.
//
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

/**
 * 顺序表结构
 */
typedef struct SqList{
    int data[MAX]; // 存储表中元素的数组
    int length;    // 顺序表长度
} SqList;

/**
 * ﻿顺序表的初始化
 * @param L
 */
void init(SqList &L){
    L.length = 0;
}

/**
 * 创建初始顺序表
 *
 * @param sqList
 * @param a
 * @param len
 */
void createSqList(SqList &sqList, int a[], int len){
    sqList.length = 0;
    for(int i=0; i<len; i++){
        sqList.data[i]=a[i];
        sqList.length++;
    }
}

/**
 * 插入数据元素
 * @param L
 * @param p
 * @param e
 * @return
 */
int insert(SqList &L, int p, int e){
    // 第p个位置插入元素
    //位置错误或者表长已经达到
    if(p<1 || p>L.length+1 || L.length==MAX){
        return 0;
    }
    int i;
    // 元素后移
    for(i=L.length-1; i>=p; i--){
        L.data[i+1] = L.data[i];
    }
    L.data[p-1] = e;
    L.length++;
}

/**
 * 删除数据元素
 *
 * @param L
 * @param p
 * @param e
 * @return
 */
int delElem(SqList &L, int p, int &e){
    if(p<1 || p>L.length){
        return 0;
    }
    int i;
    e = L.data[p-1];
    // 元素前移
    for(i=p-1; i<L.length-1; i++){
        L.data[i] = L.data[i+1];
    }
    L.length--;
    return 1;
}

/**
 * 按元素值查找
 *
 * @param L
 * @param e
 */
int locateElem(SqList L, int e){
    int i;
    for(i=0; i<L.length; i++){
        if(L.data[i] == e){
            return i;
        }
    }
    return 0;
}

/**
 * 求指定位置元素
 * s
 * @param L
 * @return
 */
int getElem(SqList L, int p, int &e){
    if(p<1 || p>L.length){
        return 0;
    }
    e = L.data[p];
    return 1;
}

/**
 * 打印顺序表
 * @param a
 * @param len
 */
void printSqList(char * name, SqList sqList){
    printf("顺序表 %s : [", name);
    for(int i=0; i<sqList.length; i++){
        printf(" %d ",sqList.data[i]);
    }
    printf("]\n");
}