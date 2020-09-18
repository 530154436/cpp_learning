//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题65. 不用加减乘除做加法
    写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

示例:
    输入: a = 1, b = 1
    输出: 2
 
提示：
    a, b 均可能是负数或 0
    结果不会溢出 32 位整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    循环条件: 进位不为0，即不再产生进位:
    循环体:
        1. 先做异或运算，即无进位加法
        2. 求进位，与运算并左移一位

    知识点：
        交换两个变量: a = a^b;
                    b = a^b;
                    a = a^b;

作者：jerry_nju
链接：https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/wei-yun-suan-zhu-xing-jie-shi-by-jerry_nju/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
int add(int a, int b) {
    int sum=0;
    while(b){                        // 循环条件: 进位不为0，即不再产生进位
        sum = a^b;                   // 求和（不计进位）. 相同位置0，相反位置1
        b = ((unsigned int)a&b)<<1;  // 计算进位. bit=1左移1位
        a = sum;
    }
    return a;
}