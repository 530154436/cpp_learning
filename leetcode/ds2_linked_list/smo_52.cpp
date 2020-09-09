//
// Created by 郑楚彬 on 2020/2/19.
//
#include "LinkList.hpp"
/**
   剑指 Offer 52. 两个链表的第一个公共节点
   请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。

   示例 1：
    输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
    输出：Reference of the node with value = 8
    输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。
            从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
            在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

   来源：力扣（LeetCode）
   链接：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof
 */
/*
 *
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB)
        return NULL;
    ListNode *pA=headA, *pB=headB;
    while(pA!=pB){
        pA = pA?pA->next:headB;
        pB = pB?pB->next:headA;
    }
    return pA;
}
