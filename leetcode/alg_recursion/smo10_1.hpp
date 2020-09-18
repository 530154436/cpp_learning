//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题10- I. 斐波那契数列
    写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：
        F(0) = 0,   F(1) = 1
        F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
    斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
    答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 
示例 1：
    输入：n = 2
    输出：1
示例 2：
    输入：n = 5
    输出：5
提示：
    0 <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
解题思路:

 (1)动态规划解析：
    状态定义： 设 dp 为一维数组，其中 dp[i] 的值代表 斐波那契数列第 $i$ 个数字 。
    转移方程： dp[i+1]=dp[i]+dp[i−1] ，即对应数列定义 f(n+1)=f(n)+f(n−1) ；
    初始状态： dp[0]=0, dp[1]=1 ，即初始化前两个数字；
    返回值： dp[n] ，即斐波那契数列的第 n 个数字。

    链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/mian-shi-ti-10-i-fei-bo-na-qi-shu-lie-dong-tai-gui/
 */
int fib(int n) {
    // 第1个+1是要存储0至n共n+1个数据；第2个+1是考虑n==0的情况，保证v[1]不越界）
    vector<int> dp(n+1+1, 0);
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] =  (dp[i-1] + dp[i-2]) % 1000000007;
    }
    return dp[n];
}

// 递归版本
// int fib(int n) {
//    if(n == 0) return 0;
//    if(n == 1) return 1;
//    return fib(n - 1) + fib(n - 2);
// }