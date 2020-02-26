//
// Created by 郑楚彬 on 2020/2/14.
//
#include <deque>
#include <queue>
#include "../lib.hpp"

/**
面试题59 - II. 队列的最大值
    请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。
    若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：
    输入: ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
         [[],[1],[2],[],[],[]]
    输出: [null,null,null,2,1,2]

示例 2：
    输入: ["MaxQueue","pop_front","max_value"]
         [[],[],[]]
    输出: [null,-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
 */

/*
 解题思路(单调队列):  队列+双端队列
    1. 用一个队列**保存正常元素**，另一个**双端**队列保存**单调递减的元素**
    2. 入队时，第一个队列正常入队；
              第二个队列是一个递减(单调)的双端队列，**从尾部**把所有小于当前value的元素删除
    3. 出队时，第一个队列正常出栈；
              第二个队列的**头部**与出栈的值作比较，如果相同，那么一起出栈
 */

class MaxQueue {
    public:
        queue<int> q;
        deque<int> dq;

        int max_value() {
            if(dq.empty()) return -1;
            return dq.front();
        }

        void push_back(int value) {
            q.push(value);
            while(!dq.empty() && value>dq.back()) // 从尾部把所有小于当前value的元素删除
                dq.pop_back();
            dq.push_back(value);
        }

        int pop_front() {
            if(q.empty()) return -1;
            int front = q.front();
            if(dq.front()==front)
                dq.pop_front();
            q.pop();
            return front;
        }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */