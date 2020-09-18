//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题27. 二叉树的镜像
    请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：
         4
       /   \
      2     7
     / \   / \
    1   3 6   9

镜像输出：
         4
       /   \
      7     2
     / \   / \
    9   6 3   1

示例 1：
    输入：root = [4,2,7,1,3,6,9]
    输出：[4,7,2,9,6,3,1]
 
限制：
    0 <= 节点个数 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路: 前序遍历
 */
TreeNode* mirrorTree(TreeNode* root) {
    if(!root) return NULL;

    swap(root->left, root->right); // 交换左右子树
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
}