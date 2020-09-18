//
// Created by Edward on 2018/5/25.
//
#include <iostream>
using namespace std;

/**
 * 二叉排序树
 */
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
} BSTNode;

/**
 * 查找关键字 (递归版本)
 *
 * @param bst
 * @param key
 * @return
 */
BSTNode* bstSearch(BSTNode* bst, int key){
    if(bst==NULL)
        return NULL;
    if(bst->key == key){
        return bst;
    }else if(key < bst->key){
        return bstSearch(bst->lchild, key);
    }else{
        return bstSearch(bst->rchild, key);
    }
}

/**
 * 插入关键字
 *
 * @param bst
 * @param key
 * @return
 */
int bstInsert(BSTNode* &bst, int key){
    if(bst == NULL){
        bst = (BSTNode *) malloc(sizeof(BSTNode));
        bst->lchild = NULL;
        bst->rchild = NULL;
        bst->key = key;
        return 1;
    }else{
        if(bst->key == key){
            return 0;
        }else if(key < bst->key){
            return bstInsert(bst->lchild, key);
        }else{
            return bstInsert(bst->rchild, key);
        }
    }
}

/**
 * 构造二叉排序树
 *
 * @param bst
 * @param keys
 * @param n
 */
void createBST(BSTNode* &bst, int keys[], int n){
    int i;
    for(i=0; i<n; i++){
        bstInsert(bst, keys[i]);
    }
}

/**
 * 删除关键字节点
 *
 * 若被删除节点p的左，右子树均非空，则有两种做法: 1. 是用被删除节点最大的左孩子来代替删除节点，
 *                                          2. 是用被删除节点最小的右孩子来代替删除节点。
 *
 * @param bst
 * @param key
 * @return
 */
int deleteNode(BSTNode* &bst, int key){
    BSTNode *s, *q;

    if(bst->rchild==NULL && bst->lchild==NULL){  // 左右子树均为空
        free(bst);
        bst = NULL;
    }else if(bst->rchild == NULL){ // 右子树为空，连接左子树
        q = bst->lchild;
        bst->key = q->key;
        bst->lchild = q->lchild;
        bst->rchild = q->rchild;
        free(q);
    }else if(bst->lchild == NULL){ // 左子树为空，连接右子树
        q = bst->rchild;
        bst->key = q->key;
        bst->lchild = q->lchild;
        bst->rchild = q->rchild;
        free(q);
    }else{                        // 左右子树均不为空
        // s 的父节点
        q = bst;
        s = bst->lchild;
        while(s->rchild != NULL){
            q = s;
            s = s->rchild;
        } //转左，然后向右到尽头 ==> s 不可能有右子树

        //s指向被删结点的“前驱”
        bst->key = s->key;
        
        if(q!=bst){
            //重接*q的右子树 (以s为根的子树均比q大，所以应连q的右子树)
            q->rchild = s->lchild;
        }else{
            //重接*q的左子树
            q->lchild = s->lchild;
        }
        free(s);
    }
    return 1;
}

/**
 * 二叉查找树上删除一个结点
 *
 * @param bst
 * @param key
 * @return
 */
int deleteBST(BSTNode* &bst, int key){
    //不存在关键字等于key的数据元素
    if(bst == NULL){
        return 0;
    }else{
        //  找到关键字等于key的数据元素
        if(key == bst->key){
            return deleteNode(bst, key);
        }else if(key < bst->key){
            return deleteBST(bst->lchild, key);
        }else{
            return deleteBST(bst->rchild, key);
        }
    }
}

