//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题06. 从尾到头打印链表
    输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：
    输入：head = [1,3,2]
    输出：[2,3,1]
 
限制：
    0 <= 链表长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
vector<int> reversePrint(ListNode* head) {
    vector<int> res;
    while(head){
        res.push_back(head->val);
        head = head->next;
    }
    for(int i=0,j=res.size()-1; i<j; i++,j--){ // 数组反转
        swap(res[i], res[j]);
    }
    return res;
}