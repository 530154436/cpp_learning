//
// Created by Edward on 2020/2/14.
//
#include <deque>
#include "../lib.hpp"

/**
面试题09. 用两个栈实现队列
    用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：
    输入：["CQueue","appendTail","deleteHead","deleteHead"]
         [[],[3],[],[]]
    输出：[null,null,3,-1]

示例 2：
    输入：["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
         [[],[],[5],[2],[],[]]
    输出：[null,-1,null,null,5,2]

提示：
    1 <= values <= 10000
    最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 解题思路:
    1. 加入队尾 appendTail()函数： 将数字 val 加入栈 s1 即可。
    2. 删除队首deleteHead()函数： 有以下三种情况。
        (1) 当s1、s2均为空，返回 -1
        (2) 当s2为空，将栈 s1 元素全部转移至栈 s2 中，实现元素倒序，并返回栈 s2 的栈顶元素。
        (3) 当s2不为空，s2中仍有已完成倒序的元素，直接返回 B 的栈顶元素。
 */

class CQueue {
    public:
        stack<int> s1;
        stack<int> s2;

        CQueue() {

        }

        void appendTail(int value) {
            s1.push(value);
        }

        int deleteHead() {
            if(s1.empty() && s2.empty()) return -1;
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top()); s1.pop();
                }
            }
            int res = s2.top(); s2.pop();
            return res;
        }
};