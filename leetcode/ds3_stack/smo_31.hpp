//
// Created by 郑楚彬 on 2020/2/19.
//
#include "../lib.hpp"
/**
面试题31. 栈的压入、弹出序列
    输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
    假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
    但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

示例 1：
    输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    输出：true
解释：我们可以按以下顺序执行：
    push(1), push(2), push(3), push(4), pop() -> 4,
    push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

示例 2：
    输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
    输出：false
解释：1 不能在 2 之前弹出。
 

提示：
    0 <= pushed.length == popped.length <= 1000
    0 <= pushed[i], popped[i] < 1000
    pushed 是 popped 的排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 解题思路：
    建立一个辅助栈，把输入的第一个序列中的数字依次压入辅助栈，并按照第二序列的顺序依次从该栈中弹出数字。
    1. 初始化栈 stack，j = 0；
    2. 遍历 pushed 中的元素 x；
       (1) x 入栈
       (2) 若辅助栈不为空 且 栈顶元素==popped[idx]，则依次弹出栈顶元素，并j++
    3. 若辅助栈为空，返回 true，否则返回 false。
 */
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    if(pushed.size()!=popped.size())
        return false;

    stack<int> s;
    int idx=0;
    for(int num:pushed){
        s.push(num);
        while(!s.empty() && s.top()==popped[idx]) {
            s.pop();  idx++;
        }
    }
    return s.empty(); // 辅助栈为空则是
}