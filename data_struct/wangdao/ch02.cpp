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
    LinkList L1, L2, L3;
    int a[10]={7, 8, 4, 11, 12, 4, 4, 6, 8, 10}; List_TailInsert(L1, a, 10);
    int b[10]={1, 1, 3, 4, 4, 6, 7, 7, 9, 11};   List_TailInsert(L2, b, 10);
    int c[10]={1, 2, 3, 4, 5, 9, 9, 12, 14, 15}; List_TailInsert(L3, c, 10);

    int indent=90;
    std::cout<<std::left<<std::setw(indent-15)<<"初始化(无序表L1): "; PrintLinkList(L1);
    std::cout<<std::left<<std::setw(indent-15)<<"初始化(有序表L2): "; PrintLinkList(L2);
    std::cout<<std::left<<std::setw(indent-15)<<"初始化(有序表L3): "; PrintLinkList(L3);

    std::cout<<std::left<<std::setw(indent)<<"获取表 L 中第 6 个位置的元素的值: ";
    std::cout<<GetElem(L1, 6)->data<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"在表 L 中查找具有给定关键宇值(10)的元素: ";
    std::cout<<LocateElem(L1, 10)->data<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"获取链表长度: ";
    std::cout<<Length(L1)<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"1. 设计一个递归算法, 删除不带头结点的单链表 L 中所有值为 x=8 的结点: ";
    Del_X_1(L1->next, 8);  PrintLinkList(L1);

    List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"2. 在带头结点的单链表 L 中，删除所有值为 x=4 的结点: ";
    Del_X_2(L1, 4);  PrintLinkList(L1);

    List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"3. 带头结点的单链表从尾到头反向输出每个结点的值: ";
    R_Print(L1);

    List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"4. 带头结点的单链表 L 中删除一个最小值结点: ";
    Delete_Min(L1);  PrintLinkList(L1);

    List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"5. 将带头结点的单链表就地逆置: ";
    Reverse_1(L1);  PrintLinkList(L1);

    List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"6. 有一个带头结点的单链表 L，设计一个算法使其元素递增有序: ";
    Sort(L1);  PrintLinkList(L1);

    List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"7. 删除表中所有介于给定的两个值(min=4,max=8)之间的元素的元素: ";
    RangeDelete(L1, 4, 8);  PrintLinkList(L1);

    LinkList A;
    List_TailInsert(A, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"10.将一个带头结点的单链表 A 分解为两个带头结点的单链表 A 和 B: "<<std::endl;
    LinkList B = DisCreat_1(A);
    std::cout<<std::left<<std::setw(indent)<<"   单链表 A :";PrintLinkList(A);
    std::cout<<std::left<<std::setw(indent)<<"   单链表 B :";PrintLinkList(B);

    List_TailInsert(A, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"11.单链表 A 分解为A={a1,a2,··· , an,}, B={bn,bn-1,...,b2,b1}: "<<std::endl;
    B = DisCreat_2(A);
    std::cout<<std::left<<std::setw(indent)<<"   单链表 A :";PrintLinkList(A);
    std::cout<<std::left<<std::setw(indent)<<"   单链表 B :";PrintLinkList(B);

    List_TailInsert(L2, b, 10);
    std::cout<<std::left<<std::setw(indent)<<"12.递增有序的单链表表去重(去掉数值相同的元素): ";
    Del_Same(L2);  PrintLinkList(L2);

    List_TailInsert(L2, b, 10);
    List_TailInsert(L3, c, 10);
    std::cout<<std::left<<std::setw(indent)<<"13.将两个按元素值递增次序排列的单链表归并为一个递减的单链表(L2+L3): ";
    LinkList Lc = MergeList(L2,L3);
    PrintLinkList(Lc);

    List_TailInsert(L2, b, 10);
    List_TailInsert(L3, c, 10);
    std::cout<<std::left<<std::setw(indent)<<"14.从两个元素递增有序的单链表(带头结点)中的公共元素产生单链表C: ";
    Lc = Get_Common(L2,L3);
    PrintLinkList(Lc);

    List_TailInsert(L2, b, 10);
    List_TailInsert(L3, c, 10);
    std::cout<<std::left<<std::setw(indent)<<"15.求两个元素递增排列的单链表 A 与 B 的交集，并存放于 A 链表中: ";
    Union(L2,L3);
    PrintLinkList(L2);

    List_TailInsert(L1, a, 10);
    LinkList L11;
    int a1[4]={11, 12, 4, 4}; List_TailInsert(L11, a1, 4);
    std::cout<<std::left<<std::setw(indent)<<"16. 判断序列 B 是否是序列 A 的连续子序列: ";
    std::cout<<std::left<<std::setw(indent)<<Pattern(L1->next, L11->next)<<std::endl;

    List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"21.查找链表中倒数第 k 个位直上的结点(k为正整数): ";
    Search_k(L1, 9);

    List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"23.对于链表中 data 的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点: ";
    func(L1, 12); PrintLinkList(L1);

    List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"25. 单链表{a1,a2,··· ,an}转换为{a1,an,a2,an-1,a3,an-2,···}: ";
    change_list(L1); PrintLinkList(L1);
}

int main(){
    //exercise_2_2();
    exercise_2_3();
}