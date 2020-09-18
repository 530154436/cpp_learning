//
// Created by Edward on 2020/2/20.
//
#include "ds6_heap/lc347.hpp"
#include "ds6_heap/lc215.hpp"
/*
堆(优先队列)
 215. 数组中的第K个最大元素
 347. 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 面试题40. 最小的k个数
 */

int main(){
    vector<int> nums, result;
    int res;

    // 215.
    nums = {3,2,1,5,6,4};
    res = findKthLargest(nums, 2);
    display<int>(nums);
    cout<<res<<endl;

    // 347.
    nums = {5,3,1,1,1,3,73,1};
    result = topKFrequent(nums, 2);
    display<int>(result);
}