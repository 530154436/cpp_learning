//
// Created by Edward on 2020/2/19.
//
#include "../lib.hpp"
/**
739. 每日温度
    根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。
    如果之后都不会升高，请在该位置用 0 来代替。
例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
     你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
提示：
     气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures
 */

/*
 解题思路：单调递减栈
    遍历整个数组:
        (1) 如果栈不空，且当前数字大于栈顶元素，取出栈顶元素并求出下标差(距离)。
        (2) 如果当前数字小于等于栈顶元素，则将数字入栈，这样就可以一直保持递减栈，且每个数字和`第1个`大于它的数的距离也可以算出来。

 https://leetcode-cn.com/problems/daily-temperatures/solution/leetcode-tu-jie-739mei-ri-wen-du-by-misterbooo/
 */
// 暴力破解
vector<int> dailyTemperatures1(vector<int>& T) {
    vector<int> days;
    stack<int> temp;

    for(int i=0; i<(int)T.size(); i++){
        bool flag = false;
        for(int j=i+1; j<(int)T.size(); j++){
            if(T[j]>T[i]){
                days.push_back(j-i);
                flag = true;
                break;
            }
        }
        if(!flag) days.push_back(0);
    }
    return days;
}

// 单调递减栈
vector<int> dailyTemperatures(vector<int> T) {
    vector<int> days((int)T.size(), 0);
    stack<int> temp;

    for(int i=0; i<(int)T.size(); i++){
        while(!temp.empty() && T[i]>T[temp.top()]){
            int t = temp.top();
            temp.pop();
            days[t] = i-t;
        }
        // 存储索引
        temp.push(i);
    }
    return days;
}