//
// Created by 郑楚彬 on 2020/8/18.
//
/**
 * 5.3 二叉树的遍历和线索二叉树-综合应用题 (p149-p151)
 *     假设: (1) 二又树采用二叉链表存储结构 ★★☆☆☆
 */
#include <climits>

#include "BiTree.hpp"
#include "ThreadTree.h"
#include "Tree.hpp"
#include "BinarySearchTree.hpp"
#include "../templates/SqStackTemplate.hpp"
#include "../templates/SqQueueTemplate.hpp"

/*
 * 练习 5.3 p149-p151
 */
void InvertLevel(BiTree T);                             // 4. 二又树自下而上、从右到左的层次遍历算法。
int Btdepth(BiTree T);                                  // 5. 非递归求二叉树的高度。
int BtdepthR(BiTree T);
                                                        /** ★★☆ */
BiTNode* BiTreePreinCreate(ElemType *A, int l1, int h1, // 6. 根据先序遍历序列和中序遍历序列建立二叉链表 (二叉树中各结点的值互不相同)
                           ElemType *B, int l2, int h2);

bool IsComplete(BiTree T);                              // 7. 判别二叉树是否为完全二叉树。
int DsonNodes (BiTree T);                               // 8. 计算一棵给定二叉树的所有双分支结点个数。
int DsonNodes1 (BiTree T);
void swap(BiTree T);                                    // 9. 交换二叉树中所有结点的左、右子树。
void swap1(BiTree T);
ElemType PreNode(BiTree T, int k);                      // 10. 求先序遍历序列中第 k (1<= k <= 二又树中结点个数)个结点的值。
void SearchDeleteXTree(BiTree T, ElemType x);           // 11. 对于树中每个元素值为 x 的结点，删去以它为根的子树，并释放相应的空间。

                                                        /** ★★☆ */
void Search (BiTree T , ElemType x);                    // 12. 在二叉树中查找值为 x 的结点，打印值为 x 的结点的所有祖先
bool SearchR (BiTree T , ElemType x);
                                                        /** ★★★ */
BiTree Ancestor(BiTree ROOT, BiTNode *p, BiTNode *q);   // 13. 找到 p 和 q的最近公共祖先结点 r。

BiTree AncestorR(BiTree T, BiTNode *p, BiTNode *q);
int BTWidth(BiTree T);                                  // 14. 求非空二又树 b 的宽度(即具有结点数最多的那一层的结点个数)。
void PreToPost(ElemType pre[],int l1, int h1,           // 15. 满二叉树已知其先序序列为 pre，求后序序列 post。
               ElemType post[],int l2,int h2);
BiTNode* LeafToLinikedList(BiTNode* T);                 // 16. 二叉树的叶结点按从左到右的顺序连成一个单链表
bool Similar(BiTree T1, BiTree T2);                     // 17. 判断两棵二叉树是否相似

                                                        /** ❌ */
ThreadNode* InPostPre(ThreadNode* T , ThreadNode* p);   // 18. 写出在中序线索二叉树里查找指定结点在后序的前驱结点的算法 。

int wpl(BiTree T);                                      // 19. 二又树的带权路径长度

                                                        /** ★★☆ */
void BtreeToExp(BiTree T, int depth);                   // 20. 将给定的表达式树(二叉树)转换为等价的中缀表达式并输出。


/*
 * 练习 5.4 p176-p177
 */
int leaves(CSTree T);                                   // 5. 编程求以孩子兄弟表示法存储的森林的叶子结点数。

                                                        /** ★★☆ */
void createCSTree_Degree(                               // 7. 己知一棵树的层次序列及每个结点的度，编写算法构造此树的孩子兄弟链表。
    CSTree&T, ElemType e[], int degree[], int n);
int Height (CSTree bt);                                 // 6. 以孩子兄弟链表为存储结构，请设计递归算法求树的深度。


/*
 * 练习 5.5 p195-p196
 */
                                                        /** ★★☆ */
bool JudgeBST(BSTree bt);                               // 6. 试编写一个算法，判断给定的二叉树是否是二叉排序树。

int level(BSTree bst, BSTNode *p);                      // 7. 设计一个算法，求出在指定结点给定二叉排序树中的层次。
int levelR(BSTree bst, BSTNode *p);
                                                        /** ★★☆ */
bool Judge_AVL(BSTree bst, int &depth);                 // 8. 利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法。
int MinBST(BSTree bst);                                 // 9. 设计一个算法，求出给定二叉排序树中最小和最大的关键字。
int MaxBST(BSTree bst);
void OutPut(BSTNode *bt, int key);                      // 10. 设计一个算法 ，从大到小输出二叉排序树中所有值不小于 k 的关键字。
BSTNode *Search_Small(BSTNode*t , int k );              // 12. 二叉排序树上查找第 k (1<=k<=n) 小的元素，并返回指向该结点的指针。


/*
 * 总结 p206-p207
 *     设二叉树的存储结构为二叉链表 ，编写有关二叉树的递归算法。
 */
void DelLeafNode(BiTree bt);                            // 6. 从二叉树中删去所有叶结点。     (层次遍历 => 参考练习5.3_11)
int GetLevel(BiTree bt,BiTNode *p);                     // 7. 计算指定结点 *p 所在的层次。  (层次遍历=>参考练习5.3_5)