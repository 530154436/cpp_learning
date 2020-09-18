//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
242. 有效的字母异位词
    给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:
    输入: s = "anagram", t = "nagaram"
    输出: true
示例 2:
    输入: s = "rat", t = "car"
    输出: false
说明:
    你可以假设字符串只包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
 */

/*
 解题思路：
    小写字母一共 26 个，因此：利用一个长度为 26 的字符数组，
    将出现在字符串 s 里的字符个数加 1，而出现在字符串 t 里的字符个数减 1，最后判断每个小写字母的个数是否都为 0。
 */
bool isAnagram(string s, string t) {
    int n = (int)s.size();
    if(n!=t.size()) return false;

    int a[26] = {};
    for(int i=0; i<n; i++){
        a[(int)(s[i]-'a')] += 1;
        a[(int)(t[i]-'a')] -= 1;
    }
    for(int i:a){
        if(i>0 || i<0)
            return false;
    }
    return true;
}