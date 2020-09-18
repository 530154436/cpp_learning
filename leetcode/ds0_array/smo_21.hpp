//
// Created by Edward on 2020/2/2.
//
#include "../lib.hpp"

/**
面试题21. 调整数组顺序使奇数位于偶数前面
    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

示例：
    输入：nums = [1,2,3,4]
    输出：[1,3,2,4]
    注：[3,1,2,4] 也是正确的答案之一。
 
提示：
    1 <= nums.length <= 50000
    1 <= nums[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
 解题思路：双指针
    “双指针”，分别是指向数组头部的指针 i，与指向数组尾部的指针 j。过程如下：
        (1) i 向右移动，直到遇到偶数；j 向左移动，直到遇到奇数
        (2) 检查 i 是否小于 j，若小于，交换 i 和 j 的元素，回到上一步骤继续移动；否则结束循环
    时间复杂度是 O(N),空间复杂度是 O(1)。
 */
vector<int> exchange(vector<int>& nums) {
    if(nums.empty()) return nums;

    int i=0, j=(int)nums.size()-1;
    while(i<j){
        while(i<j && nums[i]%2!=0) i++; // 找到第1个偶数
        while(i<j && nums[j]%2==0) j--; // 找到第1个奇数
        if(i<j) swap(nums[i], nums[j]);
    }
    return nums;
}
