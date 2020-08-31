//
// Created by 郑楚彬 on 2020/8/18.
//
#include "BiTree.hpp"
#include "../templates/SqQueueTemplate.hpp"
#include "../templates/SqStackTemplate.hpp"

void visit(BiTNode *node){
    std::cout << node->data << ' ';
}

void Create(BiTree &root, char const *&elements){
    ElemType c = *elements; // 读元素
    if(c == '\0')
        return;

    if('#' == c){
        root = NULL;
        elements++;
    }else{
        root = (BiTNode *) malloc(sizeof(BiTNode *));
        root->data = c;

        // std::cout << root->data << std::endl;
        elements++;
        Create(root->lchild, elements);
        Create(root->rchild, elements);
    }
}

void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void PreOrder2(BiTree T){
    SqStack<BiTNode *> s;
    InitStack(s);
    BiTNode *p=T;
    while(p || !StackEmpty(s)){     // 栈不空 或 p不空时循环
        if(p){                      // 一路向左
            visit(p);
            Push(s, p);             // 当前结点入栈
            p = p->lchild;          // 左孩子不为空，一路向左
        }else{                      // 出栈，并转向出栈结点的右子树
            Pop(s, p);              // 栈顶元素出栈
            p = p->rchild;          // 向右子树走， p 赋值为当前结点的右孩子
        }
    }
}

void InOrder2(BiTree T){
    SqStack<BiTNode *> s;
    InitStack(s);
    BiTNode *p=T;
    while(p || !StackEmpty(s)){
        if(p){
            Push(s, p);
            p = p->lchild;
        }else{
            Pop(s, p);
            visit(p);
            p = p->rchild;
        }
    }
}

void PostOrder2(BiTNode *T){
    SqStack<BiTNode *> s; InitStack(s);
    BiTNode *p = T;
    BiTNode *r = NULL;
    while(p || !StackEmpty(s)){
        if(p){                             // 走到最左边
            Push(s, p);
            p = p->lchild;
        }else{                             // 向右
            GetTop(s, p);                  // 读栈顶结点(非出栈〉
            if(p->rchild && p->rchild!=r){ // 若右子树存在，且未被访问过
                p = p->rchild;
                Push(s, p);
                p = p->lchild;
            }
            else{                          // 否则，弹出结点并访问
                visit(p);
                Pop(s, p);
                r = p;                     // 记录最近访问过的结点
                                           // 区分返回是从左子树返回的还是从右子树返回的, 因此设定一个辅助指针 r
                p = NULL;                  // 结点访问完后，重置 p
                                           // 每次出战访问完一个结点就相当于遍历完以该结点为根的子树，需将p置NULL。
            }
        }
    }
}

void LevelOrder(BiTree T){
    SqQueue<BiTNode *> Q;
    InitQueue(Q);
    BiTNode *p;
    EnQueue(Q, T);
    while(!QueueEmpty(Q)){          // 队列不为空则循环
        DeQueue(Q, p);
        visit(p);                   // 访问出队结点
        if(p->lchild)
            EnQueue(Q, p->lchild);  // 左子树不空，则左子树根结点入队
        if(p->rchild)
            EnQueue(Q, p->rchild);  // 右子树不空，则右子树根结点入队
    }
}