//
// Created by 郑楚彬 on 2018/4/22.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/**
 * 线索二叉树结构体定义
 */
typedef struct ThreadNode{
    char data;
    int ltag,rtag;             // 索引标记 0/1
    struct ThreadNode *lchild; // 指向左孩子 ltag==0,指向前驱 ltag==1;
    struct ThreadNode *rchild; // 指向右孩子 rtag==0,指向后继 rtag==1;
} ThreadNode, *ThreadTree;

/**
 * 构造一个二叉树(按前序遍历，'#'表示空)、中序线索二叉树
 */
void Create(ThreadNode *&T, char* &elements);      // 建立二叉树(未索引化)
void CreateInThread(ThreadNode *T);                // 建立中序线索二叉树

/**
 * 中序线索二叉树的遍历
 */
void visit(ThreadNode *node);                      // 访问节点
ThreadNode *FirstNode (ThreadNode *T);             // 求中序线索二叉树中中序序列下的第一个结点
ThreadNode *NextNode (ThreadNode *p);              // 求中序线索二叉树中结点 p 在中序序列下的后继
void InOrder (ThreadNode *T);                      // 中序线索二叉树的中序遍历的算法