//
// Created by 郑楚彬 on 2020/2/19.
//
#include "../lib.hpp"
/**
面试题30. 包含min函数的栈
    定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.min();   --> 返回 -3.
    minStack.pop();
    minStack.top();      --> 返回 0.
    minStack.min();   --> 返回 -2.
 
提示：
    各函数的调用总次数不超过 20000 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 解题思路： 单调栈
    1. 维护一个数据栈和一个最小值栈(一个从顶向下单调递增的栈)
    2. `最小值栈`PUSH条件:
        栈为空、或小于等于栈顶 (等于相当于重复最小值的情况)
    3. POP:
        检查是否pop了最小值，如果是，最小值栈也要跟着pop
 */
class MinStack {
public:
    stack<int> s;
    stack<int> minStack;
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if(minStack.empty() || x<=minStack.top())   // 栈为空、或小于栈顶
            minStack.push(x);
    }

    void pop() {
        if(minStack.top()==s.top()) // 最小值被弹出
            minStack.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int min() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */