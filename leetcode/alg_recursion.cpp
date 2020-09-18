//
// Created by Edward on 2020/2/19.
//
#include "alg_recursion/lc247.hpp"
#include "alg_recursion/msjd_08_06.hpp"
#include "alg_recursion/smo10_1.hpp"
#include "alg_recursion/smo10_2.hpp"
#include "alg_recursion/smo_16.hpp"
/*
 247. 中心对称数 II
 面试题 08.06. 汉诺塔问题
 面试题10- I. 斐波那契数列
 面试题10- II. 青蛙跳台阶问题
 面试题16. 数值的整数次方 Pow(x, n)
 */

int main(){
    // 247. 中心对称数 II
    vector<string> s = findStrobogrammatic(2);
    display(s);

    // 面试题 08.06. 汉诺塔问题
    vector<int> A = {2, 1, 0}, B = {}, C = {};
    display(A);
    hanota(A, B, C);
    display(C);

    // 面试题10- I. 斐波那契数列
    cout<<fib(5)<<endl;

    // 面试题10- II. 青蛙跳台阶问题
    cout<<numWays(7)<<endl;

    // 面试题16. 数值的整数次方
    cout<<myPow(2.00000, -2)<<endl;
}
