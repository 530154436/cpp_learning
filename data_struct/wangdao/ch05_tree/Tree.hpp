//
// Created by 郑楚彬 on 2020/8/31.
//
#ifndef TIANQINDATASTRUCT_TREE_HPP
#define TIANQINDATASTRUCT_TREE_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

/**
 * 双亲表示法的存储结构
 */
#define MaxSize 100             // 树中最多结点数
typedef char ElemType;

typedef struct PTNode {         // 树的结点定义
    ElemType data;
    int parent;                 // 双亲位置域
} PTNode;

typedef struct PTree {          // 树的类型定义
    PTNode nodes[MaxSize];      // 双亲表示
    int n;                      // 结点数
}PTree;


/**
 * 孩子兄弟表示法 (重点)
 */
#define maxNodes
typedef struct CSNode{
    ElemType data;
    CSNode *firstChild, *nextSibling;   // 第一个孩子和右兄弟指针
}CSNode, *CSTree;


void display(CSNode *node);     // 打印节点的孩子、兄弟

#endif //TIANQINDATASTRUCT_TREE_HPP