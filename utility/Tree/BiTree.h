//
// Created by 郑楚彬 on 2018/4/12.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/**
 * 二叉链表节点类型定义
 */
typedef struct BiTNode{
    char data;
    BiTNode *lchild;
    BiTNode *rchild;
}BiTNode;

/**
 * 初始化一个二叉树的节点(按序号建)
 *
 * @param root 双亲节点
 * @param elements 字符数组
 * @param n    节点数
 */
void init(BiTNode *&root, char* &elements){
    char c = *elements;
    if(c == '\0' || '#' == c){
        root = NULL;
        elements++;
        return;
    }else{
        root = (BiTNode *) malloc(sizeof(BiTNode *));
        root->data = c;
        cout << *elements << endl;
        elements++;
        init(root->lchild, elements);
        init(root->rchild, elements);
    }
}

/**
 * 先序遍历
 */
void preorder(BiTNode *&bt){
    if(bt == NULL){
        return;
    }
    cout << bt->data << ' ';
    preorder(bt->lchild);
    preorder(bt->rchild);
}

/**
 * 中序遍历
 * @param bt
 */
void inorder(BiTNode *&bt){
    if(bt == NULL){
        return;
    }
    inorder(bt->lchild);
    cout << bt->data << ' ';
    inorder(bt->rchild);
}

/**
 * 后序遍历
 * @param bt
 */
void postorder(BiTNode *&bt){
    if(bt == NULL){
        return;
    }
    inorder(bt->lchild);
    inorder(bt->rchild);
    cout << bt->data << ' ';
}

/**
 * 求一棵二叉树的深度，二叉树以二叉链表为存储方式
 *
 * 思路:
 *      树的深度= max(LD, RD) + 1
 *   即 左子树与右子树深度的最大值+1
 * *@param bt
 */
int getDeepth(BiTNode *bt){
    int LD, RD;
    if(bt == NULL){
        return 0;
    }else{
        LD = getDeepth(bt->lchild);
        RD = getDeepth(bt->rchild);
        return (LD>RD?LD:RD) + 1;
    }
}

/**
 * 查找值域等于key的节点
 *
 * @param bt   二叉树
 * @param q    待求节点
 * @param key  匹配值
 */
void search(BiTNode *bt, BiTNode *&q, char key){
    if(bt == NULL){
        return;
    }
    // 如果值相等，则q指向值域等于key的节点
    if(bt->data == key) {
        q = bt;
    }else{
        // 否则分别到左右子树上查找
        search(bt->lchild, q, key);
        search(bt->rchild, q, key);
    }
}