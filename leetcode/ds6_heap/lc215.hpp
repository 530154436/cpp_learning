//
// Created by 郑楚彬 on 2020/2/2.
//
#include "../lib.hpp"

/**
215. 数组中的第K个最大元素
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
 1. 快排+二分查找:
    利用快速排序思想，对数组进行划分，并且判断划分的边界元素位置pivot_pos是否为第k大的数(k - 1)；
    若pivot_pos == k - 1则返回该数，
    若pivot_pos > k - 1说明第k大的数在左半边数组里；
    若pivot_pos < k - 1说明在右半边数组里。对其继续进行数组划分，直到找到第k大的数。
 */

int partition(vector<int>& nums, int low, int high){
    int pivot = nums[low];
    while(low<high){
        // 右移
        while(low<high && nums[high]>=pivot) high--;
        nums[low] = nums[high];

        // 左移
        while(low<high && nums[low]<=pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

int quickSort(vector<int>& nums, int k, int len){
    k = len-k;  // 升序; 降序: k = k-1;
    int low=0, high=len-1;
    while(low<=high){
        int pivot_pos = partition(nums, low, high);
        if(k==pivot_pos){
            return nums[k];
        }else if(k<pivot_pos){
            high = pivot_pos-1;
        }else{
            low = pivot_pos+1;
        }
    }
    return -1;
}


/*
 2. 建立大根堆
    将所有数组中的元素加入堆中，不断移除堆顶元素，直到第k次.
 */

void adjustDown(vector<int> &nums, int k, int len){
    int rootVal = nums[k];
    for(int i=2*k+1; i<len; i=(2*i+1)){
        if(i+1<len && nums[i]<nums[i+1]) i++;
        if(rootVal<nums[i]){
            nums[k] = nums[i];
            k = i;
        }else{
            break;
        }
    }
    nums[k] = rootVal;
}

void buildMaxHeap(vector<int> &nums, int len){
    for(int k=len/2-1; k>=0; k--){
        adjustDown(nums, k, len);
        //display<int>(nums);
    }
}

int heapSort(vector<int>& nums, int k, int len){
    //建堆
    buildMaxHeap(nums, len);

    for(int i=len-1; i>=len-k; i--){
        swap(nums[0], nums[i]);
        adjustDown(nums, 0, i);
    }
    return nums[len-k];
}

/*
 3. 建立小根堆
    先建一个容量为k的小根堆, 然后把剩下的大于堆顶的元素和堆顶交换并调整堆，最终的堆顶元素即为第k大值
 */

void adjustDown_min(vector<int> &nums, int k, int len){
    int rootVal = nums[k];
    for(int i=2*k+1; i<len; i=(2*i+1)){
        if(i+1<len && nums[i]>nums[i+1]) i++;
        if(rootVal>nums[i]){
            nums[k] = nums[i];
            k = i;
        }else{
            break;
        }
    }
    nums[k] = rootVal;
}

void buildMinHeap(vector<int> &nums, int len){
    for(int k=len/2-1; k>=0; k--){
        adjustDown_min(nums, k, len);
        //display<int>(nums);
    }
}

int heapSort_min(vector<int>& nums, int k, int len){
    //建堆
    buildMinHeap(nums, k);

    for(int i=k; i<len; i++){
        if(nums[i]>nums[0]){
            swap(nums[0], nums[i]);
            adjustDown_min(nums, 0, k);
        }
    }
    return nums[0];
}

int findKthLargest(vector<int>& nums, int k) {
    int len = (int)nums.size();
    //return quickSort(nums, k, len); // 二分法+快排
    //return heapSort(nums, k, len);  // 大顶堆排序
    return heapSort_min(nums, k, len);// 小顶堆
}