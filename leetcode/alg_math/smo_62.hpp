//
// Created by 郑楚彬 on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题62. 圆圈中最后剩下的数字 (约瑟夫环)
    0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
    例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

示例 1：
    输入: n = 5, m = 3
    输出: 3

示例 2：
    输入: n = 10, m = 17
    输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    约瑟夫环问题 f(N,M)=(f(N−1,M)+M)%N

    https://www.jianshu.com/p/6ee5c7b21333
    https://blog.csdn.net/u011500062/article/details/72855826
 */
int lastRemaining(int n, int m) {
    int last=0;
    for(int i=2; i<=n; i++){
        last = (last+m) % i;    // 模N: 防止数组越界，超过的部分会被接到头上
    }
    return last;
}

// 环形链表模拟: 超时
int lastRemaining1(int n, int m) {
    vector<int> nums;
    for(int i=0; i<n; i++)
        nums.push_back(i);

    vector<int>::iterator cur=nums.begin();
    while(nums.size()>1){
        for(int i=1; i<m; i++){
            cur++;
            if(cur==nums.end())
                cur = nums.begin();
        }
        // 注意: erase（it）删除迭代器指定位置的元素，并且返回下一个位置的迭代器
        cur = nums.erase(cur);
        if(cur==nums.end())
            cur = nums.begin();
    }
    return *cur;
}