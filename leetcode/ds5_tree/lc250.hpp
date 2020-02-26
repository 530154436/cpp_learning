//
// Created by 郑楚彬 on 2020/2/19.
//
#include "../lib.hpp"
/**
250. 统计同值子树
 给定一个二叉树，统计该二叉树数值相同的子树个数。同值子树是指该子树的所有节点都拥有相同的数值。

示例：
    输入: root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-univalue-subtrees
 */

/*
 解题思路：
    给定树中的一个结点，若其满足下面条件中的一个，则子树同值:
        (1) 该节点没有子结点 （基本情况）
        (2) 该节点的所有子结点都为同值子树，且结点与其子结点值相同。
 */
bool isUnival(TreeNode* node, int &cnt){
    if(!node) return false;
    if(!node->left && !node->right) {
        cnt++;
        return true;
    }
    bool flag=true;
    if(node->left){
        flag &= isUnival(node->left, cnt);  // 查看左子树是否是同值树
        flag &= node->left->val==node->val; // 常看当前节点是否等于左节点
    }
    if(node->right){
        flag &= isUnival(node->right, cnt);  // 查看右子树是否是同值树
        flag &= node->right->val==node->val; // 常看当前节点是否等于右节点
    }
    if(flag) cnt++; // 当前树是同值树，结果加1
    return flag;
}

int countUnivalSubtrees(TreeNode* root) {
    if(!root) return 0;
    int cnt=0;
    isUnival(root, cnt);
    return cnt;
}