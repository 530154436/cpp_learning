//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题03. 数组中重复的数字
    找出数组中重复的数字。
    在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
    请找出数组中任意一个重复的数字。

示例 1：
    输入：[2, 3, 1, 0, 2, 5, 3]
    输出：2 或 3

限制：
    2 <= n <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 解题思路：
    初始化集合为空集合，重复的数字 repeat = -1
    遍历数组中的每个元素：
        (1) 将该元素加入集合中，判断是否添加成功
        (2) 如果添加失败，说明该元素已经在集合中，因此该元素是重复元素，将该元素的值赋给 repeat，并结束遍历
        (3) 返回 repeat
Java
 */
int findRepeatNumber(vector<int>& nums) {
    unordered_map<int, int> uniNums;
    int res;
    for(int num:nums){
        if(uniNums.find(num)!=uniNums.end()){
            res = num;
            break;
        }else{
            uniNums[num]+=1;
        }
    }
    return res;
}