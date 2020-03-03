//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题48. 最长不含重复字符的子字符串
    请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

示例 1:
    输入: "abcabcbb"
    输出: 3
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 
提示：
    s.length <= 40000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 思路1: 双指针+哈希表
    1. 初始化头尾指针分别为begin=0,end=0、unordered_map作为滑动窗口
    2. 遍历字符串，end指向当前字符:
        (1) 将当前字符加入到窗口中
        (2) 判断当前字符在滑动窗口中是否出现: 如果存在，使begin右移，直到该窗口不包含该元素
        (3) 更新最长子串长度
 */
int lengthOfLongestSubstring1(string s) {
    unordered_map<int, int> window;
    int begin=0, len=(int)s.size(), cnt=0;
    for(int end=0; end<len; end++){
        window[s[end]]++;
        // 判断该窗口中是否存在重复元素: 如果存在，使begin右移，直到该窗口不包含该元素
        while(window[s[end]]>1){
            window[s[begin]]--;
            begin++;
        }
        cnt = (end-begin+1>cnt?end-begin+1:cnt);
    }
    return cnt;
}

/*
 思路2: 双指针+哈希表
    1. 初始化头尾指针分别为begin=0,end=0、unordered_map作为滑动窗口
    2. 遍历字符串，end指向当前字符:
        (1) 判断当前字符在滑动窗口中是否出现: 如果存在，使begin右移至重复字符后一位，并防止begin左移
            即 begin = max(window[s[end]]+1, begin);
        (2) 将当前字符加入到窗口中
        (3) 更新最长子串长度
 */
int lengthOfLongestSubstring(string s) {
    unordered_map<int, int> window;
    int begin=0, len=(int)s.size(), cnt=0;
    for(int end=0; end<len; end++){
        // 判断该窗口中是否存在重复元素: 如果存在，则begin右移到重复字符后一位
        if(window.count(s[end]))
            begin = max(window[s[end]]+1, begin); // max: 防止begin左移，eg: "abba"

        window[s[end]]=end;
        cnt = (end-begin+1>cnt?end-begin+1:cnt);
    }
    return cnt;
}