//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题38. 字符串的排列
    输入一个字符串，打印出该字符串中字符的所有排列。
    你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:
    输入：s = "abc"
    输出：["abc","acb","bac","bca","cab","cba"]
 
限制：
    1 <= s 的长度 <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    1. 把字符串分为两个部分：
        (1) 一部分是字符串的第1个字符；另一部分是第1个字符以后的所有字符。
        (2) 拿第1个字符和它后面的字符逐个交换。
    2. 固定第1个字符，求后面所有字符的全排列。(递归)
 */
void permutation(set<string> &res, string s, int begin){
    if(begin==(int)s.size())
        res.insert(s);  // 找到一个排列，记录下来

    for(int i=begin; i<(int)s.size(); i++){
        swap(s[i], s[begin]);           // 把 i 换到第一位
        permutation(res, s, begin+1);   // 全排列剩下部分
        swap(s[i], s[begin]);           // 归位
    }
}

vector<string> permutation(string s) {
    set<string> res;
    permutation(res, s, 0);  // 全排列
    return vector<string> (res.begin(), res.end());
}