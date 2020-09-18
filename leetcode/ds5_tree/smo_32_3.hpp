//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题32 - III. 从上到下打印二叉树 III
    请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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
      [20,9],
      [15,7]
    ]
 
提示：
    节点总数 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路: 使用队列来进行层次遍历。
 */
vector<vector<int>> levelOrder3(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;

    queue<TreeNode*> nodes;
    nodes.push(root);
    bool isOdd = false; // 控制奇偶层
    while(!nodes.empty()){
        int size = (int)nodes.size();
        vector<int> level (size, 0);

        for(int i=0; i<size; i++){
            TreeNode* node = nodes.front(); nodes.pop();
            if(isOdd)
                level[size-1-i] = node->val; // 奇数层
            else
                level[i] = node->val;        // 偶数层

            if(node->left) nodes.push(node->left);
            if(node->right) nodes.push(node->right);
        }
        res.push_back(level);
        isOdd = !isOdd;
    }
    return res;
}