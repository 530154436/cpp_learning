//
// Created by Edward on 2020/2/2.
//
#include "../lib.hpp"

/**
283. 移动零
    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
    输入: [0,1,0,3,12]
    输出: [1,3,12,0,0]
说明:
    必须在原数组上操作，不能拷贝额外的数组。
    尽量减少操作次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/move-zeroes
 */

/*
 解题思路：
  双指针
  (1) 指针 “j” 表示快指针,负责处理新元素。
      指针 "i" 表示慢指针,负责存储非 0 元素
  (2) 在 “j” 索引到达数组的末尾之后，所有非 0 元素都已按原始顺序移动到数组的开头。
  (3) “i” 索引之后的所有元素用 0 覆盖。
C++
 */

void moveZeroes(vector<int>& nums) {
    int n = (int)nums.size(), i=0;
    for(int j=0; j<n; j++){
        if(nums[j]!=0)
            nums[i++] = nums[j];
    }
    for(int j=i; j<n; j++)
        nums[j] = 0;
}
