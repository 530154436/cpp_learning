//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
26. 删除排序数组中的重复项
    给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
    不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:
    给定数组 nums = [1,1,2],
    函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。

示例 2:
    给定 nums = [0,0,1,1,1,2,2,3,3,4],
    函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
    (不需要考虑数组中超出新长度后面的元素。)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
 */

/*
 解题思路：
    放置两个指针 i 和 j，其中 i 是慢指针，而 j 是快指针。只要 nums[i] = nums[j]，增加 j 以跳过重复项。
     (1) nums[i] \neq nums[j]:  nums[++i] = nums[j];
     (2) nums[i] \eq nums[j] :  跳过重复项
    重复相同的过程，直到 jj 到达数组的末尾为止。
 */
int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;
    int i=0;
    for(int j=0; j<nums.size(); j++){
        if(nums[i]!=nums[j]){
            nums[++i] = nums[j];
        }
    }
    return i+1;
}