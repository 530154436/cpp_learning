//
// Created by 郑楚彬 on 2020/2/19.
//
#include "alg_bitwise/smo_64.hpp"
#include "alg_bitwise/smo_56_1.hpp"
#include "alg_bitwise/smo_56_2.hpp"
/*
 面试题64. 求1+2+…+n
 面试题15. 二进制中1的个数
 136. 只出现一次的数字
 面试题56 - I. 数组中数字出现的次数
 面试题56 - II. 数组中数字出现的次数 II  xxx
 */

int main(){
    vector<int> nums, res;
    int result;

    // 面试题64.求1+2+…+n
    cout<<sumNums(100)<<endl;

    // 面试题56 - I. 数组中数字出现的次数
    nums = {1,2,5,2};
    res = singleNumbers_1(nums);
    display(res);

    //  面试题56 - II. 数组中数字出现的次数 II
    nums = {3,4,3,3};
    result = singleNumbers_2(nums);
    cout<<result<<endl;

}
