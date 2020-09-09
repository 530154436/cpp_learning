//
// Created by 郑楚彬 on 2020/2/12.
//
#include "../lib.hpp"

/**
142. 环形链表 II
    给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
    为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
    说明：不允许修改给定的链表。

    示例 1：
        输入：head = [3,2,0,-4], pos = 1
        输出：tail connects to node index 1
        解释：链表中有一个环，其尾部连接到第二个节点。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
 */
/*
 * 解题思路:
 *  1. 判断链表中是否有环：
 *    设置快慢两个指针分别为 fast 和 slow，初始时都指向链表头 head。
 *    ① 即 slow=slow->next; fast每次走两步，即 fast=fast->ηext->next。
 *    ② 由于 fast 比 slow 走得快，如果有环，fast 一定会先进入环，而 slow 后进入环。
 *    ③ 当两个指针都进入环后，经过若干次操作后两个指针定能在环上相遇。即可判断一个链表是否有环。
 *
 *  2. 设头结点到环的入口点的距离为 a，环的入口点沿着环的方向到相遇点的距离为 x，环长为 r，相遇时 fast 绕过了 n 圈。
 *     则 2(a+x)=a+nr+x
 *        => a=nr-x=(r-x)+(n-1)r，即从头结点到环的入口点的距离等于 n 倍的环长减去环的入口点到相遇点的距离。
 *     因此可设置两个指针，一个指向head，一个指向相遇点，两个指针同步移动(均为一次走一步)，相遇点即为环的入口点。
 */
ListNode *detectCycle(ListNode *head) {
    ListNode *slow=head, *fast=head;
    while(slow && fast && fast->next){  // 找到相遇点
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            break;
    }
    if(!slow || !fast || !fast->next)
        return NULL;

    ListNode *p1=head,*p2=slow;
    while(p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}