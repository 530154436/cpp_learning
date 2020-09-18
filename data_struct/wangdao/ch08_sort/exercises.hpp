//
// Created by Edward on 2020/9/10.
//

#ifndef TIANQINDATASTRUCT_EXERCISES_HPP
#define TIANQINDATASTRUCT_EXERCISES_HPP

#include <stdlib.h>
#include "../templates/LinkListTemplate.hpp"
#include "sort.hpp"

/*
 * 8.3 交换排序 p323-p324
 */
                                                        /** ★★☆ 冒泡排序 */
void BubbleSort(ElemType A[], int n);                   // 2. 双向冒泡排序算法

                                                        /** ★★☆ 基于快排划分思想 */
void move(ElemType A[], int n);                         // 3. 把所有奇数移动到所有偶数前边的算法
void move2(ElemType A[], int n);
int Partition2(ElemType A[], int low, int high);        // 4. 重新编写快速排序的划分算法，使之每次选取的枢轴值都是随机地从当前子表中选择的。
int kth_elem(ElemType A[] , int low, int high, int k);  // 5. 数组中找出第 k 小的元素
int setPartition(ElemType A[], int n);                  // 6. 将A划分为两个不相交的子集，满足 |n_1-n_2| 最小且 |S_1-S_2| 最大
int PartitionN(ElemType A[],int n);                     // 4. (8.6)数组{K_1,K_2，...，K_n}, 将 K_n，放在将元素排序后的正确位置上

                                                        /** ★★☆ 三指针 */
void Flag_A_rrange(ElemType A[],int n);                 // 7. 荷兰国旗问题

/*
 * 8.4 选择排序 p335
 */
                                                        /** ❌ */
void selectSort(LNode<ElemType> *&L);                   // 4. 在基于单链表表示的待排序关键字序列上进行简单选择排序。
                                                        /** ❌ */
bool IsMinHeap(ElemType A[], int len);                  // 5. 试设计一个算法，判断一个数据序列是否构成一个小根堆。

/*
 * 8.6 各种内部排序算法的比较和应用
 */
                                                        /** ★★☆ 插入排序 */
void Insert_Sort(ElemType A[] , int m, int n);          // 2. 前m个元素递增有序，后n个元素递增有序，设计一个算法，使得整个顺序表有序。


#endif //TIANQINDATASTRUCT_EXERCISES_HPP
