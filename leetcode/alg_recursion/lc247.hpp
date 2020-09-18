//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
247. 中心对称数 II
    中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
    找到所有长度为 n 的中心对称数。
示例 :
    输入:  n = 2
    输出: ["11","69","88","96"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/strobogrammatic-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
解题思路:
    当 n=0 的时候，应该输出空字符串：“ ”。
    当 n=1 的时候，也就是长度为 1 的中心对称数有：0，1，8。
    当 n=2 的时候，长度为 2 的中心对称数有：11， 69，88，96。注意：00 并不是一个合法的结果。
    当 n=3 的时候，只需要在长度为 1 的合法中心对称数的基础上，不断地在两边添加 11，69，88，96 就可以了。
    随着 n 不断地增长，我们只需要在长度为 n-2 的中心对称数两边添加 11，69，88，96 即可。
 */

vector<string> conStrobogrammatic(int n, bool root) {
    if(n<=0) {return {""};}
    if(n==1) {return {"0", "1", "8"};}

    vector<string> res = conStrobogrammatic(n-2, false);
    vector<string> new_res = {};

    for(int i=0; i<(int)res.size(); i++){
        if(!root) new_res.push_back("0"+res[i]+"0");

        new_res.push_back("1"+res[i]+"1");
        new_res.push_back("6"+res[i]+"9");
        new_res.push_back("8"+res[i]+"8");
        new_res.push_back("9"+res[i]+"6");
    }
    return new_res;
}

vector<string> findStrobogrammatic(int n) {
    return conStrobogrammatic(n, true);
}
