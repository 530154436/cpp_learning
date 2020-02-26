//
// Created by 郑楚彬 on 2020/2/14.
//
#include <deque>
#include "../lib.hpp"

/**
面试题59 - I. 滑动窗口的最大值
 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:
    输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
    输出: [3,3,5,5,6,7]
解释:
      滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
 */

/*
 解题思路:
    双端队列（保存当前窗口最大值的数组位置）
    1. 维护一个递减(单调)的双端队列，**从尾部**把所有小于当前value的元素删除
    2. 判断队首元素下标是否在滑动窗口内部, i 始终为滑动窗口的头
    3. 压入当前value下标
    4. 当窗口长度第一次达到k后，开始保存当前窗口中最大值，滑动窗口的最大值总是位于队列的头部
 */

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    vector<int> result;                                 // 保存最终结果
    deque<int> tmp;                                     // 双端队列 保证队列中数组位置的数值按从大到小排序
    for(int i=0; i<nums.size(); i++){
        while(!tmp.empty() && nums[i]>nums[tmp.back()]) // 保证从大到小 如果前面数小则需要依次弹出，直至满足要求
            tmp.pop_back();

        while(!tmp.empty() && i-k+1>tmp.front())        // 判断当前队列中队首的值是否有效
            tmp.pop_front();

        tmp.push_back(i);                               // 添加当前值对应的数组下标

        if(i-k+1>=0)                                    // 当窗口长度第一次达到k后，开始保存当前窗口中最大值
            result.push_back(nums[tmp.front()]);        // 滑动窗口的最大值总是位于队列的头部
    }
    return result;
}