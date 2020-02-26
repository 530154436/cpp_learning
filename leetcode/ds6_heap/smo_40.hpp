//
// Created by 郑楚彬 on 2020/2/2.
//
#include "../lib.hpp"

/**
面试题40. 最小的k个数
    在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

    示例 1:
        输入: [3,2,1,5,6,4] 和 k = 2
        输出: 5
    示例 2:
        输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
        输出: 4
    说明:
        你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array

 */

/*
 解题思路:
    1. 创建大小为`k`的大根堆
    2. 从第 i = k+1 个元素开始跟大根堆的第一个元素,也就是当前 K 个元素里面的最大值进行比较
       当 arr[i] < heap[0] 时,交换这两个元素,并向下调整,如此进行 n-k 次.
    3. 时间复杂度为O(NlogK),空间复杂度为O(K).此方法在`海量数据`时应用比较好。
 */

void adjustDown(vector<int>& arr, int k, int len){
    int pVal = arr[k];
    for(int i=2*k+1; i<len; i=(2*i+1)){
        if(i+1<len && arr[i+1]>arr[i]) i++; // 右节点值>做节点值
        if(arr[i]>pVal){                    // 子节点最大值>根值
            arr[k] = arr[i];                // 向下调整
            k = i;
        }else{
            break;
        }
    }
    arr[k] = pVal;
}

void builMaxHeap(vector<int>& arr, int len){
    for(int i=len/2-1; i>=0; i--){      // 遍历根含有子节点的所有父节点
        adjustDown(arr, i, len);
    }
}

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if(k==0) return {};
    vector<int> maxHeap;
    for(int i=0; i<k; i++) maxHeap.push_back(arr[i]);

    // 创建大根堆
    builMaxHeap(maxHeap, k);

    // 加入新元素
    for(int i=k; i<(int)arr.size(); i++){
        if(arr[i]<maxHeap[0]){
            maxHeap[0] = arr[i];
            adjustDown(maxHeap, 0, k);
        }
    }
    return maxHeap;
}