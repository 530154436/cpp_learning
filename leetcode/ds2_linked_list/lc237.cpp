//
// Created by 郑楚彬 on 2020/2/19.
//
#include "LinkList.hpp"
/**
 * 237. 删除链表中的节点
 * 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。

   示例 1：
    输入：head = [4,5,1,9], node = 5
    输出：[4,1,9]
    解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

   来源：力扣（LeetCode）
   链接：https://leetcode-cn.com/problems/delete-node-in-a-linked-list
 */
/*
 * 由于没有办法得到node的前节点，我们只能通过将下一个节点的值复制到当前节点node，然后移除node的下一个节点来达到目的。
 */
void deleteNode(ListNode* node) {
    if(!node) return;
    ListNode* p = node->next;
    if(p){
        int exchange = node->val;   // 交换数据域
        node->val = p->val;
        p->val = exchange;

        node->next = p->next;       // 删除节点
        delete(p);
    }else{
        delete(node);
    }
}
