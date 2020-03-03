//
// Created by 郑楚彬 on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题56 - I. 数组中数字出现的次数
    一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
    输入：nums = [4,1,4,6]
    输出：[1,6] 或 [6,1]

示例 2：
    输入：nums = [1,2,10,4,1,4,3,3]
    输出：[2,10] 或 [10,2]

限制：
    2 <= nums <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    1. 进行一次全员异或操作, 最终结果为: ab = a⨁b
    2. 将这两个不同的数字分成两组 A 和 B，满足：
        (1) 两个独特的的数字分成不同组
        (2) 相同的数字分成相同组
        + 分组方法:
            (1) 在 ab 中找到第一位是1的位的位置 n
            (2) 原数组中的每个数字根据第 n 位是否为 1 进行分组
    3. 每一组的数据进行异或即可得到那a、b

作者：fe-lucifer
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/zhi-chu-xian-yi-ci-de-shu-xi-lie-wei-yun-suan-by-a/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
/**
 * 找到第一位是1的位数 n
 */
int findFirstBitIsOne(int num){
    int idx=0;
    // 判断末位是否为0
    while((num&1)==0) {
        num >>= 1; idx++;
    }
    return idx;
}

/**
 * 判断第n位是否为1
 */
bool isBitOne(int num, int idx){
    // 右移${idx}位
    num >>= idx;
    return (num&1);
}

vector<int> singleNumbers_1(vector<int> &nums) {
    vector<int> res;

    int ab=0, a=0, b=0;
    for(int num:nums)
        ab ^= num; // 最终结果= a XOR b

    // 找到第一位是1的位的位置 n
    int n = findFirstBitIsOne(ab);
    for(int num:nums){

        if(isBitOne(num, n))
            a ^= num; // 第n位是1
        else
            b ^= num; // 第n位是0
    }
    res.push_back(a);
    res.push_back(b);
    return res;
}