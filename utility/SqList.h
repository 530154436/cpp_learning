//
// Created by 郑楚彬 on 2018/3/27.
//
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
void printSqList(char* name, SqList sqList){
    printf("顺序表 %s : [", name);
    for(int i=0; i<sqList.length; i++){
        printf("%d ",sqList.data[i]);
    }
    printf("]\n");
}