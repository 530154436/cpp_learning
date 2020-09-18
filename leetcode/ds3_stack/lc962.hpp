//
// Created by Edward on 2020/2/19.
//
#include "../lib.hpp"
/**
962. 最大宽度坡
    给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。
    找出 A 中的坡的最大宽度，如果不存在，返回 0 。

示例 1：
    输入：[6,0,8,2,1,5]
    输出：4
    解释：
    最大宽度的坡为 (i, j) = (1, 5): A[1] = 0 且 A[5] = 5.

示例 2：
    输入：[9,8,1,0,1,9,4,0,4,1]
    输出：7
    解释：
    最大宽度的坡为 (i, j) = (2, 9): A[2] = 1 且 A[9] = 1.

提示：
    2 <= A.length <= 50000
    0 <= A[i] <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-width-ramp
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 解题思路：
    找到当前元素左边第一个比它小的元素，果断单调递减栈，从右往前遍历。

 ps 单调栈应用范围
    求解数组中元素右边第一个比它小的元素的下标，从前往后，构造单调递增栈；
    求解数组中元素右边第一个比它大的元素的下标，从前往后，构造单调递减栈；
    求解数组中元素左边第一个比它小的元素的下标，从后往前，构造单调递减栈；
    求解数组中元素左边第一个比它小的元素的下标，从后往前，构造单调递增栈。

 链接：https://leetcode-cn.com/problems/maximum-width-ramp/solution/dan-diao-di-jian-zhan-on-by-huangyt/
 */
int maxWidthRamp(vector<int>& A) {
    if(A.empty()) return 0;

    int size = (int)A.size();

    // 构造单调递减栈
    stack<int> s;
    s.push(0);
    for(int i=1; i<size; i++){
        if(A[i]<=A[s.top()]){
            s.push(i);
        }
    }

    // 从右向左遍历: 求最大坡度
    int max = 0;
    for(int j=size-1; j>=0; j--){
        while(!s.empty() && A[j]>=A[s.top()]){
            max = max>j-s.top()?max:j-s.top();
            s.pop();
        }
    }
    return max;
}