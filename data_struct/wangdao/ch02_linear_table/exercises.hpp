//
// Created by 郑楚彬 on 2020/9/3.
//
#include "SqList.hpp"
#include "LinkList.hpp"

/*
 * 练习 2.2 线性表的顺序实现 p19-p21
 */
bool Del_Min(SqList &L, ElemType &value);               // 1. 从顺序表中删除具有最小值的元素
void Reverse (SqList &L);                               // 2. 将顺序表 L 的所有元素逆置

                                                        /** ★★☆ */
void del_x_2(SqList &L,ElemType x);                     // 3. 删除线性表中所有值为 x 的数据元素
bool Del_s_t(SqList &L, ElemType s, ElemType t);        // 4. 从有序顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素
bool Del_s_t2(SqList &L, ElemType s, ElemType t);       // 5. 从顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素

                                                        /** ★★☆ */
bool Delete_Same(SqList& L);                            // 6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。

                                                        /** ★★☆ */
bool Merge(SqList A, SqList B, SqList &C);              // 7. 将两个有序顺序表合并为一个新的有序顺序表

void Reverse(ElemType A[], int m, int n, int size);     // 8. 将数组顺序表位置互换
                                                        // 10. 将 R 中保存的序列循环左移 p (O<p<n ) 个位置

                                                        /** ★★☆ */
void SearchExcgIst(ElemType A[], int n, ElemType x);    // 9. 线性表递增有序，在表中查找数值为 x 的元素

                                                        /** ★★★ */
int MSearch(int A[],int B[],int n);                     // 11. 找出两个序列 A 和 B 的中位数。
int Majority (int A[], int n);                          // 12. 找出数组 A 的主元素
int findMissMin(int A[] , int n);                       // 13. 找出数组中未出现的最小正整数


/*
 * 练习 2.2 线性表的链式表示 p40-p44
 */
void Del_X_1(LinkList &L, ElemType x);                  // 1. 设计一个递归算法, 删除不带头结点的单链表 L 中所有值为 x 的结点。
void Del_X_2(LinkList &L, ElemType x);                  // 2. 在带头结点的单链表 L 中，删除所有值为 x 的结点
void R_Print(LinkList L);                               // 3. 带头结点的单链表从尾到头反向输出每个结点的值
LinkList Delete_Min(LinkList &L);                       // 4. 带头结点的单链表 L 中删除一个最小值结点
LinkList Reverse_1(LinkList &L);                        // 5. 将带头结点的单链表就地逆置
void Sort(LinkList &L);                                 // 6. 有一个带头结点的单链表 L，设计一个算法使其元素递增有序。
void RangeDelete(LinkList &L, int min, int max);        // 7. 删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素
LinkList Search_Lst_Common(LinkList L1, LinkList L2);   // 8. 给定两个单链表，编写算法找出两个链表的公共结点。
void MinDelete(LinkList &head);                         // 9. 按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间
LinkList DisCreat_1(LinkList &A);                       // 10.将一个带头结点的单链表 A 分解为两个带头结点的单链表 A 和 B









