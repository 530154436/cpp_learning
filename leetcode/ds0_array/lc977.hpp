//
// Created by 郑楚彬 on 2020/2/14.
//
#include "../lib.hpp"

/**
977. 有序数组的平方
  给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

示例 1：
    输入：[-4,-1,0,3,10]
    输出：[0,1,9,16,100]

示例 2：
    输入：[-7,-3,2,3,11]
    输出：[4,9,9,49,121]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
 */

/*
 解题思路:
    1. 平方最大的只会出现再数组两侧，并且越往中间平方数会越小。
    2. 用两个指针分别位于数组两侧，比较大小逐渐往中间移动，得到一个平方值由大到小的数组。
    3. 最后再逆转数组
 */
void reverse(std::vector<int> &s){
    // 反转数组
    int l=0, r=(int)s.size()-1;
    while(l<r){
        swap(s[l], s[r]);
        l++; r--;
    }
}

vector<int> sortedSquares(vector<int>& A) {
    vector<int> res;
    int l=0, r=(int)A.size()-1;
    int sum_l, sum_r;
    while(l<=r){
        sum_l = A[l]*A[l];
        sum_r = A[r]*A[r];
        if(sum_l>sum_r){
            res.push_back(sum_l);
            l++;
        }else{
            res.push_back(sum_r);
            r--;
        }
    }

    // 反转数组
    reverse(res);

    return res;
}