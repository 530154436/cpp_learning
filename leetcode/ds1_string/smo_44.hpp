//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题44. 数字序列中某一位的数字
    数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
    请写一个函数，求任意第n位对应的数字。

示例 1：
    输入：n = 3
    输出：3

示例 2：
    输入：n = 11
    输出：0

限制：
    0 <= n < 2^31

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 思路:
    对于第 n 位对应的数字，我们令这个数字对应的数为 target，然后分三步进行。
    1. 首先找到这个数字对应的数是几位数，用 digit 表示；
    2. 然后确定这个对应的数的数值 target；
    3. 最后确定返回值是 target 中的哪个数字。

作者：z1m
链接：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/zhe-shi-yi-dao-shu-xue-ti-ge-zhao-gui-lu-by-z1m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */
int findNthDigit(int n) {
    // 根据n确定该数由几位数组成: ${digit}
    long base=9, digit=1;
    while(n-base*digit>0){
        n -= base*digit;
        base *= 10;
        digit++;
    }

    // 确定该数的具体数值
    int idx = n%digit, num = 1;    // idx: 该数字的第 idx 位; num: 表示该数
    if(idx==0) idx=digit;
    for(int i=2; i<=digit; i++)
        num *= 10;
    num +=(idx==digit ? n/digit-1 : n/digit); // idx==0时为该数的上一个

    // 求该数第 idx 位的数值
    for(int i=digit; i>idx; i--) num /= 10;
    return num%10;
}
