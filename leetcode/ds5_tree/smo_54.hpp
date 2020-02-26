//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题54. 二叉搜索树的第k大节点
    给定一棵二叉搜索树，请找出其中第k大的节点。

示例 1:
    输入: root = [3,1,4,null,2], k = 1
       3
      / \
     1   4
      \
       2
    输出: 4

示例 2:
    输入: root = [5,3,6,2,4,null,null,1], k = 3
           5
          / \
         3   6
        / \
       2   4
      /
     1
    输出: 4
 
限制：
   1 ≤ k ≤ 二叉搜索树元素个数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/*
解题思路: 逆中序遍历
    逆中序遍历的顺序为右中左，即得到的是一个递减序列
    使用逆中序遍历在返回数组中的第 K 个即可得到结果
 */

void calKthLargest(TreeNode* root, int k, int &cnt, int &val){
    if(!root || cnt==k) return;

    calKthLargest(root->right, k, cnt, val);
    if(++cnt==k)
        val = root->val;
    calKthLargest(root->left, k, cnt, val);
}
int kthLargest(TreeNode* root, int k) {
    int cnt=0, val=0;
    calKthLargest(root, k, cnt, val);
    return val;
}