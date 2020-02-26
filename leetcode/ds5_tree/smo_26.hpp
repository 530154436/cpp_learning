//
// Created by 郑楚彬 on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题26. 树的子结构
    输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。
例如:
    给定的树 A:

         3
        / \
       4   5
      / \
     1   2

    给定的树 B：
       4 
      /
     1

    返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：
    输入：A = [1,2,3], B = [3,1]
    输出：false

示例 2：
    输入：A = [3,4,5,1,2], B = [4,1]
    输出：true

限制：
    0 <= 节点个数 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
解题思路:
 1. 在树A中查找与根节点的值一样的节点 (前序遍历)
    (1) 如果找到了值相同的节点，则判断树A中以R为根节点的子树是不是和树B具有共同的结构 (checkSubStructure)
    (2) 如果没找到值相同的节点，则将A树的左子树的首节点值和B树比较
    (3) 如果左子树中不存在和B树节点值相同的节点，则向其右子树进行查找
    (4) 如果均没有，则result=false,返回result

 2. 判断树A中以R为根节点的子树是否和树B具有相同的结构
    a. B树遍历完了（说明A树子结构和B树子结构相同），return true;
    b. A树遍历完了（此时A树没有遍历完），说明不同，return false;
    c. 判断A树和B树当前节点值相等，并且其左右子树节点值均相等
 */

/**
 * 判断树A中以R为根节点的子树是否和树B具有相同的结构
 */
bool checkSubStructure(TreeNode* A, TreeNode* B){
    if(!B) return true;
    if(!A) return false;

    bool isLeft = checkSubStructure(A->left, B->left);
    bool isRight = checkSubStructure(A->right, B->right);
    return A->val==B->val && isLeft && isRight;
}

/**
 * 在树A中查找与根节点的值一样的节点 (前序遍历)
 */
bool isSubStructure(TreeNode* A, TreeNode* B) {
    bool res = false;
    if(A && B){
        if(A->val==B->val)
            res = checkSubStructure(A, B);
        if(isSubStructure(A->left, B))
            res = true;
        if(isSubStructure(A->right, B))
            res = true;
    }
    return res;
}
