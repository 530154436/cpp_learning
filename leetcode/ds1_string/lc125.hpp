//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
125. 验证回文串
    给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：
    本题中，我们将空字符串定义为有效的回文串。

示例 1:
    输入: "A man, a plan, a canal: Panama"
    输出: true

示例 2:
    输入: "race a car"
    输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
 */

/*
 解题思路： 双指针
 */
bool isAlphabet(char c){
    return ('A'<=c && c<='Z') || ('a'<=c && c<='z');
}

bool isNum(char c){
    return '0'<=c && c<='9';
}

bool isPalindrome(string s) {
    vector<char> valid_s;
    for(int i=0; i<s.size(); i++){
        if(isAlphabet(s[i]) || isNum(s[i])){
            if('A'<=s[i] && s[i]<='Z'){
                valid_s.push_back((char)(s[i]-'A'+'a')); // 大小写转换
            }else{
                valid_s.push_back(s[i]);
            }
        }
    }

    // 双指针 => 首尾元素比较
    int i=0, j=(int)valid_s.size()-1;
    while(i<j){
        // cout<< valid_s[i]<<','<<valid_s[j]<<endl;
        if(valid_s[i]!=valid_s[j]) return false;
        i++; j--;
    }

    return true;
}