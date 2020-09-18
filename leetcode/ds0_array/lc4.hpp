//
// Created by Edward on 2020/2/15.
//
#include <vector>
/**
 4. 寻找两个正序数组的中位数
    给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

    请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
    你可以假设 nums1 和 nums2 不会同时为空。

    示例 1:
        nums1 = [1, 3]
        nums2 = [2]
        则中位数是 2.0
    示例 2:
        nums1 = [1, 2]
        nums2 = [3, 4]
        则中位数是 (2 + 3)/2 = 2.5

    https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 */
/*
 解题思路： 双指针 => 等价于求第n个节点 (非最优解)
 */
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    int n1=nums1.size(),n2=nums2.size();
    int i=0,j=0,mid=(n1+n2)/2, pre=0,median=0;

    for(int k=0; k<=mid; k++){
        pre = median;
        if(i<nums1.size() && (j>=n2||nums1[i]<nums2[j])){
            median=nums1[i++];
        }else{
            median=nums2[j++];
        }
    }
    return (n1+n2)%2==0?(median+pre)/2.0:median;
}