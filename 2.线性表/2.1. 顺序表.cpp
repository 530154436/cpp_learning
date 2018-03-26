//
// Created by 郑楚彬 on 2018/3/26.
//
#include <stdio.h>
#include "../utility/Printer.h"

using namespace std;

#define MAX 100

typedef struct SqList{
    int data[MAX];
    int length;
} SqList;


/*
例题 1  已知一个顺序表 L，其中的元素递增有序排列，设计一个算法插入一个元素 x (x 为 int 型)后
        保持该顺序表仍然递增有序排列(假设插入操作总能成功，即插入后表 长不会大于 MAX)。  */

/*
 * 返回第一个比 x 大的元素的位置
 */
int findElement(SqList L, int x){
    int p;
    for(p=0; p<L.length; p++){
        if(L.data[p] > x){
            return p;
        }
    }
    return p;
}

void insert(SqList &L, int x){
    int p;
    p = findElement(L, x);
    for(int i=L.length; i>=p; i--){
        L.data[i+1] =L.data[i];
    }
    L.data[p] = x;
    L.length++;
}

void test1(){
    // 初始化结构体
    SqList sqlist;
    sqlist.length = 0;
    for(int i=0; i<10; i++){
        sqlist.data[i]=i+10;
        sqlist.length++;
    }
    printArray(sqlist.data, sqlist.length);
    insert(sqlist, 7);
    printArray(sqlist.data, sqlist.length);
    insert(sqlist, 16);
    printArray(sqlist.data, sqlist.length);
    insert(sqlist, 20);
    printArray(sqlist.data, sqlist.length);
}

int main(){
    test1();
}

