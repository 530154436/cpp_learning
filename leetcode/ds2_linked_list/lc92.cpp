//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
#include "LinkList.hpp"
/**
92. 反转链表 II
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
    1 ≤ m ≤ n ≤ 链表长度。

示例:
    输入: 1->2->3->4->5->NULL, m = 2, n = 4
    输出: 1->4->3->2->5->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
 */

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

/*
双指针、虚假链表头
以第m-1节点为"头节点"，将[m,n]范围的节点不断插入"头节点"，最后，第m个节点指向第n+1个节点
 */
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(!head || m==n) return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    // 第m-1个节点
    ListNode *pre=dummy;
    for(int i=1; i<m; i++){
        pre = pre->next;
    }

    // 第m个节点
    ListNode *t, *cur=pre->next, *mNode=pre->next;
    // 头插法
    for(int i=m; i<=n; i++){
        t = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = t;
    }
    // 第m个节点指向第n+1个节点
    mNode->next = cur;

    return dummy->next;
}