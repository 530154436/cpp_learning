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

// ================= 测试 ================= //
void test1(SqList &sqlist){
    printSqList("插入前", sqlist);
    insert(sqlist, 7);
    printSqList("插入7", sqlist);
    insert(sqlist, 16);
    printSqList("插入16", sqlist);
    insert(sqlist, 20);
    printSqList("插入20", sqlist);
}

void test2(SqList &sqlist){
    int e = 0;
    deleteByPosition(sqlist, 5, e);
    printSqList("删除下标为5", sqlist);
    cout << e << endl;
}
// ================= 测试 ================= //

int main(){
    // 初始化结构体
    SqList sqlist;
    sqlist.length = 0;
    for(int i=1; i<10; i++){
        sqlist.data[i]=i+10;
        sqlist.length++;
    }

    test1(sqlist);
    // test2(sqlist);
}

