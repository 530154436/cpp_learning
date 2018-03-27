//
// Created by 郑楚彬 on 2018/3/26.
//
#include <stdio.h>
#include "../utility/SqList.h"

using namespace std;

/**
 * 例题 1  已知一个顺序表 L，其中的元素递增有序排列，设计一个算法插入一个元素 x (x 为 int 型)后
 *         保持该顺序表仍然递增有序排列(假设插入操作总能成功，即插入后表 长不会大于 MAX)。
 */

// 返回第一个比 x 大的元素的位置
int findElement(SqList L, int x){
    int p;
    for(p=0; p<L.length; p++){
        if(L.data[p] > x){
            return p;
        }
    }
    return p;
}

// 将元素 x 插入表中
void insert(SqList &L, int x){
    int p;
    p = findElement(L, x);

    // 其他元素后移
    for(int i=L.length; i>=p; i--){
        L.data[i+1] =L.data[i];
    }

    L.data[p] = x;
    L.length++;
}

void test1(SqList &sqlist){
    printSqList(sqlist.data, sqlist.length);
    insert(sqlist, 7);
    printSqList(sqlist.data, sqlist.length);
    insert(sqlist, 16);
    printSqList(sqlist.data, sqlist.length);
    insert(sqlist, 20);
    printSqList(sqlist.data, sqlist.length);
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

void test2(SqList &sqlist){
    int e = 0;
    deleteByPosition(sqlist, 5, e);
    printSqList(sqlist.data, sqlist.length);
    cout << e << endl;
}

int main(){
    // 初始化结构体
    SqList sqlist;
    sqlist.length = 0;
    for(int i=1; i<10; i++){
        sqlist.data[i]=i+10;
        sqlist.length++;
    }

    test1(sqlist);
    test2(sqlist);
}

