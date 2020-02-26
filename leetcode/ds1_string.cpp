//
// Created by 郑楚彬 on 2020/2/19.
//
#include "ds1_string/lc242.hpp"
#include "ds1_string/lc125.hpp"
#include "ds1_string/lc246.hpp"
/*
 125. 验证回文串
 242. 有效的字母异位词
 246. 中心对称数
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
}
