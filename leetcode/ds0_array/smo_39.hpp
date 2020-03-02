//
// Created by 郑楚彬 on 2020/2/2.
//
#include "../lib.hpp"

/**
面试题39. 数组中出现次数超过一半的数字
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
    你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:
    输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
    输出: 2
 
限制：
    1 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof
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
int majorityElement(vector<int>& nums) {
    if(nums.empty()) return -1;
    int res=nums[0], cnt=1;
    for(int i=1; i<(int)nums.size(); i++){
        if(nums[i]==res){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt==0) {
            res=nums[i]; cnt=1;
        }
    }
    return res;
}
