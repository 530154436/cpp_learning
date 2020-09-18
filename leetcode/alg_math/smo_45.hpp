//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题45. 把数组排成最小的数
    输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

示例 1:
    输入: [10,2]
    输出: "102"

示例 2:
    输入: [3,30,34,5,9]
    输出: "3033459"
 
提示:
    0 < nums.length <= 100

说明:
    输出结果可能非常大，所以你需要返回一个字符串而不是整数
    拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    1. 把数字转为字符串 (解决大数问题)
    2. 比较大小只需要按照字符串大小的比较规则即可

    + 注意：
        我们只是定义了比较两个数大小的规则，却用它来排序一个含有多个数字的数组，最终拼接数组的所有数字得到的
    是否真的就是最小的数字? (反证法)
 */
string minNumber(vector<int>& nums) {
    // lambda表达式自定义排序规则
    sort(nums.begin(), nums.end(), [](int a, int b){
        string astr = std::to_string(a);
        string bstr = std::to_string(b);
        cout<<astr+bstr<<endl;
        return astr+bstr < bstr+astr;
    });

    // 拼接字符串
    string res;
    for(int str:nums) res+=std::to_string(str);
    return res;
}