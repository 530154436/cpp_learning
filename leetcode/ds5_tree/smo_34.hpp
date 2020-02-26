//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题34. 二叉树中和为某一值的路径
    输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

示例:
    给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
    [
       [5,4,11,2],
       [5,8,4,5]
    ]
     
提示：
    节点总数 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路: 前序遍历
    (1) 每次遍历新节点，将节点放入当前保存的路径，并计算路径的节点值和
    (2) 检查节点是否是叶节点，并且路径上的节点值等于输入值：
        是：将路径放入结果中
        不是：继续遍历左子树和右子树
    (3) 回溯
        在函数退出之前要在路径上删除当前节点并减去当前节点的值，以确保返回父节点时路径刚好是从根节点到父节点的。
 */
void cal(TreeNode* root, int sum, int pathSum, vector<int> &path, vector<vector<int>> &res){
    if(!root) return;

    pathSum += root->val;
    path.push_back(root->val);
    // 如果是叶子节点，并且路径上的节点值等于输入值
    if(pathSum==sum && !root->left && !root->right){
        res.push_back(path);
    }
    if(root->left) cal(root->left, sum, pathSum, path, res);    // 遍历左子树
    if(root->right) cal(root->right, sum, pathSum, path, res);  // 遍历右子树
    path.pop_back(); // 回溯
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    cal(root, sum, 0, path, res);
    return res;
}