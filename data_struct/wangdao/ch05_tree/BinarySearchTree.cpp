//
// Created by Edward on 2018/5/25.
//
#include "BinarySearchTree.hpp"

void visit(BSTNode *node){
    if(node)
        std::cout << node->data << ' ';
    else
        std::cout << "NULL" << ' ';
}

/**
 * 查找关键字 (非递归版本)
 * @param bst
 * @param key
 * @return
 */
BSTNode* BST_Search(BSTree T, int key){
    while(T){
        if(T->data==key){
            return T;
        }else if(key<T->data){
            T = T->lchild;
        }else{
            T = T->rchild;
        }
    }
    return T;
}

/**
 * 查找关键字 (递归版本)
 *
 * https://leetcode-cn.com/problems/search-in-a-binary-search-tree/
 */
BSTNode* BST_SearchR(BSTree T, int key) {
    if(!T) return T;
    if(T->data==key){
        return T;
    }else if(key<T->data){
        return BST_SearchR(T->lchild, key);
    }else{
        return BST_SearchR(T->rchild, key);
    }
}

/**
 * 二叉排序树插入操作
 *
 * 算法思想:
 *     (1) 若原二叉排序树为空，则直接插入结点;
 *     (2) 若关键字 k 小于根结 点值，则插入到左子树，
 *     (3) 若关键字 k大于根结点值，则插入到右子树。
 *
 * https://leetcode-cn.com/problems/insert-into-a-binary-search-tree
 */
bool BST_Insert(BSTree &T, int key){
    if(T==NULL){                                     // 原树为空，新插入的记录为根结点
        T = (BSTNode*) malloc(sizeof(BSTNode));
        T->data = key;
        T->rchild = T->lchild = NULL;
        return true;
    }
    else if(key==T->data){                           // 树中存在相同关键字的结点，插入失败
        return false;
    }
    else if(key<T->data){                            // 插入到 T 的左子树
        return BST_Insert(T->lchild, key);
    }
    else{                                            // 插入到 T 的右子树
        return BST_Insert(T->rchild, key);
    }
}

/**
 * 构造二叉排序树
 */
void BST_Create(BSTree &T, int elems[], int n){
    if(n<=0) return;
    for(int i=0; i<n; i++)
        BST_Insert(T, elems[i]);
}

