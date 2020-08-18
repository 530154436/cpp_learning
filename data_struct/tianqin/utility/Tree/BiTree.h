//
// Created by 郑楚彬 on 2018/4/12.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 100

/**
 * 二叉链表节点类型定义
 */
typedef struct BiTNode{
    char data;
    BiTNode *lchild;
    BiTNode *rchild;
    // 习题5
    BiTNode *parent;
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
    if(c == '\0'){
        return;
    }

    if('#' == c){
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
/*
 * 递归形式
 * @param bt
 */
void preorder(BiTNode *&bt){
    if(bt == NULL){
        return;
    }
    cout << bt->data << ' ';
    preorder(bt->lchild);
    preorder(bt->rchild);
}

/*
 * 非递归形式
 * @param bt
 */
void preorderNonRecursion(BiTNode *&bt){
    if(bt != NULL){
        // 定义栈
        int top = -1;
        BiTNode* stack[Max];

        // 根节点入栈
        stack[++top] = bt;
        BiTNode *q=NULL;

        while(top != -1){
            q = stack[top--];
            cout << q->data << '\t';

            // 先入栈后出，与正常遍历顺序相反
            if(q->rchild != NULL){
                stack[++top] = q->rchild;
            }

            if(q->lchild != NULL){
                stack[++top] = q->lchild;
            }
        }
    }
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

/*
 * 非递归形式
 * @param bt
 */
void inorderNonRecursion(BiTNode *&bt){
    if(bt != NULL){
        BiTNode* stack[Max];
        int top = -1;
        BiTNode* p=bt;

        // 有可能出现栈空但遍历还没有结束的情况
        while(top!=-1 || p!=NULL){

            // 左子树不为空，则入栈
            while(p!=NULL){
                stack[++top] = p;
                p = p->lchild;
            }

            // 栈不为空出栈
            if(top != -1){
                p = stack[top--];
                cout << p->data << '\t';
                p = p->rchild;
            }
        }
    }
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

/*
 * 逆序后序遍历序列 = 先序遍历过程中树的左右子树遍历顺序交换所得的结果
 *
 * @param bt
 */
void postorderNonRecursion(BiTNode *&bt){
    if(bt != NULL){
        BiTNode* stack1[Max];
        int top1 = -1;

        BiTNode* stack2[Max];
        int top2 = -1;

        BiTNode* p=NULL;
        stack1[++top1] = bt;
        while(top1 != -1){
            p = stack1[top1--];
            stack2[++top2] = p;

            // 与先序遍历相反
            if(p->lchild != NULL){
                stack1[++top1] = p->lchild;
            }

            if(p->rchild != NULL){
                stack1[++top1] = p->rchild;
            }
        }

        // 输出最终结果
        while(top2 != -1){
            p = stack2[top2--];
            cout << p->data << '\t';
        }
    }
}

/*
 * 层次遍历
 */
void level(BiTNode *p){
    if(p == NULL){
        return;
    }
    // 循环队列
    BiTNode* queue[Max];
    int front=0, rear=0;
    BiTNode* q;

    // 根节点进队
    rear = (rear+1)%Max;
    queue[rear] = p;

    // 队列不空时循环
    while(front != rear){
        // 出队
        front = (front + 1) % Max;
        q = queue[front];
        cout << q->data << '\t';

        if(p->lchild != NULL){
            rear = (rear+1)%Max;
            queue[rear] = p->lchild;
        }

        if(p->rchild != NULL){
            rear = (rear+1)%Max;
            queue[rear] = p->rchild;
        }
    }
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