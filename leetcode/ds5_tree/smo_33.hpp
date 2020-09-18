//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题33. 二叉搜索树的后序遍历序列
    输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
    如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

    参考以下这颗二叉搜索树：

         5
        / \
       2   6
      / \
     1   3

示例 1：
    输入: [1,6,3,2,5]
    输出: false

示例 2：
    输入: [1,3,2,6,5]
    输出: true

提示：
    数组长度 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路:
    + 已知条件： 后序序列最后一个值为root；二叉搜索树左子树的值都比root小，右子树的值都比root大。
    + 步骤：
        (1) 确定根节点root；
        (2) 遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；
        (3) 遍历右子树，若发现有小于root的值，则直接返回false；
        (4) 分别判断左右子树是否仍是二叉搜索树（递归）。
 */
bool isPostorder(vector<int>& postorder, int l, int r){
    if(l>=r) return true;
    // 根节点: postorder[r]
    int i=l;                                // 左子树第1个节点
    while(postorder[i]<postorder[r]) i++;   // 找到左子树与右子树的分界点(右子树的第1个节点)

    for(int j=i; j<r; j++){                 // 右子树节点必须都小于根节点,
        if(postorder[j]<postorder[r]){
            return false;
        }
    }

    bool left = isPostorder(postorder, l, i-1);  // 判断左子树是否满足BST的定义
    bool rigth = isPostorder(postorder, i, r-1); // 判断右子树是否满足BST的定义
    return left && rigth;
}

bool verifyPostorder(vector<int>& postorder) {
    return isPostorder(postorder, 0, (int)postorder.size()-1);
}