//
// Created by Edward on 2020/2/12.
//
#include "../lib.hpp"

/**
75. 颜色分类(荷兰国旗问题)
 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

    示例:

    输入: [2,0,2,1,1,0]
    输出: [0,0,1,1,2,2]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sort-colors
 */
/*
 解题思路:
    初始化0的最右边界：p0 = 0。在整个算法执行过程中 nums[idx < p0] = 0.
    初始化2的最左边界 ：p2 = n - 1。在整个算法执行过程中 nums[idx > p2] = 2.
    初始化当前考虑的元素序号 ：curr = 0.

    While curr <= p2 :
    若 nums[curr] = 0 ：交换第 curr个 和 第p0个 元素，并将指针都向右移。
    若 nums[curr] = 2 ：交换第 curr个和第 p2个元素，并将 p2指针左移 。
    若 nums[curr] = 1 ：将指针curr右移。
 */

void sortColors(vector<int>& nums) {
    int p0=0, pcur=0, p2=(int)nums.size()-1;
    while(pcur<=p2){
        switch(nums[pcur]){
            case 0: swap(nums[pcur], nums[p0]); p0++; pcur++;
                break;
            case 2: swap(nums[pcur], nums[p2]); p2--;
                break;
            case 1: pcur++;
            default: break;
        }
    }
}
