//
// Created by Edward on 2020/2/19.
//
#include "../lib.hpp"
/**
230. 二叉搜索树中第K小的元素
    给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
    你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:
    输入: root = [3,1,4,null,2], k = 1
           3
          / \
         1   4
          \
           2
    输出: 1
示例 2:
    输入: root = [5,3,6,2,4,null,null,1], k = 3
           5
          / \
         3   6
        / \
       2   4
      /
     1
    输出: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 解题思路：
    中序遍历输出的是一个升序数组。只需要把中序遍历的第 k 个元素返回即可。
 */
void countElem(TreeNode* root, int &res, int &cnt, int k){
    if(!root || cnt==k) return ;
    countElem(root->left, res, cnt, k);
    if(++cnt==k)
        res = root->val;
    countElem(root->right, res, cnt, k);
}

int kthSmallest(TreeNode* root, int k) {
    int cnt=0, res;
    countElem(root, res, cnt, k);
    return res;
}