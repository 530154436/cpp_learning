//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题15. 二进制中1的个数
    请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

示例 1：
    输入：00000000000000000000000000001011
    输出：3
    解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。

示例 2：
    输入：00000000000000000000000010000000
    输出：1
    解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。

示例 3：
    输入：11111111111111111111111111111101
    输出：31
    解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    根据 与运算 定义，设二进制数字 n ，则有：
        (1) 若 n&1=0，则 n 二进制 最右一位 为 0 ；
        (2) 若 n&1=1，则 n 二进制 最右一位 为 1 ；
    根据以上特点，考虑以下 循环判断 ：
        (1) 判断 n 最右一位是否为 1 ，根据结果计数。
        (2) 将 n 右移一位

作者：jyd
链接：https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/solution/mian-shi-ti-15-er-jin-zhi-zhong-1de-ge-shu-wei-yun/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
int hammingWeight(uint32_t n) {
    int cnt = 0;
    while(n){
        cnt += (n&1); // 末位与运算，结果为0或1
        n >>= 1;
    }
    return cnt;
}