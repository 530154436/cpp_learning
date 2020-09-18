//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题56 - II. 数组中数字出现的次数 II
    在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

示例 1：
    输入：nums = [3,4,3,3]
    输出：4

示例 2：
    输入：nums = [9,1,7,9,7,9,7]
    输出：1
 
限制：
    1 <= nums.length <= 10000
    1 <= nums[i] < 2^31
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    1. 从低位到高位: 所有数字的二进制表示的每一位按位求和
    2. 高位到低位: 如果某一位的和能被3整除，那么该位是0或1

    + 按位求和部分可替换如下:
    ```c++
    unsigned int bitMask = 1;
    for(int j=31; j>=0; j--){
        int bit = bitMask & nums[i]; // 与运算 0010^1011 = 0010
        if(bit!=0)
            bits[j] += 1;
        bitMask <<= 1; // 左移一位
    }
    ```
 */
int singleNumbers_2(vector<int> &nums) {
    vector<int> bits (32, 0);

    for(int i=0; i<nums.size(); i++){

        // 从低位到高位: 所有数字的二进制表示的每一位按位求和
        for(int num:nums){
            for(int j=31; j>=0 && num; j--){    // num为0，循环终止
                bits[j] += (num&1);             // num&1: 末位与运算，结果为0或1
                num >>= 1;                      // 右移1位
            }
        }
    }

    // 高位到低位: 如果某一位的和能被3整除，那么该位是0或1
    int res=0;
    for(int i=0; i<32; i++){
        res <<= 1;  // 最后一位不用左移
        res += (bits[i] % 3);
    }

    return res;
}