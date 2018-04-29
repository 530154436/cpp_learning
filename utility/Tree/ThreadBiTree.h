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
typedef struct ThrBiTNode{
    char data;
    int ltag,rtag;   // 索引标记
    struct ThrBiTNode *lchild;
    struct ThrBiTNode *rchild;
} ThrBiTNode;

/**
 * 初始化一个二叉树的节点(按序号建)
 *
 * @param root 双亲节点
 * @param elements 字符数组
 * @param n    节点数
 */
void init(ThrBiTNode *&root, char* &elements){
    char c = *elements;
    if(c == '\0'){
        return;
    }

    if('#' == c){
        root = NULL;
        elements++;
        return;
    }else{
        root = (ThrBiTNode *) malloc(sizeof(ThrBiTNode *));
        root->data = c;
        root->rtag = 0;
        root->ltag = 0;

        cout << *elements << endl;
        elements++;
        init(root->lchild, elements);
        init(root->rchild, elements);
    }
}

/**
 * 二叉树中序线索化
 *
 * @param p     当前节点
 * @param pre   p 的前驱节点
 */
void inThread(ThrBiTNode *p, ThrBiTNode *pre){
    if( p!= NULL){
        // 递归，左子树线索化
        inThread(p->lchild, pre);

        // 建立当前节点的前驱线索
        if(p->lchild == NULL){
            p->ltag = 1;
            p->lchild = pre;
        }else{
            p->ltag = 0;
        }

        // 建立前驱节点的后继线索
        if(pre!=NULL && pre->rchild==NULL){
            pre->rtag = 1;
            pre->rchild = p;
        }else{
            pre->rtag = 0;
        }

        // 右子树线索化
        pre = p;
        inThread(p->rchild, pre);
    }
}

void createInThread(ThrBiTNode *root){
    ThrBiTNode *pre = NULL;
    if(root != NULL){
        inThread(root, pre);

        // 处理最后一个节点
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

/**
 * 中序线索二叉树中的第一个节点
 *
 * @param root
 * @return
 */
ThrBiTNode* first(ThrBiTNode *root){
    while(root->ltag==0){
        root = root->lchild;
    }
    return root;
}

/**
 * 求节点 p 在中序下的后继节点
 *
 * @param p
 * @return
 */
ThrBiTNode* next(ThrBiTNode *p){
    
}