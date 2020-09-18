//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题50. 第一个只出现一次的字符
    在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。

示例:
    s = "abaccdeff"
    返回 "b"

    s = ""
    返回 " "

限制：
    0 <= s 的长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

/*
 思路: 哈希表
    第1次遍历: {字符:计数}
    第2次遍历: 计数为1的字符直接返回
 */
char firstUniqChar(string s) {
    unordered_map<char, int> mp;
    for(char ch:s) mp[ch]++;
    for(char ch:s){
        if(mp[ch]==1) return ch;
    }
    return ' ';
}
