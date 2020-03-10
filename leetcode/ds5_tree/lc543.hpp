//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
543. 二叉树的直径
    给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
    给定二叉树

              1
             / \
            2   3
           / \
          4   5
    返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/*
解题思路: dfs
    1. 我们定义一个递归函数 depth(node) 计算 d_{node}，函数返回该节点为根的子树的深度。
    2. 先递归调用左儿子和右儿子求得它们为根的子树的深度 L 和 R ，则该节点为根的子树的深度即为 max(L,R)+1。
    3. 该节点的 d_{node}值为 L+R
    4. 递归搜索每个节点并设一个全局变量 maxDepth 记录 d_{node}的最大值，最后返回 maxDepth 即为树的直径。

    链接：https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/er-cha-shu-de-zhi-jing-by-leetcode-solution/
 */
int depth(TreeNode* root, int &maxDepth){
    if(!root) return 0;

    int lDepth = depth(root->left, maxDepth);   // 左子树深度
    int rDepth = depth(root->right, maxDepth);  // 右子树深度
    if(lDepth+rDepth > maxDepth)
        maxDepth = lDepth + rDepth;             // 二叉树直径即为 max(左子树深度+右子树深度)

    return (lDepth>rDepth?lDepth:rDepth) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxDepth=0;
    depth(root, maxDepth);
    return maxDepth;
}