//
// Created by Edward on 2020/2/15.
//
#include "LinkList.hpp"
/**
83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
    输入: 1->1->2
    输出: 1->2
示例 2:
    输入: 1->1->2->3->3
    输出: 1->2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
 */
/*
 * 算法思想: 由于是有序表，所有相同值域的结点都是相邻的。用 p 扫描递增单链表 L，
 *          若 *p 结点的值域等于 *p 后继结点的值域，则删除后者，否则 p 移向下一个结点。
 */
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *pre=head;
    if(!pre)
        return NULL;
    ListNode *p=pre->next, *q;
    while(p){
        q = p->next;
        if(pre->val==p->val){
            pre->next = q;      // 释放*p结点
            delete(p);
        }else{
            pre = p;
        }
        p = q;
    }
    return head;
}