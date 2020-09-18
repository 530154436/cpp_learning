//
// Created by Edward on 2018/5/29.
//
#include <iostream>
using namespace std;

#define LH 1  // 左高
#define EH 0  // 等高
#define RH -1 // 右高

/**
 * 平衡二叉排序树
 */
typedef struct BBSTNode{
    int key;
    int bf;     // 平衡因子
    BBSTNode *lchild, *rchild;
} BBSTNode, BBSTree;

/**
 * 右单旋转
 * LL平衡旋转: 节点的左孩子(L)的左子树(L)上插入了新节点
 *
 * @param p
 */
void R_Rotate(BBSTNode *&p){
    BBSTNode *lc;
    lc = p->lchild;          // lc 指向 *p 的左子树根节点
    p->lchild = lc->rchild;  // lc 的右子树挂接为 *p 的左子树
    lc->rchild = p;          // *p 挂接为 lc 的右子树
    p = lc;                  // p  指向新的根节点
}

/**
 * 左单旋转
 * RR平衡旋转: 节点的右孩子(R)的左右子树(R)上插入了新节点
 *
 * @param p
 */
void L_Rotate(BBSTNode *&p){
    BBSTNode *rc;
    rc = p->rchild;          // rc 指向 *p 的右孩子
    p->rchild = rc->lchild;  // rc 的左子树挂接为 *p 的右子树
    rc->lchild = p;          // *p 挂接为 rc 的左子树
    p = rc;                  // p  指向新的根节点
}


/**
 * 左平衡旋转
 * LR平衡旋转(先左后右双旋转)
 *
 * @param p
 */
void LeftBalance(BBSTNode *&p){
    BBSTNode *lc;
    BBSTNode *rd;
    lc = p->lchild;
    switch(lc->bf){
        case LH:               // 新插入的节点在左子树
            p->bf = lc->bf = EH;
            R_Rotate(p);
            break;
        case RH:               // 新插入的节点在右子树，需要作双旋处理
            rd = lc->rchild;   // rd指向 *T的左孩子的右子树根

            switch(rd->bf){    // 修改 *T 及其左孩子的平衡因子
                case LH: p->bf = RH; lc->bf = EH; break;
                case EH: p->bf = lc->bf = EH; break;
                case RH: p->bf = EH; lc->bf = LH; break;
            }
            rd->bf = EH;
            L_Rotate(p->lchild);   // 对 T 的左孩子做左旋处理
            R_Rotate(p);           // 对 T 作右旋平衡处理
    }
}


/**
 * 右平衡旋转
 * RL平衡旋转(先右后左双旋转)
 *
 * @param p
 */
void rightBalance(BBSTNode *&p){
    BBSTNode *rc;
    BBSTNode *ld;
    rc = p->rchild;
    switch(rc->bf){
        case RH:               // 新插入的节点在右子树
            p->bf = rc->bf = EH;
            L_Rotate(p);
            break;
        case LH:               // 新插入的节点在左子树，需要作双旋处理
            ld = rc->lchild;   // rd指向 *T的右孩子的左子树根

            switch(ld->bf){    // 修改 *T 及其右孩子的平衡因子
                case LH: p->bf = EH; rc->bf = RH; break;
                case EH: p->bf = rc->bf = EH; break;
                case RH: p->bf = LH; rc->bf = EH; break;
            }
            ld->bf = EH;
            R_Rotate(p->rchild);   // 对 T 的右孩子做左旋处理
            L_Rotate(p);           // 对 T 作左旋平衡处理
    }
}

/**
 * 插入节点
 *
 * @param T
 * @param key
 * @param taller 反映二叉树长高与否
 * @return
 */
int insertAVL(BBSTree *&T, int key, bool &taller){
    if(T == NULL){
        T = (BBSTNode *)malloc(sizeof(BBSTNode));
        T->lchild = T->rchild = NULL;
        T->key = key;
    }else{
        if(key == T->key){
            taller = false;
            return 0;
        }else if(key < T->key){
            if(!insertAVL(T->lchild, key, taller)){
                return 0;   // 未插入
            }
            if(taller){
                switch(T->bf){
                    case LH:  // 原本左子树比右子树高，需要做平衡处理
                        LeftBalance(T); taller = false;
                        break;
                    case EH:  // 原本左子树、右子树等高，现因左子树增高而使树增高
                        T->bf = LH; taller = true;
                        break;
                    case RH:  // 原本右子树比左子树高，现等高
                        T->bf = EH; taller = false;
                        break;
                }
            }
        }else{
            if(!insertAVL(T->rchild, key, taller)){
                return 0;   // 未插入
            }
            if(taller){
                switch (T->bf){
                    case LH:  // 原本左子树比右子树高，现等高
                        T->bf = EH; taller = false;
                        break;
                    case EH:  // 原本左子树、右子树等高，现因右子树增高而使树增高
                        T->bf = RH; taller = true;
                        break;
                    case RH:  // 原本右子树比左子树高，需要做平衡处理
                        rightBalance(T); taller = false;
                        break;
                }
            }
        }
    }
}