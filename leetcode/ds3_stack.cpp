//
// Created by 郑楚彬 on 2020/2/20.
//
#include "ds3_stack/lc20.hpp"
#include "ds3_stack/lc739.hpp"

/*
 20. 有效的括号
739. 每日温度
 225. 用队列实现栈
 面试题30. 包含min函数的栈
 面试题31. 栈的压入、弹出序列
 */

int main(){
    vector<int> nums, res;
    string s;

    // 20. 有效的括号
    s = "([)]";
    cout<<isValid(s)<<endl;

    // 739. 每日温度
    nums = {73, 74, 75, 71, 69, 72, 76, 73};
    display<int>(nums);
    res = dailyTemperatures(nums);
    display<int>(res);
}