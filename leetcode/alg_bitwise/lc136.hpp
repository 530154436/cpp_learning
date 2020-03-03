//
// Created by 郑楚彬 on 2020/2/23.
//
#include "../lib.hpp"
/*
136. 只出现一次的数字
    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：
    你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
    输入: [2,2,1]
    输出: 1

示例 2:
    输入: [4,1,2,1,2]
    输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路: 异或(XOR)
    1. 真值表
        0⨁0=0 0⨁1=1 1⨁0=1 1⨁1=0
    2. 规律
        (1) 0 和二进制位做 XOR 运算，得到的仍然是这个二进制位，即 a⨁0=a
        (2) 对相同的二进制位做 XOR 运算，返回的结果是 0，即 a⨁a=0
    3. 满足交换律和结合律
        a⨁b⨁a = (a⨁a)⨁b = a⨁a⨁b = (a⨁a)⨁b = 0⨁b = b

作者：LeetCode
链接：https://leetcode-cn.com/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
int singleNumbers_2(vector<int> &nums) {
    int single = 0;
    for(int num:nums) single ^= num;
    return single;
}