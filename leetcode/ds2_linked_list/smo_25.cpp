//
// Created by 郑楚彬 on 2020/2/15.
//
#include "LinkList.hpp"
#include "../lib.hpp"
/**
面试题25. 合并两个排序的链表
    输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4

限制：
    0 <= 链表长度 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路: 双指针+哑节点
    1. 定义头结点
    2. 若 l1 指向的结点值 < l2 指向的结点值，则将 l1 链接到头结点的 next 位置
       否则将 l2 链接到头结点的 next 位置
       循环进行，直至 l1 或 l2 为 NULL
    4. 最后，将 l1 或 l2 中剩下的部分，链接到头结点后面
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode* p=dummy;
    while(l1 && l2){
        if(l1->val<l2->val){
            p->next = l1;
            l1 = l1->next;
        }else{
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if(l1) p->next = l1;
    if(l2) p->next = l2;
    return dummy->next;
}