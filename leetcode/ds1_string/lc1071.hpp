//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
1071. 字符串的最大公因子
    对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
    返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

示例 1：
    输入：str1 = "ABCABC", str2 = "ABC"
    输出："ABC"

示例 2：
    输入：str1 = "ABABAB", str2 = "ABAB"
    输出："AB"

示例 3：
    输入：str1 = "LEET", str2 = "CODE"
    输出：""

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 解题思路： 辗转相除法
 */
int gcd(int a, int b){
    if(a<b) std::swap(a, b);
    int r;
    while(b>0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

string gcdOfStrings(string str1, string str2) {
    if(str1+str2 != str2+str1) return "";
    return str1.substr(0, gcd(str1.size(), str2.size()));
}