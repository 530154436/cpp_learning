//
// Created by Edward on 2020/2/15.
//
#include "LinkList.hpp"
/**
876. 链表的中间结点
    给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。

    示例 1：
        输入：[1,2,3,4,5]
        输出：此列表中的结点 3 (序列化形式：[3,4,5])
             返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
             注意，我们返回了一个 ListNode 类型的对象 ans，这样：
             ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/middle-of-the-linked-list
*/
/*
 * 设置两个指针p和q，指针p每次走一步，指针 q 每次走两步，当指针 q 到达链尾时，指针 p 正好在链表的中间结点
 */
ListNode* middleNode(ListNode* head) {
    if(!head)
        return head;
    ListNode *fast=head,*slow=head;
    while(slow && fast && fast->next){
        slow = slow->next;              // 走一小步
        fast = fast->next->next;        // 走一大步
    }
    return slow;
}