//
// Created by 郑楚彬 on 2020/8/27.
//
#include <iomanip>
#include <iostream>

#include "ch02_linear_table/exercises.hpp"

void init(SqList &L, int a[], int n){
    for(int i=0; i<n; i++)
        L.data[i] = a[i];
    L.length = n;
}

void exercise_2_2(){
    SqList L; InitList(L);                      // 初始化顺序表
    int a[10]={7, 8, 9, 11, 12, 4, 4, 6, 8, 10};
    init(L, a, 10);

    SqList L2; InitList(L2);
    int b[10]={1, 1, 3, 4, 4, 6, 7, 7, 9, 11};
    init(L2, b, 10);

    SqList L3; InitList(L3);

    int indent=100;
    std::cout<<std::left<<std::setw(indent-15)<<"初始化(无序表): "; PrintList(L);
    std::cout<<std::left<<std::setw(indent-15)<<"初始化(有序表): "; PrintList(L2);

    int value;
    std::cout<<std::left<<std::setw(indent)<<"1. 从顺序表中删除具有最小值的元素: ";
    Del_Min(L, value); PrintList(L);

    std::cout<<std::left<<std::setw(indent)<<"2. 将顺序表 L 的所有元素逆置: ";
    Reverse(L); PrintList(L);

    std::cout<<std::left<<std::setw(indent)<<"3. 删除线性表中所有值为 x=8 的数据元素: ";
    del_x_2(L, 8); PrintList(L);

    init(L2, b, 10);
    std::cout<<std::left<<std::setw(indent)<<"4. 从有序顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素 [5,10]: ";
    Del_s_t(L2, 5, 10); PrintList(L2);

    init(L, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"5. 从顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素 [5,10]: ";
    Del_s_t2(L, 5, 10); PrintList(L);

    init(L2, b, 10);
    std::cout<<std::left<<std::setw(indent)<<"6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同: ";
    Delete_Same(L2); PrintList(L2);

    init(L2, b, 10);
    std::cout<<std::left<<std::setw(indent)<<"7. 将两个有序顺序表合并为一个新的有序顺序表: ";
    Merge(L2, L2, L3); PrintList(L3);

    init(L2, b, 10);
    std::cout<<std::left<<std::setw(indent)<<"8. 将数组顺序表位置互换: ";
    Reverse(L2.data, 4, 6, 10); PrintList(L2);

    init(L2, b, 10);
    std::cout<<std::left<<std::setw(indent)<<"9. 线性表递增有序，在表中查找数值为 x 的元素: ";
    SearchExcgIst(L2.data,10, 8); PrintList(L2);
}

void exercise_2_3(){
    LinkList L1, L2;
    int a[10]={7, 8, 9, 11, 12, 4, 4, 6, 8, 10}; List_HeadInsert(L1, a, 10);
    int b[10]={1, 1, 3, 4, 4, 6, 7, 7, 9, 11};   List_TailInsert(L2, b, 10);

    int indent=90;
    std::cout<<std::left<<std::setw(indent-15)<<"初始化(无序表): "; PrintLinkList(L1);
    std::cout<<std::left<<std::setw(indent-15)<<"初始化(有序表): "; PrintLinkList(L2);

    std::cout<<std::left<<std::setw(indent)<<"获取表 L 中第 6 个位置的元素的值: ";
    std::cout<<GetElem(L1, 6)->data<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"在表 L 中查找具有给定关键宇值(10)的元素: ";
    std::cout<<LocateElem(L1, 10)->data<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"获取链表长度: ";
    std::cout<<Length(L1)<<std::endl;
}

int main(){
    //exercise_2_2();
    exercise_2_3();
}