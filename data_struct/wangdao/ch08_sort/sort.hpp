//
// Created by 郑楚彬 on 2020/9/11.
//

#ifndef TIANQINDATASTRUCT_SORTING_HPP
#define TIANQINDATASTRUCT_SORTING_HPP

#include "../templates/util.hpp"

typedef int ElemType;

/*
 *
 * 数组下标从0开始
 */

void InsertSort(ElemType A[], int n);               // 1. 直接插入排序
void BinaryInsertSort(ElemType A[] , int n);        // 2. 折半插入排序
void ShellSort(ElemType A[] , int n);               // 3. 希尔排序
void BubbleSort(ElemType A[] , int n);              // 4. 冒泡排序
void QuickSort(ElemType A[] , int low, int high);   // 5. 快速排序 (每趟排序后会将枢轴(基准)元素放到其最终的位置上)
void SelectSort (ElemType A[], int n);              // 6. 选择排序
void HeapSort(ElemType A[], int n);                 // 7. 堆排序
void MergeSort(ElemType A[],int low, int high) ;    // 8. 归并排序


#endif //TIANQINDATASTRUCT_SORTING_HPP
