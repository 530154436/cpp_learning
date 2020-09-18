//
// Created by Edward on 2018/5/25.
//
#ifndef TIANQINDATASTRUCT_BSTREE_HPP
#define TIANQINDATASTRUCT_BSTREE_HPP

#include <iostream>
#include <cstdlib>
using namespace std;

//typedef char ElemType;

/**
 * 二叉排序树
 */
typedef struct BSTNode{
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

/**
 * 基本操作
 */
void visit(BSTNode *node);
BSTNode* BST_Search(BSTree T, int key);        // 查找关键字 (非递归版本)
BSTNode* BST_SearchR(BSTree T, int key);       // 查找关键字 (递归版本)
bool BST_Insert(BSTree &T, int key);           // 二叉排序树插入操作
void BST_Create(BSTree &T, int *elems, int n); // 构造二叉排序树
// 删除操作(太复杂、忽略)

#endif
