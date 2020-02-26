//
// Created by 郑楚彬 on 2020/2/23.
//
/*
246. 中心对称数
    中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。

请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。
示例 1:
    输入:  "69"
    输出: true
示例 2:
    输入:  "88"
    输出: true
示例 3:
    输入:  "962"
    输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/strobogrammatic-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
解题思路: 双指针
 */
bool isValid(char a, char b){
    switch(a){
        case '0': return b=='0';
        case '1': return b=='1';
        case '6': return b=='9';
        case '8': return b=='8';
        case '9': return b=='6';
        default: return false;
    }
}

bool isStrobogrammatic(string num) {
    for(int i=0,j=(int)num.size()-1; i<=j; i++,j--){
        if(!isValid(num[i], num[j])){
            return false;
        }
    }
    return true;
}