//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题58 - I. 翻转单词顺序
    请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
    输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
    例如输入字符串"I am a student. "，则输出"student. a am I"。

示例 1：
    输入: "the sky is blue"
    输出: "blue is sky the"

示例 2：
    输入: "  hello world!  "
    输出: "world! hello"
    解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
    输入: "a good   example"
    输出: "example good a"
    解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 思路1:
    1. 翻转每个单词
    2. 翻转整个字符串
 */
/**
翻转字符串
*/
void reverseWord(string &s, int begin, int end){
    for(; begin<end; begin++,end--){
        std::swap(s[begin], s[end]);
    }
}

string reverseWords(string s) {
    vector<string> strs;
    string res="";

    // 字符串转为字符数组、处理多空格
    for(char ch:s){
        if(ch==' '){
            if(res!="")
                strs.push_back(res);
            res = "";
        }else{
            res += ch;
        }
    }
    if(res!="")
        strs.push_back(res);

    // 1. 翻转每个单词
    res = "";
    int size = (int)strs.size();
    for(int i=0; i<size; i++){
        reverseWord(strs[i], 0, strs[i].size()-1);
        res += strs[i];
        if(i!=size-1) res += " ";
    }

    // 2. 翻转整个字符串
    reverseWord(res, 0, res.size()-1);

    return res;
}