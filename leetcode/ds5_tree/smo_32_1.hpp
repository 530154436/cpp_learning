//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题32 - I. 从上到下打印二叉树
    从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
    给定二叉树: [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
返回：
    [3,9,20,15,7]
 

提示：
    节点总数 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路: 使用队列来进行层次遍历。
 */
vector<int> levelOrder(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*> nodes;
    vector<int> res;

    nodes.push(root);
    while(!nodes.empty()){
        root = nodes.front(); nodes.pop();
        res.push_back(root->val);
        if(root->left) nodes.push(root->left);
        if(root->right) nodes.push(root->right);
    }
    return res;
}