//
// Created by 郑楚彬 on 2020/2/2.
//
#include "../lib.hpp"

/**
167. 两数之和 II - 输入有序数组
    给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
    函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

    说明:
        返回的下标值（index1 和 index2）不是从零开始的。
        你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
    示例:
        输入: numbers = [2, 7, 11, 15], target = 9
        输出: [1,2]
        解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
 */

/*
 解题思路：
  使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。
  (1) 如果两个指针指向元素的和 sum == target，那么得到要求的结果；
  (2) 如果 sum > target，移动较大的元素，使 sum 变小一些；
  (3) 如果 sum < target，移动较小的元素，使 sum 变大一些。
  数组中的元素最多遍历一次，时间复杂度为 O(N)。只使用了两个额外变量，空间复杂度为 O(1)。
 */

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    int l=0, sum=0,  r=(int)numbers.size()-1;
    while(l<r){
        sum = numbers[l]+numbers[r];
        if(sum==target){
            res.push_back(l+1);
            res.push_back(r+1);
            break;
        }else if(sum<target){
            l++;
        }else{
            r--;
        }
    }
    return res;
}
