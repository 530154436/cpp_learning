//
// Created by 郑楚彬 on 2020/2/19.
//
#include "ds0_array/lc167.hpp"
#include "ds0_array/lc977.hpp"
#include "ds0_array/lc26.hpp"
#include "ds0_array/lc88.hpp"
#include "ds0_array/lc283.hpp"

/**
左右指针
167. 两数之和 II - 输入有序数组
977. 有序数组的平方
 88. 合并两个有序数组

快慢指针
 26. 删除排序数组中的重复项
 283. 移动零
 */

int main(){
    std::vector<int> nums,res;
    string s;

    // 167. 两数之和 II - 输入有序数组
    nums = {2, 7, 11, 15};
    res = twoSum(nums, 9);
    display<int>(nums);
    display<int>(res);

    // 977. 有序数组的平方
    // 344. 反转字符串
    nums = {-4,-1,0,3,10};
    res = sortedSquares(nums);
    display(nums);
    display(res);

    // 88. 合并两个有序数组
    std::vector<int> nums1={1,2,3,0,0,0}, nums2={2,5,6};
    int m=3, n=3;
    display(nums1);
    merge(nums1, m, nums2, n);
    display(nums1);

    // 26. 删除排序数组中的重复项
    nums = {0,0,1,1,1,2,2,3,3,4};
    display(nums);
    removeDuplicates(nums);
    display(nums);

    // 283. 移动零
    nums = {0,1,0,3,12};
    display(nums);
    moveZeroes(nums);
    display(nums);

    // 75. 颜色分类(荷兰国旗问题)
    nums = {2,0,2,1,1,0};
    display<int>(nums);
    sortColors(nums);
    display<int>(nums);
}