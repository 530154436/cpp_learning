//
// Created by 郑楚彬 on 2020/2/2.
//
#include "../lib.hpp"

/**
面试题57. 和为s的两个数字
    输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

示例 1：
    输入：nums = [2,7,11,15], target = 9
    输出：[2,7] 或者 [7,2]

示例 2：
    输入：nums = [10,26,30,31,47,60], target = 40
    输出：[10,30] 或者 [30,10]
 
限制：
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

/*
 解题思路：
  使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。
  (1) 如果两个指针指向元素的和 sum == target，那么得到要求的结果；
  (2) 如果 sum > target，移动较大的元素，使 sum 变小一些；
  (3) 如果 sum < target，移动较小的元素，使 sum 变大一些。
  数组中的元素最多遍历一次，时间复杂度为 O(N)。只使用了两个额外变量，空间复杂度为 O(1)。
 */

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int l=0, sum=0,  r=(int)nums.size()-1;
    while(l<r){
        sum = nums[l]+nums[r];
        if(sum==target){
            res.push_back(nums[l]);
            res.push_back(nums[r]);
            break;
        }else if(sum<target){
            l++;
        }else{
            r--;
        }
    }
    return res;
}
