```bash
g++ --version

g++ (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
#### 2. 线性表
+ 编译与执行
```bash
g++ -o ch02.o ch02.cpp ch02_linear_table/*.cpp
./ch05.o
```

+ **顺序表**
```c
/**
 * 线性表的顺序存储
 */
typedef int ElemType;           // 元素数据类型
typedef struct SqList{
    ElemType* data;             // 顺序表的元素(数组)
    int length;                 // 顺序表的当前长度
}SqList;                        // 顺序表的类型定义

/**
 * 线性表的基本操作
 */
bool InitList(SqList &L);                           // 初始化表。构造一个空的线性表 。
int Length(SqList L);                               // 求表长。返回线性表 L 的长度，即 L 中数据元素的个数。
int LocateElem(SqList L, ElemType e);               // 按值查找操作。在表 L 中查找具有给定关键宇值的元素。
ElemType GetElem(SqList L, int i);                  // 按位查找操作。获取表 L 中第 i 个位置的元素的值。
bool ListInsert(SqList &L, int i, ElemType e);      // 插入操作。在表 L 中的第 i 个位置上插入指定元素 e。
bool ListDelete(SqList &L, int i, ElemType &e);     // 删除操作。删除表 L 中第 i 个位置的元素，并用 e 返回删除元素的值。
void PrintList(SqList L);                           // 输出操作。按前后顺序输出线性表 L 的所有元素值。
bool Empty(SqList L);                               // 判空操作。若 L 为空表， 则返回 true，否则返回 false。
bool DestroyList(SqList &L);                        // 销毁操作。销毁线性表，井释放线性表 L 所占用的内存空间。
```
+ **链表**
```c
/**
 * 单链表 (带头结点)
 */
typedef int ElemType;           // 元素数据类型
typedef struct LNode{
    ElemType data;              // 数据域
    struct LNode* next;         // 指针域
}LNode, *LinkList;

/**
 * 单链表的基本操作
 */
LinkList List_HeadInsert(LinkList &L, int a[], int n);  // 采用头插法建立单链表
LinkList List_TailInsert(LinkList &L, int a[], int n);  // 采用尾插法建立单链表
LNode *GetElem(LinkList L, int i);                      // 按位查找操作。获取表 L 中第 i 个位置的元素的值。
LNode *LocateElem(LinkList L, ElemType e);              // 按值查找操作。在表 L 中查找具有给定关键宇值的元素。
void PrintLinkList(LinkList L);                         // 输出操作。按前后顺序输出线性表 L 的所有元素值。
int Length(LinkList L);                                 // 求表长。返回线性表 L 的长度，即 L 中数据元素的个数。

/**
 * 双链表
 */
typedef struct DNode{           // 定义双链表结点类型
    ElemType data ;             // 数据域
    struct DNode *prior,*next;  // 前驱和后继之好着呢
}DNode, *DLinkList ;
```
+ **练习**
```c
/*
 * 练习 2.2 线性表的顺序实现 p19-p21
 */
bool Del_Min(SqList &L, ElemType &value);               // 1. 从顺序表中删除具有最小值的元素
void Reverse (SqList &L);                               // 2. 将顺序表 L 的所有元素逆置

                                                        /** ★★☆ */
void del_x_2(SqList &L,ElemType x);                     // 3. 删除线性表中所有值为 x 的数据元素
bool Del_s_t(SqList &L, ElemType s, ElemType t);        // 4. 从有序顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素
bool Del_s_t2(SqList &L, ElemType s, ElemType t);       // 5. 从顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素

                                                        /** ★★☆ */
bool Delete_Same(SqList& L);                            // 6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。

                                                        /** ★★☆ */
bool Merge(SqList A, SqList B, SqList &C);              // 7. 将两个有序顺序表合并为一个新的有序顺序表

void Reverse(ElemType A[], int m, int n, int size);     // 8. 将数组顺序表位置互换
                                                        // 10. 将 R 中保存的序列循环左移 p (O<p<n ) 个位置

                                                        /** ★★☆ */
void SearchExcgIst(ElemType A[], int n, ElemType x);    // 9. 线性表递增有序，在表中查找数值为 x 的元素

                                                        /** ★★★ */
int MSearch(int A[],int B[],int n);                     // 11. 找出两个序列 A 和 B 的中位数。
int Majority (int A[], int n);                          // 12. 找出数组 A 的主元素
int findMissMin(int A[] , int n);                       // 13. 找出数组中未出现的最小正整数


