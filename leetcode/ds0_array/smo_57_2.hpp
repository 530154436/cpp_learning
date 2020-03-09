//
// Created by 郑楚彬 on 2020/2/2.
//
#include "../lib.hpp"

/**
面试题57. 和为s的两个数字
    输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
    序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：
    输入：target = 9
    输出：[[2,3,4],[4,5]]

示例 2：
    输入：target = 15
    输出：[[1,2,3,4,5],[4,5,6],[7,8]]
     
限制：
    1 <= target <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路1：
    双指针
    + 设置两个指针small, big分别代表左边界和右边界，从i累加到j，当前的和为curSum:
    (1) curSum > target: small++
    (2) curSum < target: big++
    (3) curSum == target: 添加到结果集中，并 small++、big++

作者：loick
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/liang-ge-zhi-zhen-yi-qi-hua-by-loick/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

vector<int> toSequence(int small, int big){
    vector<int> sum;
    for(int i=small; i<=big; i++)
        sum.push_back(i);
    return sum;
}

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    if(target<3) return res;

    // 慢指针、快指针
    int small=1,big=2, middle=(target+1)/2;
    int curSum = 0;
    while(small<big && small<=middle){
        curSum = ((small+big)*(big-small+1))/2;     // 等差数列求和
        if(curSum==target){
            res.push_back(toSequence(small, big));
            small++;
            big++;
        }
        else if(curSum<target){
            big++;
        }else{
            small++;
        }
    }
    return res;
}

// 比较麻烦
vector<vector<int>> findContinuousSequence1(int target) {
    vector<vector<int>> res;
    if(target<3) return res;

    int small=1,big=2, middle=(target+1)/2;
    int curSum = small+big;
    while(small<=middle && big<=middle){
        if(curSum==target)
            res.push_back(toSequence(small, big));

        while(curSum>target && small<middle){
            curSum -= small;
            small++;

            if(curSum==target)
                res.push_back(toSequence(small, big));
        }

        big++;
        curSum+=big;
    }

    return res;
}