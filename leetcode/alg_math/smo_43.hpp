//
// Created by 郑楚彬 on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题43. 1～n整数中1出现的次数
    输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
    例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

示例 1：
    输入：n = 12
    输出：5

示例 2：
    输入：n = 13
    输出：6

限制：
    1 <= n < 2^31

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    当计算右数第 i 位包含的 X 的个数时：
        1. 取第 i 位左边（高位）的数字，乘以 10i−1，得到基础值 a。
        2. 取第 i 位数字，计算修正值：
            (1) 如果大于 X，则结果为 a+10i−1。
            (2) 如果小于 X，则结果为 a。
            (3) 如果等 X，则取第 i 位右边（低位）数字，设为 b，最后结果为 a+b+1。

        https://www.cnblogs.com/cyjb/p/digitOccurrenceInRegion.html

 */
int countDigitOne(int n) {
    return count(n, 1);
}

// 计算数字 X 在 1-n 中出现的次数。
int count(int n, int x) {
    int cnt = 0, k=n;
    long i=1;
    while(k>0) {
        // k / 10 为高位的数字。
        cnt += (k / 10) * i;
        // 当前位的数字。
        int cur = k % 10;
        if (cur > x) {
            cnt += i;
        } else if (cur == x) {
            // n - k * i 为低位的数字。
            cnt += n - k * i + 1;
        }

        i *= 10;
        k = n / i;
    }
    return cnt;
}