/*
 * 练习 2.2 线性表的链式表示 p40-p44
 */
void Del_X_1(LinkList &L, ElemType x);                  // 1. 设计一个递归算法, 删除不带头结点的单链表 L 中所有值为 x 的结点。
void Del_X_2(LinkList &L, ElemType x);                  // 2. 在带头结点的单链表 L 中，删除所有值为 x 的结点
void R_Print(LinkList L);                               // 3. 带头结点的单链表从尾到头反向输出每个结点的值
LinkList Delete_Min(LinkList &L);                       // 4. 带头结点的单链表 L 中删除一个最小值结点
LinkList Reverse_1(LinkList &L);                        // 5. 将带头结点的单链表就地逆置
void Sort(LinkList &L);                                 // 6. 有一个带头结点的单链表 L，设计一个算法使其元素递增有序。
void RangeDelete(LinkList &L, int min, int max);        // 7. 删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素
LinkList Search_Lst_Common(LinkList L1, LinkList L2);   // 8. 给定两个单链表，编写算法找出两个链表的公共结点。
void MinDelete(LinkList &head);                         // 9. 按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间
LinkList DisCreat_1(LinkList &A);                       // 10.将一个带头结点的单链表 A 分解为两个带头结点的单链表 A 和 B
```

#### 5. 树与二叉树
+ 编译与执行
```bash
g++ -o ch05.o ch05.cpp ch05_tree/BiTree.cpp ch05_tree/Tree.cpp ch05_tree/BinarySearchTree.cpp ch05_tree/exercises.cpp
./ch05.o
```
+ **二叉树**
```c
/**
 * 二叉树的链式存储结构
 */
typedef struct BiTNode {
    ElemType data;					                         // 数据域
    struct BiTNode *lchild, *rchild;                         // 左、右孩子指针
    // BiTNode(ElemType x) : data(x), lchild(NULL), rchild(NULL) {}
} BiTNode, *BiTree;

/**
 * 构造一个二叉树(按前序遍历，'#'表示空)
 */
void Create(BiTree &root, char const *&elements);

/**
 * 二叉树的遍历
 */
void visit(BiTNode *node);  // 访问节点

void PreOrder(BiTree T);    // 先序遍历
void InOrder(BiTree T);     // 中序遍历
void PostOrder(BiTree T);   // 后序遍历

void PreOrder2(BiTree T);   // 先序遍历(非递归)
void InOrder2(BiTree T);    // 中序遍历(非递归)
void PostOrder2(BiTree T);  // 后序遍历(非递归) 最难!

void LevelOrder(BiTree T);  // 层次遍历
```

+ **树、森林**
```c
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
```

+ **二叉排序树** (二叉搜索树)
```c
/**
 * 二叉排序树
 */
typedef struct BSTNode{
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

/**
 * 基本操作
 */
void visit(BSTNode *node);
BSTNode* BST_Search(BSTree T, int key);        // 查找关键字 (非递归版本)
BSTNode* BST_SearchR(BSTree T, int key);       // 查找关键字 (递归版本)
bool BST_Insert(BSTree &T, int key);           // 二叉排序树插入操作
void BST_Create(BSTree &T, int *elems, int n); // 构造二叉排序树
// 删除操作(太复杂、忽略)
```
+ **练习**
```c
/*
 * 练习 5.3 二叉树的遍历和索引二叉树 (p149-p151)
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
 * 练习 5.4 树、森林 (p176-p177)
 */
int leaves(CSTree T);                                   // 5. 编程求以孩子兄弟表示法存储的森林的叶子结点数。

                                                        /** ★★☆ */
void createCSTree_Degree(                               // 7. 己知一棵树的层次序列及每个结点的度，编写算法构造此树的孩子兄弟链表。
    CSTree&T, ElemType e[], int degree[], int n);
int Height (CSTree bt);                                 // 6. 以孩子兄弟链表为存储结构，请设计递归算法求树的深度。


/*
 * 练习 5.5 树与二叉树的应用 (p195-p196)
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
 */
void DelLeafNode(BiTree bt);                            // 6. 从二叉树中删去所有叶结点。     (层次遍历 => 参考练习5.3_11)
int GetLevel(BiTree bt,BiTNode *p);                     // 7. 计算指定结点 *p 所在的层次。  (层次遍历=>参考练习5.3_5)
```

#### 参考
[1][C++之函数/结构体/类 模板](https://zhuanlan.zhihu.com/p/37669989)