//
// Created by 郑楚彬 on 2020/2/19.
//
#include "../lib.hpp"
/**
225. 用队列实现栈(包括单队列、双队列)

使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 解题思路：单队列
    1. 用队列实现栈 C++ 单队列 入栈O(N) 出栈O(1)
    2. 维护队列使其队头对应栈的栈顶，队尾对应栈的栈底。则需要在每次在队列尾部加入元素之后将原本就有的que.size()-1个元素
    从头取出放回尾部以使队头对应栈顶，队尾对应栈底。
 */
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    queue<int> data;

    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
        // 除了刚插入的元素，其余重置
        for(int i=0; i<data.size()-1; i++){
            data.push(data.front());
            data.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = data.front();
        data.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
};

/*
 双队列:
 插入操作: queue，queue2一定至少一个为空。选择queue1，queue2中不为空的那个队列插入（如果都为空，随意选择一个）
 弹出操作: 将不为空的队列除最后一个队列的其他元素依次取出放到另一个队列中，而将最后那一个元素取出丢弃即可。
 */
class MyStack2 {
public:
    /** Initialize your data structure here. */
    MyStack2() {

    }

    queue<int> q1;
    queue<int> q2;

    /** Push element x onto stack. */
    void push(int x) {
        if(!q1.empty()){
            q1.push(x);
        }else {
            q2.push(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x=-1;
        if(!q1.empty()){
            int size=(int)q1.size();
            for(int i=0; i<size-1; i++){
                q2.push(q1.front());
                q1.pop();
            }
            x = q1.front();
            q1.pop();
        }else{
            int size=(int)q2.size();
            for(int i=0; i<size-1; i++){
                q1.push(q2.front());
                q2.pop();
            }
            x = q2.front();
            q2.pop();
        }
        return x;
    }

    /** Get the top element. */
    int top() {
        int x=-1;
        if(!q1.empty()){
            while(!q1.empty()){
                q2.push(q1.front());
                x = q1.front();
                q1.pop();
            }
        }else{
            while(!q2.empty()){
                q1.push(q2.front());
                x = q2.front();
                q2.pop();
            }
        }
        return x;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */