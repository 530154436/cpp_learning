//
// Created by Edward on 2020/9/3.
//
#include "SqList.hpp"

/**
 * 初始化表。构造一个空的线性表 。
 */
bool InitList(SqList &L){
    L.data = (ElemType*)malloc(sizeof(ElemType)*MaxSize);
    L.length = 0;
    return true;
}

/**
 * 求表长。返回线性表 L 的长度，即 L 中数据元素的个数。
 */
int Length(SqList L){
    return L.length;
}

/**
 * 按值查找操作。在表 L 中查找具有给定关键宇值的元素
 */
int LocateElem(SqList L, ElemType e){
    for(int i=0; i<L.length; i++)
        if(L.data[i]==e)
            return i+1;             // 下标为 i 的元素值等于 e，返回其位序为 i+1
    return 0;
}

/**
 * 按位查找操作。获取表 L 中第 i 个位置的元素的值。
 */
ElemType GetElem(SqList L, int i){
    if(i<1 || i>L.length)               // 判断 i 的范围是否有效 (1<=i<=L.length)
        return -1;

    return L.data[i-1];
}

/**
 * 插入操作。在表 L 中的第 i 个位置上插入指定元素 e。
 */
bool ListInsert(SqList &L, int i, ElemType e){
    if(i<1 || i>L.length+1)             // 判断 i 的范围是否有效 (1<=i<=L.length+1)
        return false;

    if(L.length>=MaxSize)               // 当前存储空间己满，不能插入
        return false;

    for(int j=L.length; j>=i; j--)      // 将第 i个元素及之后的元素后移
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;                    // 在位置 i 处放入 e
    L.length++;
    return true;
}

/**
 * 删除操作。删除表 L 中第 i 个位置的元素，并用 e 返回删除元素的值。
 */
bool ListDelete(SqList &L, int i, ElemType &e){
    if(i<1 || i>L.length)               // 判断 i 的范围是否有效 (1<=i<=L.length)
        return false;

    if(L.length==0)                     // 线性表为空
        return false;

    e = L.data[i-1];                    // 将被删除的元素赋值给 e
    for(int j=i; j<L.length; j++)       // 将第 i 个位置后的元素前移
        L.data[i-1] = L.data[i];
    L.length--;
    return true;
}

/**
 * 输出操作。按前后顺序输出线性表 L 的所有元素值。
 */
void PrintList(SqList L){
    for(int i=0; i<L.length; i++)
        std::cout<<L.data[i]<<" ";
    std::cout<<std::endl;
}

/**
 * 判空操作。若 L 为空表， 则返回 true，否则返回 false。
 */
bool Empty(SqList L){
    return L.length==0;
}

/**
 * 销毁操作。销毁线性表，井释放线性表 L 所占用的内存空间。
 */
bool DestroyList(SqList &L){
    free(L.data);
    L.length = 0;
    return true;
}