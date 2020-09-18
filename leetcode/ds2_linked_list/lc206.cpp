//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
206. 反转链表
    定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

示例:
    输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL
限制：
    0 <= 节点个数 <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
双指针

定义两个指针： pre 和 cur ；pre 在前 cur 在后。
每次让 pre 的 next 指向 cur ，实现一次局部反转
局部反转完成之后， pre 和 cur 同时往前移动一个位置
循环上述过程，直至 pre 到达链表尾部

链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/fan-zhuan-lian-biao-yi-dong-de-shuang-zhi-zhen-jia/
 */
ListNode* reverseList1(ListNode* head) {
    ListNode *pre=NULL, *cur=head, *next;
    while(cur){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

/*
虚假链表头(头插法)
*/
ListNode* reverseList2(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    dummy-> next = NULL;

    ListNode *t, *cur=head;
    while(cur){
        t = cur->next;
        cur->next = dummy->next;
        dummy->next = cur;
        cur = t;
    }
    return dummy->next;
}

ListNode* reverseList(ListNode* head) {
    // return reverseList1(head);
    return reverseList2(head);
}