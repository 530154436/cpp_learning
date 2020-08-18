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
    int i,j,Ri;
    for(i=1; i<n; i++){
        Ri = R[i];
        for(j=i-1; j>=0 && R[j]>Ri; j--)  // 从后往前查找待插入位置
            R[j+1] = R[j];                // 向后挪位
        R[j+1] = Ri;                      // 复制到插入位置
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
// 分区
int partion(int a[], int low, int high){
    int pivot = a[low];
    while(low < high){
        // 找到第1个比pivot小的值左移
        while( low<high && a[high]>=pivot ) high--;
        a[low] = a[high];

        // 找到第1个比pivot大的值右移
        while( low<high && a[low]<=pivot ) low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

// 快排
void quickSort(int a[], int low, int high){
    if(low >= high)
        return;
    // 分区
    int pivotpos = partion(a, low, high);
    string result = "pivotpos " + to_string(++pivotpos) + " 趟排序结果("+"pivot=" + to_string(a[pivotpos]) +")";
    printIntArray(result, a, high+1);
    // 分治
    quickSort(a, low, pivotpos-1);
    quickSort(a, pivotpos+1, high);
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

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

/**
 * 向下调整( 保证父节点最大 )
 *
 * @param a
 * @param k
 * @param len
 */
void adjustDown(int a[], int k, int len){
    string result = "(k=" + to_string(k) + ", len="+to_string(len) + ")";
    int p = a[k];                        // 父节点k
    for(int i=2*k+1; i<len; i=2*i+1){    // 沿key较大的子节点向下筛选
        if(i<len-1 && a[i]<a[i+1]) i++;  // 左右子节点中取最大
        if(p<a[i]){                     // 父子节点中取最大
            a[k] = a[i];
            k = i;
        }else{
            break;
        }
    }
    a[k] = p;
    printIntArray(result, a, len);
}

/**
 * 初始化最大堆
 *
 * @param a
 * @param n
 */
void buildHeap(int a[], int len){
    // 初始化堆，i从最后一个父节点开始调整
    for(int i=len/2-1; i>=0; i--){
        adjustDown(a, i, len);
    }
}

/**
 * 堆排序
 *
 * @param a
 * @param len
 */
void heapSort(int a[],  int len){
    int i;

    // 创建堆
    buildHeap(a, len);

    // 先将第一个元素(最大的元素)和已排数组最后一个元素做交换，再重新调整
    for(i=len-1; i>0; i--){
        swap(a[0], a[i]);

        string result = "第 " + to_string(len-i) + " 趟排序结果";
        printIntArray(result, a, len);

        // 在减少一个元素的无序列中进行调整
        adjustDown(a, 0, i);
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



