//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题36. 二叉搜索树与双向链表
    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

为了让您更好地理解问题，以下面的二叉搜索树为例：





 我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，
 第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

 



 特别地，我们希望可以就地完成转换操作。
 当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路: 中序遍历(类似线索二叉树)
 */
void inThread(Node* p, Node* &pre, Node* &head){
    if(!p) return;

    inThread(p->left, pre, head);

    if(!head){
        head = p;   // 初始化头结点(最左的子节点)
        pre = p;    // 初始化前驱节点
    }else{
        pre->right = p; // 前驱节点的右指针指向当前节点
        p->left = pre;  // 当前节点的左指针指向前驱节点
        pre = p;        // 前驱节点引用变为当前节点
    }

    inThread(p->right, pre, head);
}

Node* treeToDoublyList(Node* root) {
    if(!root) return NULL;

    Node *pre=NULL, *head=NULL;

    inThread(root, pre, head); // 中序遍历方式遍历二叉树并将其调整成双向链表
    head->left = pre;          // 头节点的左指针指向尾节点
    pre->right = head;         // 尾节点的指针指向头节点
    return head;
}