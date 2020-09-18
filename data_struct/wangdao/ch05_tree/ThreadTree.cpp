//
// Created by Edward on 2018/4/22.
//
#include "ThreadTree.h"

void visit(ThreadNode *node){
    std::cout << node->data << ' ';
}

/**
 * 构造一个二叉树(按前序遍历、未索引化、'#'表示空)
 * @param root
 * @param elements
 */
void Create(ThreadNode *&root, char* &elements){
    char c = *elements;
    if(c == '\0')
        return;

    if('#' == c){
        root = NULL;
        elements++;
        return;
    }else{
        root = (ThreadNode *) malloc(sizeof(ThreadNode *));
        root->data = c;
        root->rtag = 0; // 索引标记
        root->ltag = 0;

        cout << *elements << endl;
        elements++;
        Create(root->lchild, elements);
        Create(root->rchild, elements);
    }
}

/**
 * 建立中序线索二叉树
 * @param root
 */
void InThread(ThreadNode *&p, ThreadNode *&pre){
    if(p){
        InThread(p->lchild, pre);                   // 递归，左子树线索化
        if(p->lchild==NULL){                        // 左子树为空, 建立当前节点的前驱线索
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre!=NULL && pre->rchild==NULL){         // pre右子树为空, 建立前驱节点的后继线索
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;                                    // 标记当前结点成为刚刚访问过的结点
        InThread(p->rchild, pre);                   // 递归，线索化右子树
    }
}

void CreateInThread(ThreadNode *T){
    if(T){
        ThreadNode* pre = NULL;
        InThread(T, pre);           // 线索化二叉树
        pre->rchild = NULL;         // 处理遍历的最后一个结点
        pre->rtag = 1;
    }
}

/**
 * 求中序线索二叉树中中序序列下的第一个结点
 * @param p
 * @return
 */
ThreadNode *FirstNode (ThreadNode *T){
    while(T && T->ltag==0)
        T = T->lchild;      // 最左下结点(不一定是叶结点)
    return T;
}

/**
 * 求中序线索二叉树中结点 p 在中序序列下的后继
 * @param p
 * @return
 */
ThreadNode *NextNode (ThreadNode *p){
    if(p && p->rtag==0)                 // 存在右孩子
        return FirstNode(p->rchild);    // 返回右孩子的第一个绩点
    return p->rchild;                   // rtag==1 直接返回后继线索
}

/**
 * 中序线索二叉树的中序遍历的算法
 * @param T
 */
void InOrder (ThreadNode *T){
    for(ThreadNode*p=FirstNode(T); p!=NULL; p=NextNode(p))  // 中序遍历
        visit(p);
}