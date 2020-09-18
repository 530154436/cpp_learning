//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题68 - II. 二叉树的最近公共祖先
    给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
    百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
                                满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

示例 1:
    输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    输出: 3
    解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

示例 2:
    输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    输出: 5
    解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 
说明:
    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉树中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路:
    (1) 从根节点开始遍历树。
    (2) 如果当前节点本身是 p 或 q 中的一个，我们会将变量 isRoot 标记为 true，并继续搜索左右分支中的另一个节点。
    (3) 如果左分支或右分支中的任何一个返回 true，则表示在下面找到了两个节点中的一个。
    (4) 如果在遍历的任何点上，左、右或中三个标志中的任意两个变为 true，这意味着我们找到了节点 p 和 q 的最近公共祖先为当前节点。

作者：LeetCode
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetcod/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
bool findOne(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&res){
    if(!root) return false;

    bool isLeft = findOne(root->left, p, q, res);
    bool isRight = findOne(root->right, p, q, res);
    bool isRoot = root->val==p->val || root->val==q->val;

    if((isLeft&&isRight) || (isRoot&&isLeft) || (isRoot&&isRight)) // 找到了两个节点
        res = root;
    return isLeft || isRight || isRoot; // 表示找到一个节点
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *res;
    findOne(root, p, q, res);
    return res;
}