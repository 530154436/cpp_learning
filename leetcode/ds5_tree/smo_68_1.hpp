//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题68 - I. 二叉搜索树的最近公共祖先
    给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
    百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
                                满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
示例 1:
    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    输出: 6
    解释: 节点 2 和节点 8 的最近公共祖先是 6。

 示例 2:
    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    输出: 2
    解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 
说明:
    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉搜索树中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路:
    基于搜索二叉树的左小右大的特性，可以分为以下几种情况:
        情况1：两个目标节点的值都小于根节点：递归左子树查结果
        情况2：两个目标节点的值都大于根节点：递归右子树查结果
        情况3：两个目标节点的值有任一一个等于根节点：返回根节点
        情况4：两个目标节点的值在根节点两侧：返回根节点
        情况5：根节点为空，或者两个目标节点为空（该题没有但是如果面试的还是要问清楚）
    情况3，4可以合并

链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/di-gui-jie-fa-by-yicheng2020-3/
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

TreeNode* findLCA(TreeNode* &root, TreeNode* p, TreeNode* q){
    if(root->val>p->val && root->val>q->val) return findLCA(root->left, p, q);        // 如果当前根值大于两个值，那说明pq都在左子树
    else if(root->val<p->val && root->val<q->val) return findLCA(root->right, p, q);  // 如果当前根值小于两个值，那说明pq都在右子树
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return findLCA(root, p, q);
}
