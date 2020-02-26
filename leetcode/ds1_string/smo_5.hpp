//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题05. 替换空格
    请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：
    输入：s = "We are happy."
    输出："We%20are%20happy." 

限制：
    0 <= s 的长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

string replaceSpace(string s) {
    string res = "";
    for(int i=0; i<(int)s.size(); i++){
        if(s[i]==' ')
            res += "%20";
        else
            res += s[i];
    }
    return res;
}