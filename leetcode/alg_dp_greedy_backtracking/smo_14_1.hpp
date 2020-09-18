//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题14- I. 剪绳子
    给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m] 。
    请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？
    例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：
    输入: 2
    输出: 1
    解释: 2 = 1 + 1, 1 × 1 = 1

示例 2:
    输入: 10
    输出: 36
    解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

提示：
    2 <= n <= 58

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    初始值：
        products[0] = 0;
        products[1] = 1;    // 真实值 0
        products[2] = 2;    // 真实值 1
        products[3] = 3;    // 真实值 2
    递推:
        products[i]表示把长度为i的绳子剪成若干段后各段长度乘积的最大值
        products[n] = max(products[i]*products[i-j])

    解释:
        1. 找规律: products[i]与products[i-1]、products[i-2]...products[1]之间的关系
        2. 将i分成两个部分：j、i-j < i
           把j从1到i/2遍历，得到products[j]*products[i-j]的最大值，合理地利用了以前算出来的最大值。
 */
int cuttingRope(int n) {
    if(n<2) return 0;
    if(n==2) return 1;
    if(n==3) return 2;

    vector<int> products (n+1, 0);

    // 特殊情况: n=2、3，products[x]<x
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    // products[i]表示把长度为i的绳子剪成若干段后各段长度乘积的最大值
    for(int i=4; i<=n; i++){
        int max = 0;
        // 只考虑前i/2个剪切位置即可, 后面的剪切位置是重复的
        for(int j=1; j<=i/2; j++){
            int product = products[j]*products[i-j];
            if(product>max)
                max = product;
        }
        products[i] = max;
    }
    return products[n];
}