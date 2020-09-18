//
// Created by Edward on 2020/2/19.
//
#include "ds1_string/lc242.hpp"
#include "ds1_string/lc125.hpp"
#include "ds1_string/lc246.hpp"
#include "ds1_string/smo_5.hpp"
#include "ds1_string/smo_44.hpp"
/*
 125. 验证回文串
 242. 有效的字母异位词
 246. 中心对称数
 面试题05. 替换空格
 面试题38. 字符串的排列  xxx
 面试题44. 数字序列中某一位的数字
 面试题48. 最长不含重复字符的子字符串
 面试题58 - I. 翻转单词顺序
 面试题58 - II. 左旋转字符串
 面试题50. 第一个只出现一次的字符
 1071. 字符串的最大公因子
 */

int main(){
    // 242. 有效的字母异位词
    string s = "anagram", t = "nagaram";
    cout<<isAnagram(s, t)<<endl;

    // 125. 验证回文串
    s = "A man, a plan, a canal: Panama";
    cout<<isPalindrome(s)<<endl;

    // 246. 中心对称数
    s = "88";
    cout<<isStrobogrammatic(s)<< endl;

    //面试题44. 数字序列中某一位的数字
    cout<<findNthDigit(10)<<endl;
}
