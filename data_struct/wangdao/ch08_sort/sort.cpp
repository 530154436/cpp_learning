//
// Created by 郑楚彬 on 2020/9/11.
//
#include "sort.hpp"

/**
 * 直接插入排序
 *
 * 基本思想:
 *      每次将一个待排序的记录按其关键字大小插入到前面己排好序的子序列中，直到全部记录插入完成。
 *      (1) 从前面的有序子表中查找出待插入元素应该被插入的位置;
 *      (2) 给插入位置腾出空间，将待插入元素复制到表中的插入位置。
 */
void InsertSort(ElemType A[], int n){
    int i,j,tmp;

    for(i=1; i<n; i++){
        if(A[i]<A[i-1]){                        // 若A[i]关键码小于其前驱, 将A[i]插入有序表
            tmp = A[i];
            for(j=i-1; j>=0 && tmp<A[j]; --j)   // 从后往前查找待插入位置(第1个比A[i]小)
                A[j+1] = A[j];                  // 向后挪位
            A[j+1] = tmp;                       // 复制到插入位置
        }
    }
}

/**
 * ﻿折半插入排序
 *
 * 基本思想:
 *      与直接插入排序区别: 先折半查找出元素的待插入位置，然后统一地移动待插入位置之后的所有元素。
 */
void BinaryInsertSort(ElemType A[] , int n){
    int i,j,tmp,l,h,mid;

    for(i=1; i<n; i++){

        tmp = A[i];

        // 折半查找
        l=0,h=i-1;                  // 设置折半查找的范围
        while(l<=h){                // 折半查找(默认递增有序)
            mid = (l+h)/2;
            if(tmp<A[mid])
                h = mid-1;
            else
                l = mid+1;
        }

        // 统一后移元素，空出插入位置
        for(j=i-1; j>=h+1;--j)
            A[j+1] = A[j];

        A[j+1] = tmp;
    }
}

/**
 * 希尔排序
 *
 * 基本思想是:
 *      先将待排序表分割成若干形如 L[i, i+d, i+2d,..., i+kd] 的“特殊” 子表，即把相隔某个"增量"的记录组成一个子表，
 *      对各个子表分别进行直接插入排序，当整个表中的元素呈“基本有序”时，再对全体记录进行一次直接插入排序。
 */
void ShellSort(ElemType A[] , int n){
    int i,j,tmp,d;

    for(d=n/2; d>=1; d/=2){
        for(i=d; i<n; i++){

            // 类似直接插入排序                       // 所有距离为d的倍数的记录放在同一组，在各组内进行直接插入排序;
            if(A[i]<A[i-d]){                        // 需将 A[i] 插入有序增量子表
                tmp = A[i];
                for(j=i-d; j>=0 && tmp<A[j]; j-=d)
                    A[j+d] = A[j];                  // 记录后移， 查找插入的位置
                A[j+d] = tmp;
            }

        }
    }
}

/**
 * 冒泡排序
 *
 * 算法思想:
 *      从后往前(或从前往后)两两比较相邻元素的值，若为逆序(即 A[i-1]>A[i])，则交换它们，直到序列比较完。
 */

void swap(ElemType &a, ElemType &b){
    ElemType tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(ElemType A[] , int n){
    int i,j;
    bool flag;

    for(i=0;i<n-1;i++){
        flag = false;               // 表示本趟冒泡是否发生交换的标志
        for(j=n-1;j>i;j--){         // 一趟冒泡过程(关键字最小的元素如气泡-般逐渐往上“漂浮”直至“水面”)
            if(A[j-1]>A[j]){
                swap(A[j-1], A[j]);
                flag = true;
            }
        }
        if(!flag)                   // 本趟遍历后没有发生交换，说明表已经有序
            return;
    }
}

/**
 * 快速排序
 *
 * 算法思想:
 *      在待排序表 L[1...n] 中任取一个元素 pivot 作为枢轴(或基准，通常取首元素)，通-过一趟排序，将待排序表划分为独立的两部分
 *      L[1...k-1] 和 L[k+1...n], 使得 L[1...k-1] 中的所有元素小于 pivot, L [k+1...n] 中的所有元素大于等于 pivot，
 *      则 pivot 放在了其最终位置 L(k)上，这个过程称为一趟快速排序(或一次划分)。
 *      然后分别递归地对两个子表重复上述过程，直至每部分内只有一个元素或空为止，则所有元素放在了其最终位置上。
 */
int partition(ElemType A[] , int low, int high){
    int pivot = A[low];                             // 将当前表中第一个元素设为枢轴，对表进行划分
    while(low<high){
        while(low<high && A[high]>=pivot) --high;
        A[low] = A[high];                           // 将比枢轴小的元素移动到左端

        while(low<high && A[low]<=pivot) ++low;
        A[high] = A[low];                           // 将比枢轴大的元素移动到右端
    }
    A[low] = pivot;                                 //枢轴元素存放到最终位置
    return low;
}

void QuickSort(ElemType A[] , int low, int high){
    if(low<high){
        int pivot_pos = partition(A, low, high);     // 将表A[low···high]划分为两个子表
        QuickSort(A, low, pivot_pos-1);             // 依次对两个子表进行递归排序
        QuickSort(A, pivot_pos+1, high);
    }
}

/**
 * 选择排序
 *
 * 算法思想:
 *    每一趟(如第i趟)在后面 n-i+1 个待排序元素中选取关键字最小的元素，作为有序子序列的第 i 个元素，
 *    直到第 n-1 趟做完，待排序元素只剩下 1 个，就不用再选了。
 */
void SelectSort (ElemType A[], int n){
    int i,j,min;

    for(i=0; i<n-1; i++){
        min = i;                    // 记录最小元素位置
        for(j=i+1; j<n;j++){        // 在 A[i...n-1] 中选择最小的元素
            if(A[min]>A[j])
                min = j;            // 更新最小元素位置
        }
        if(min!=j)
            swap(A[i], A[min]);
    }
}