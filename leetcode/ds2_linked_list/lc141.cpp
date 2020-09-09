//
// Created by 郑楚彬 on 2020/2/12.
//
#include "../lib.hpp"

/**
141. 环形链表
    给定一个链表，判断链表中是否有环。
    为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

    示例 1：
        输入：head = [3,2,0,-4], pos = 1
        输出：true
        解释：链表中有一个环，其尾部连接到第二个节点。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/linked-list-cycle
 */
/*
 解题思路:
    设置快慢两个指针分别为 fast 和 slow，初始时都指向链表头 head。
    ① 即 slow=slow->next; fast每次走两步，即 fast=fast->ηext->next。
    ② 由于 fast 比 slow 走得快，如果有环，fast 一定会先进入环，而 slow 后进入环。
    ③ 当两个指针都进入环后，经过若干次操作后两个指针定能在环上相遇。即可判断一个链表是否有环。
 */

bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode *slow=head;
    ListNode *fast=head;
    while(slow && fast && fast->next){
        slow = slow->next;              // 走一步
        fast = fast->next->next;        // 走两步
        if(slow==fast)
            return true;
    }
    return false;
}