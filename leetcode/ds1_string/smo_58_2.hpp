//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题58 - II. 左旋转字符串
    字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
    比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：
    输入: s = "abcdefg", k = 2
    输出: "cdefgab"

示例 2：
    输入: s = "lrloseumgh", k = 6
    输出: "umghlrlose"

限制：
    1 <= k < s.length <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 思路1:
    1. 将字符分为两部分，并分别翻转
    2. 翻转整个字符串
 */
/**
翻转字符串
*/
/*
翻转字符串
*/
void reverseWord(string &s, int begin, int end){
    for(; begin<end; begin++,end--){
        std::swap(s[begin], s[end]);
    }
}

string reverseLeftWords(string s, int n) {
    if(n==0) return s;
    int size = (int)s.size();
    reverseWord(s, 0, n-1);     // 翻转前半部
    reverseWord(s, n, size-1);  // 翻转后半部
    reverseWord(s, 0, size-1);  // 翻转整个字符串
    return s;
}