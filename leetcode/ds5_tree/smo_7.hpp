//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题07. 重建二叉树
    输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

例如，给出
    前序遍历 preorder = [3,9,20,15,7]
    中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：
        3
       / \
      9  20
        /  \
       15   7
 
限制：
    0 <= 节点个数 <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
解题思路: 递归
    1. 题目分析
        前序遍历特点： 节点按照 [ 根节点 | 左子树 | 右子树 ] 排序，以题目示例为例：[ 3 | 9 | 20 15 7 ]
        中序遍历特点： 节点按照 [ 左子树 | 根节点 | 右子树 ] 排序，以题目示例为例：[ 9 | 3 | 15 20 7 ]


        (2) 在中序遍历中搜索根节点 root 的索引 ，可将中序遍历划分为 [ 左子树 | 根节点 | 右子树 ] 。
        (3) 根据中序遍历中的左（右）子树的节点数量，可将前序遍历划分为 [ 根节点 | 左子树 | 右子树 ] 。

    2. 递归解析
        终止条件： pl>pr || il>ir
        (1) 建立根节点
            前序遍历的首个元素即为根节点 root 的值；
        (2) 在中序遍历中搜索根节点 root 的索引 iroot
        (3) 根据 iroot和中序遍历序列中计算 root 左（右）子树的节点数量 llen、rlen
        (4) 构建根节点root的左子树和右子树:
            左子树: 前序边界: [pl+1, pl+llen], 中序边界: [il, iroot-1]
            右子树: 前序边界: [pr-rlen+1, pr], 中序边界: [iroot+1, ir]
        返回值: root

作者：jyd
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/solution/mian-shi-ti-07-zhong-jian-er-cha-shu-di-gui-fa-qin/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */
TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
    // 递归结束条件
    if(pl>pr || il>ir) return NULL;

    // 根节点
    TreeNode *root = new TreeNode(preorder[pl]);

    // 找到中序遍历中的根节点
    int iroot=il;
    while(iroot<=ir && preorder[pl]!=inorder[iroot]) iroot++;

    // 计算左右子树的长度
    int llen = iroot-il;
    int rlen = ir-iroot;

    // 递归建立左右子树
    root->left = build(preorder, inorder, pl+1, pl+llen, il, iroot-1);
    root->right = build(preorder, inorder, pr-rlen+1, pr, iroot+1, ir);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, inorder, 0, (int)preorder.size()-1,
                 0, (int)inorder.size()-1);
}