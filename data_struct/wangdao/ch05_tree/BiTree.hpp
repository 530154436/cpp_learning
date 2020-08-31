//
// Created by 郑楚彬 on 2020/8/18.
//
#ifndef TIANQINDATASTRUCT_BiTree_HPP
#define TIANQINDATASTRUCT_BiTree_HPP

#include <iostream>
#include <cstdlib>
using namespace std;

typedef char ElemType;

/**
 * 二叉树的链式存储结构
 */
typedef struct BiTNode {
    ElemType data;					                         // 数据域
    struct BiTNode *lchild, *rchild;                         // 左、右孩子指针
    // BiTNode(ElemType x) : data(x), lchild(NULL), rchild(NULL) {}
} BiTNode, *BiTree;

/**
 * 构造一个二叉树(按前序遍历，'#'表示空)
 */
void Create(BiTree &root, char const *&elements);

/**
 * 二叉树的遍历
 */
void visit(BiTNode *node);  // 访问节点

void PreOrder(BiTree T);    // 先序遍历
void InOrder(BiTree T);     // 中序遍历
void PostOrder(BiTree T);   // 后序遍历

void PreOrder2(BiTree T);   // 先序遍历(非递归)
void InOrder2(BiTree T);    // 中序遍历(非递归)
void PostOrder2(BiTree T);  // 后序遍历(非递归) 最难!

void LevelOrder(BiTree T);  // 层次遍历

#endif //TIANQINDATASTRUCT_BiTree_HPP