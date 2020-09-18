//
// Created by Edward on 2020/2/12.
//
#include "LinkList.hpp"

/**
160. 相交链表
    编写一个程序，找到两个单链表相交的起始节点。

    示例 1：
        输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
        输出：Reference of the node with value = 8
        输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，
                 链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；
                 在 B 中，相交节点前有 3 个节点。
    注意：
        如果两个链表没有交点，返回 null.
        在返回结果后，两个链表仍须保持原有的结构。
        可假定整个链表结构中没有循环。
        程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 */
/*
 解题思路:
    指针 pA 指向 A 链表，指针 pB 指向 B 链表，依次往后遍历
    如果 pA 到了末尾，则 pA = headB 继续遍历
    如果 pB 到了末尾，则 pB = headA 继续遍历
    比较长的链表指针指向较短链表head时，长度差就消除了.如此，只需要将最短链表遍历两次即可找到位置
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pA=headA, *pB=headB;
    while(pA!=pB){
        pA = pA==NULL?headB:pA->next;  // if(!pA) pA=headB; else pA = pA->next;
        pB = pB==NULL?headA:pB->next;  // if(!pB) pB=headA; else pB = pB->next;
    }
    return pA;
}