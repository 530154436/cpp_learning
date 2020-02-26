//
// Created by 郑楚彬 on 2020/2/20.
//
#include "ds4_queue/smo59_1.hpp"
#include "ds4_queue/smo59_2.hpp"
/*
 面试题09. 用两个栈实现队列
 面试题59-I. 滑动窗口的最大值
 面试题59-II. 队列的最大值

1、3. 无重复字符的最长子串
2、30. 串联所有单词的子串
3、76. 最小覆盖子串
4、159. 至多包含两个不同字符的最长子串
5、209. 长度最小的子数组
6、239. 滑动窗口最大值
7、340. 至多包含 K 个不同字符的最长子串
8、438. 找到字符串中所有字母异位词
9、567. 字符串的排列
10、632. 最小区间
11、727. 最小窗口子序列
 */

int main(){
    // 面试题59-I. 滑动窗口的最大值
    std::vector<int> nums {1,3,-1,-3,5,3,6,7};
    std::vector<int> res = maxSlidingWindow(nums, 3);
    display(res);

    // 面试题59-II. 队列的最大值
    auto* obj = new MaxQueue();
    obj->push_back(1);
    cout<<obj->max_value()<<endl;
    obj->push_back(2);
    cout<<obj->max_value()<<endl;
}