//
// Created by 郑楚彬 on 2018/3/27.
//

#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

/**
 * 顺序表结构
 */
typedef struct SqList{
    int data[MAX];
    int length;
} SqList;

/**
 * 例题 2 删除顺序表 L 中下标为 p(1≤p≤length)的元素，成功返回 1，否则返回 0，并将被删除元素的值赋值给 e。
 */
int deleteByPosition(SqList &L, int p, int &e){
    if(p>L.length || p<1){
        return 0;
    }
    e = L.data[p];
    for(int i=p; i<L.length; i++){
        L.data[i] = L.data[i+1];
    }
    L.length--;
    return 1;
}

/**
 * 打印顺序表
 * @param a
 * @param len
 */
void printSqList(int *a, int len){
    if(a==NULL){
        printf("数组为空!!!");
        return;
    }
    printf("数组: [");
    for(int i=0; i<len-1; i++){
        printf("%d ",a[i]);
    }
    printf("%d]\n", a[len-1]);
}