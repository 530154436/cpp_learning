//
// Created by Edward on 2020/9/3.
//
#include "SqList.hpp"
#include "LinkList.hpp"
#include <climits>
/*
 * 练习 2.2 线性表的顺序实现 p19-p21
 */
                                                        /** ★★☆ 双指针、归并 */
void Reverse(SqList &L);                                // 2. 将顺序表 L 的所有元素逆置
void Reverse(ElemType A[], int m, int n, int size);     // 8. 将数组顺序表位置互换
                                                        // 10. 将 R 中保存的序列循环左移 p (O<p<n ) 个位置

void del_x_2(SqList &L,ElemType x);                     // 3. 删除线性表中所有值为 x 的数据元素
bool Delete_Same(SqList& L);                            // 6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。

bool Del_s_t(SqList &L, ElemType s, ElemType t);        // 4. 从有序顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素
bool Del_s_t2(SqList &L, ElemType s, ElemType t);       // 5. 从顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素

bool Merge(SqList A, SqList B, SqList &C);              // 7. 将两个有序顺序表合并为一个新的有序顺序表

                                                        /** ★★☆  二分查找 */
void SearchExcgIst(ElemType A[], int n, ElemType x);    // 9. 线性表递增有序，在表中查找数值为 x 的元素
int MSearch(int A[],int B[],int n);                     // 11. 找出两个序列 A 和 B 的中位数。
double MSearch1(int A[], int m, int B[],int n);
int MSearch2(int A[],int B[],int n);                    /** ❌ */

                                                        /** ★★☆  其他 */
bool Del_Min(SqList &L, ElemType &value);               // 1. 从顺序表中删除具有最小值的元素
int Majority (int A[], int n);                          // 12. 找出数组 A 的主元素
int findMissMin(int A[] , int n);                       // 13. 找出数组中未出现的最小正整数


/*
 * 练习 2.2 线性表的链式表示 p40-p44
 */
                                                        /** ★★★ 双指针、快慢指针 */
LinkList Search_Lst_Common(LinkList L1, LinkList L2);   // 8. 给定两个单链表，编写算法找出两个链表的公共结点。
LNode* find_addr(LNode *strl , LNode *str2);            // 22.找出由 str1 和 str2 所指向两个链表共同后缀的起始位置

int Search_k(LinkList list, int k);                     // 21.查找链表中倒数第 k 个位直上的结点(k为正整数)
LNode* FindLoopStart(LNode *head);                      // 24.判断一个链表是否有环，如果有，找出环的入口点并返回，否则返回 NULL。
void change_list(LNode*&h);                             // 25. 单链表{a1,a2,··· ,an}转换为{a1,an,a2,an-1,a3,an-2,···}

                                                        /** ★★☆ 删除节点 */
void Del_X_1(LinkList &L, ElemType x);                  // 1. 设计一个递归算法, 删除不带头结点的单链表 L 中所有值为 x 的结点。

void Del_X_2(LinkList &L, ElemType x);                  // 2. 在带头结点的单链表 L 中，删除所有值为 x 的结点
void RangeDelete(LinkList &L, int min, int max);        // 7. 删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素
void Del_Same(LinkList &L);                             // 12.递增有序的单链表表去重(去掉数值相同的元素)

LinkList Delete_Min(LinkList &L);                       // 4. 带头结点的单链表 L 中删除一个最小值结点
void MinDelete(LinkList &head);                         // 9. 按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间
void Del_All(LinkList &L);                              // 19.反复找出单链表中结点值最小的结点并输出，然后将该结点从中删除，直到单链表空为止，再删除表头结点。

                                                        /** ★★☆ 链表排序、头插法、尾插法 */
void R_Print(LinkList L);                               // 3. 带头结点的单链表从尾到头反向输出每个结点的值
LinkList Reverse_1(LinkList &L);                        // 5. 将带头结点的单链表就地逆置

void Sort(LinkList &L);                                 // 6. 有一个带头结点的单链表 L，设计一个算法使其元素递增有序。

LinkList DisCreat_1(LinkList &A);                       // 10.将一个带头结点的单链表 A 分解为两个带头结点的单链表 A 和 B
LinkList DisCreat_2(LinkList &A);                       // 11.单链表 A 分解为A={a1,a2,··· , an,}, B={bn,bn-1,...,b2,b1}

LinkList MergeList(LinkList La,LinkList Lb);            // 13.将两个按元素值递增次序排列的单链表归并为一个递减的单链表
LinkList Get_Common(LinkList A, LinkList B);            // 14.从两个元素递增有序的单链表(带头结点)中的公共元素产生单链表C
void Union(LinkList &la, LinkList &lb);                 // 15.求两个元素递增排列的单链表 A 与 B 的交集，并存放于 A 链表中。

                                                        /** ★☆☆ 循环单链表、循环双链表 */
int Symmetry(DLinkList L);                              // 17.判断带头结点的循环双链表是否对称。
LinkList Link(LinkList &h1 , LinkList &h2);             // 18.将循环单链表h2 链接到循环单链表h1，要求链接后的链表仍保持循环链表。
DLinkList Locate(DLinkList &L,ElemType x);              // 20.非循环双向链表符合要求的 Locate(L,x) 运算的算法

                                                        /** ★☆☆ 其他 */
int Pattern(LinkList A,LinkList B);                     // 16. 判断序列 B 是否是序列 A 的连续子序列
void func(LNode* &h, int n);                            // 23.对于链表中 data 的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点

/*
 * 思维拓展 p63
 */
/**
 * 1. 一个长度为 N 的整型数组 A[1..N]，给定整数 x，请设计一个时间复杂度不超过 O(nlog2n) 的算法，
 *    查找出这个数组中所有两两之和等于 X 的整数对(每个元素只输出一次)。
 *
 * 面试题57. 和为s的两个数字
 * 链接：https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof
 */
