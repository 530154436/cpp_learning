//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题32 - II. 从上到下打印二叉树 II
    从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

例如:
    给定二叉树: [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
返回其层次遍历结果：
    [
      [3],
      [9,20],
      [15,7]
    ]
 
提示：
    节点总数 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路: 使用队列来进行层次遍历。
 */
vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;

    queue<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        vector<int> levels;
        int size = nodes.size();
        for(int i=0; i<size; i++){ //当前层节点都在队列中，依次取出
            TreeNode* node = nodes.front(); nodes.pop();
            levels.push_back(node->val);

            if(node->left) nodes.push(node->left);
            if(node->right) nodes.push(node->right);
        }
        res.push_back(levels);
    }
    return res;
}