//
// Created by Edward on 2020/2/2.
//
#include "../lib.hpp"

/**
面试题42. 连续子数组的最大和
    输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
    要求时间复杂度为O(n)。

示例1:
    输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出: 6
    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

提示：
    1 <= arr.length <= 10^5
    -100 <= arr[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
 解题思路：
 思路1:
    先排序，再取中间值，中间值就是数组中出现次数超过一半的数字。
 思路2:
    1. 用res记录上一次访问的值，cnt表明当前值出现的次数，
       (1) 如果下一个值和当前值相同那么count++；否则count--，
       (2) 减到0的时候就要更换新的res值了，因为如果存在超过数组长度一半的值，那么最后target一定会是该值。
 */
int maxSubArray(vector<int>& nums) {
    int n = nums.size(), max=INT_MIN, sum=INT_MIN;
    for(int i=0; i<n; i++){
        if(sum<=0)
            sum = nums[i];
        else
            sum += nums[i];

        if(sum>max)
            max = sum;
    }
    return max;
}
