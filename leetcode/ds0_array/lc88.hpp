//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
88. 合并两个有序数组
    给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:
    初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:
    输入: nums1 = [1,2,3,0,0,0], m = 3
         nums2 = [2,5,6],       n = 3
    输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
 */

/*
 解题思路： 双指针 => 直接插入排序
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i,j;
    for(i=0; i<n; i++){
        for(j=m-1; j>=0 && nums1[j]>nums2[i]; j--)  // 从后往前查找待插入位置
            nums1[j+1]=nums1[j];                    // 向后挪位
        nums1[j+1] = nums2[i];                      // 复制到插入位置
        m++;
    }
}