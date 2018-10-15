//
// Created by 郑楚彬 on 2018/5/23.
//

#define MAX 100
#include "../Printer.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * 直接插入排序
 *
 * @param R
 * @param n
 */
void insertSort(int R[], int n){
    int tmp;
    int i,j;
    for(i=1; i<n; i++){
        tmp = R[i];
        // 大于待排元素则后移，即找到第一个小于tmp的数组下标
        for(j=i-1; j>=0 && R[j]>tmp; j--){
            R[j+1] = R[j];
        }
        // 找到插入位置
        R[j+1] = tmp;
        string result = "第 " + to_string(i) + " 趟排序结果";
        printIntArray(result, R, 8);
    }
}

/**
 * 折半插入排序
 *
 * @param R
 * @param n
 */
void binaryInsertSort(int R[], int n){
    int i,j,low,high,mid;
    int tmp;
    for(i=1; i<n; i++){
        tmp = R[i];
        low = 0;
        high = i-1;
        // 折半查找
        while(low<=high){
            mid = (low + high)/2;
            if(tmp>R[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        // 将high+1后面的数组整体后移
        for(j=i-1; j>=high+1; j--){
            R[j+1] = R[j];
        }
        R[j+1] = tmp;
        string result = "第 " + to_string(i) + " 趟排序结果(low=" + to_string(low) + ",high=" + to_string(high)+ ",mid=" + to_string(mid) +")";
        printIntArray(result, R, 8);
    }
}

/**
 * 希尔排序
 *
 * @param R
 * @param n
 */
void shellSort(int R[], int n){
    int i,j,tmp,gap;
    // 计算趟数
    int count=0;

    // 初始步长为 n/2
    // 最后一遍步长为1，算法变为插入排序，这就保证了数据一定会被排序。
    for(gap=n/2; gap > 0; gap/=2){
        for(i=gap; i<n; i++){
            tmp = R[i];
            // 插入时采用移动法 => gap=1时为直接插入排序
            for(j=i-gap; j>=0 && R[j]>tmp; j-=gap){
                R[j+gap] = R[j];
            }
            R[j+gap] = tmp;
            string result = "gap=" + to_string(gap);
            printIntArray(result, R, n);
        }
        string result = "第 " + to_string(++count) + " 趟排序结果("+"gap=" + to_string(gap) +")";
        printIntArray(result, R, n);
    }
}

/**
 * 冒泡排序
 *
 * @param R
 * @param n
 */
void bubbleSort(int R[], int n){
    int i,j,tmp, flag;
    for(i=0; i<n-1; i++){
        flag = 0;
        // 将小的排在最前面
        for(j=n-1; j>i; j--){
            // 交换
            if(R[j-1]>R[j]){
                tmp = R[j];
                R[j] = R[j-1];
                R[j-1] = tmp;
                flag = 1;
            }
        }
        string result = "第 " + to_string(i) + " 趟排序结果";
        printIntArray(result, R, n);

        // 如果一趟排序没有发生交换，则证明有序，排序结束
        if (flag == 0) return;
    }
}

/**
 * 快速排序
 *
 * @param R
 * @param l
 * @param r
 */
void quickSort(int R[], int l, int r){
    int i=l,j=r,tmp;

    if(l<r){
        tmp = R[l];
        while(i!=j){
            // 从右向左扫描找到一个小于tmp的元素
            while(i<j && R[j]>=tmp) j--;
            if(i<j){
                // 放在tmp左边，i指针右移一位
                R[i] = R[j];
                i++;
            }

            // 从左向右扫描找到一个大于tmp的元素
            while(i<j && R[i]<=tmp) i++;
            if(i<j){
                // 放在tmp右边, j左移一位
                R[j] = R[i];
                j--;
            }
        }
        R[i] = tmp;

        string result = "i=" + to_string(i) + ", pivot=" + to_string(tmp) + ", l=" + to_string(l) + ", r=" + to_string(r);
        printIntArray(result, R, 8);

        // 对tmp左边元素进行排序
        quickSort(R, l, i-1);
        // 对tmp右边元素进行排序
        quickSort(R, i+1, r);
    }
}

/**
 * 简单选择排序
 *
 * @param R
 * @param n
 */
void selectSort(int R[], int n){
    int k,i,j,tmp;
    for(i=0; i<n; i++){
        k = i;
        // 找出 i 之后的元素中最小的一个
        for(j=i+1; j<n;j++){
            if(R[k] > R[j]){
                k = j;
            }
        }
        // 最小元素与 i 交换
        tmp = R[i];
        R[i] = R[k];
        R[k] = tmp;

        string result = "第 " + to_string(i+1) + " 趟排序结果";
        printIntArray(result, R, n);
    }
}

/**
 * 最大堆调整( 保证父节点最大 )
 *
 * @param R
 * @param low
 * @param high
 */
void maxHeapify(int R[], int low, int high){
    // 父节点和左孩子(数组从0开始)
    int i=low, j = 2*i + 1;
    int tmp = R[i];
    while(j <= high){

        // 如果右孩子较大，则 j 指向右孩子
        if(j<high && R[j]<R[j+1]){
            j++;
        }

        // 将 R[j] 调整到双亲节点的位置上
        if(tmp < R[j]){
            R[i] = R[j];
            i = j;
            j = 2*i + 1;
        }else{
            // 调整结束
            break;
        }
    }
    R[i] = tmp;
    string result = "(low=" + to_string(low) + ", hight="+to_string(high) + ")";
    printIntArray(result, R, 9);
}

/**
 * 初始化最大堆
 *
 * @param R
 * @param n
 */
void buildHeap(int R[], int n){
    // 初始化堆，i从最后一个父节点开始调整
    for(int i=n/2-1; i>=0; i--){
        maxHeapify(R, i, n-1);
    }
}

/**
 * 堆排序
 *
 * @param R
 * @param n
 */
void heapSort(int R[],  int n){
    int tmp,i;

    // 创建堆
    buildHeap(R, n);

    // 先将第一个元素(最大的元素)和已排数组最后一个元素做交换，再重新调整
    for(i=n-1; i>0; i--){
        // 交换
        tmp = R[0];
        R[0] = R[i];
        R[i] = tmp;

        string result = "第 " + to_string(n-i) + " 趟排序结果";
        printIntArray(result, R, n);

        // 在减少一个元素的无序列中进行调整
        maxHeapify(R, 0, i-1);
    }
}

// 定义临时数组用于保存原数组原数组元素
int* temp = (int *) malloc((MAX)*sizeof(int));

/**
 * 一次归并 (合并两个已排序的子数组为一个有序数组)
 *
 * @param R
 * @param low
 * @param mid
 * @param high
 */
void merge(int R[], int low, int mid, int high){
    // b1[] => a[low .. mid]  左子数组
    // b2[] => b[mid+1.. high] 右子数组

    int i,j,k;

    // 复制数组元素
    for(i=low; i<=high; i++){
        temp[i] = R[i];
    }

    // 合并两个已排序的子数组为一个有序数组
    for(i=low, j=mid+1, k=low; i<=mid && j<=high; k++){
        if(temp[i]<=temp[j]){
            R[k] = temp[i++];
        }else{
            R[k] = temp[j++];
        }
    }

    // 如果左子数组还有剩余元素，则追加到临时数组的末尾
    while(i<=mid) R[k++] = temp[i++];

    // 如果右子数组还有剩余元素，则追加到临时数组的末尾
    while(j<=high) R[k++] = temp[j++];

    string resultTmp = "=> temp (low=" + to_string(low) + ", mid=" + to_string(mid) + ", high=" + to_string(high) +")";
    printIntArray(resultTmp, temp, 5);
    string result = "=>    R (low=" + to_string(low) + ", mid=" + to_string(mid) + ", high=" + to_string(high) +")";
    printIntArray(result, R, 5);
}

/**
 * 二路归并排序 (递归版本)
 *
 * @param R
 * @param low
 * @param high
 */
void mergeSort(int R[], int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        string result = "=> (low=" + to_string(low) + ", mid=" + to_string(mid) + ", high=" + to_string(high) +")";
        cout << result << endl;

        mergeSort(R, low, mid);
        mergeSort(R, mid+1, high);
        merge(R, low, mid, high);
    }
}



