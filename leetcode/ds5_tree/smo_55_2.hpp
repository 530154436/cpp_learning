//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题55 - II. 平衡二叉树
    输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

示例 1:
    给定二叉树 [3,9,20,null,null,15,7]
        3
       / \
      9  20
        /  \
       15   7
    返回 true 。

示例 2:
    给定二叉树 [1,2,2,3,3,null,null,4,4]

           1
          / \
         2   2
        / \
       3   3
      / \
     4   4
    返回 false 。

限制：
    1 <= 树的结点个数 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
/*
解题思路: 使用队列来进行层次遍历。
 */
bool checkBalanced(TreeNode* root, int &deepth){
    if(!root) return true;

    int left=0, right=0;
    bool isLeftBal = checkBalanced(root->left, left);       // 判断左子树是否平衡
    bool isRightBal = checkBalanced(root->right, right);    // 判断右子树是否平衡
    deepth = 1+(left>right?left:right);                     // 计算当前节点深度
    return left-right<=1 && left-right>=-1 && isLeftBal && isRightBal;
}

bool isBalanced(TreeNode* root) {
    int deepth = 0;
    return checkBalanced(root, deepth);
}