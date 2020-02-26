//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题28. 对称的二叉树
    请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
        1
       / \
      2   2
     / \ / \
    3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
        1
       / \
      2   2
       \   \
       3    3

示例 1：
    输入：root = [1,2,2,3,4,4,3]
    输出：true
示例 2：
    输入：root = [1,2,2,null,3,null,3]
    输出：false
限制：
    0 <= 节点个数 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路:
    递归结束条件：
        (1) 都为空指针则返回 true
        (2) 只有一个为空则返回 false
        (3) 两个指针当前节点值不相等 返回false
    递归过程：
        (1) 判断 A 的右子树与 B 的左子树是否对称
        (2) 判断 A 的左子树与 B 的右子树是否对称
 */
bool isSymmetric(TreeNode* root) {
    return isSame(root, root);
}

bool isSame(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->val != root2->val) return false;
    return isSame(root1->left, root2->right) && isSame(root1->right, root2->left);
}