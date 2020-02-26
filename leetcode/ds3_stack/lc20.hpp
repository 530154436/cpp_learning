//
// Created by 郑楚彬 on 2020/2/19.
//
#include "../lib.hpp"
/**
20. 有效的括号
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    注意空字符串可被认为是有效字符串。

示例 1:
    输入: "()"
    输出: true
示例 2:
    输入: "()[]{}"
    输出: true
示例 3:
    输入: "(]"
    输出: false
示例 4:
    输入: "([)]"
    输出: false
示例 5:
    输入: "{[]}"
    输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
 */

/*
 解题思路：
    利用一个栈，不断地往里压左括号，一旦遇上右括号，就把栈顶的左括号弹出来，表示这是一个合法的组合，
    以此类推，直到最后判断栈里还有没有左括号剩余。
 */
bool isValid(string s) {
    stack<char> ss;
    for(char ch:s){
        if(ch=='}' || ch==']' || ch==')'){
            if(ss.empty()
               || (ss.top()!='(' && ch==')')
               || (ss.top()!='{' && ch=='}')
               || (ss.top()!='[' && ch==']'))
                return false;
            ss.pop();
        }else{
            ss.push(ch);
        }
    }
    return ss.empty();
}