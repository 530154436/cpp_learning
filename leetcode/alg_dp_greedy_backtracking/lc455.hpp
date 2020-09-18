//
// Created by Edward on 2020/2/12.
//
#include "../lib.hpp"

/**
455. 分发饼干
    假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i ，
    都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。
    如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

    注意：
        你可以假设胃口值为正。
        一个小朋友最多只能拥有一块饼干。

    示例 1:
        输入: [1,2,3], [1,1]
        输出: 1
        解释:
            你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
            虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
            所以你应该输出1。
    示例 2:
        输入: [1,2], [1,2,3]
        输出: 2
        解释:
            你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
            你拥有的饼干数量和尺寸都足以让所有孩子满足。
            所以你应该输出2.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/assign-cookies
 */

/*
 解题思路:
    (1) 对s、g排序，采用快速排序.
    (2) 根据贪心算法的原理，分配的最优策略是每次分配只关注未分配饼干的最小胃口的小朋友。
 */

int partition(vector<int> &nums, int l, int r){
    int pivot = nums[l];
    while(l<r){
        while(l<r && nums[r]>=pivot) r--;
        nums[l] = nums[r];

        while(l<r && nums[l]<=pivot) l++;
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    return l;
}

void quickSort(vector<int>& nums, int l, int r){
    if(l>r) return;
    int pivot_pos = partition(nums, l, r);
    quickSort(nums, l, pivot_pos-1);
    quickSort(nums, pivot_pos+1, r);
}

int findContentChildren(vector<int>& g, vector<int>& s) {
    quickSort(g, 0, g.size()-1); // 快排
    quickSort(s, 0, s.size()-1);
    int gi=0, sj=0;
    while(gi<g.size() && sj<s.size()){
        if(g[gi]<=s[sj]) gi++;
        sj++;
    }
    return gi;
}