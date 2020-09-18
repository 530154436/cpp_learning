****
### 声明
本人本着以学习为目的整合了`2021年王道数据结构考研复习指导`、中的大部分算法题、并给出相应的解答和示例，在此不保证所有的题解均正确无误，
仅供学习参考，请勿用于商业用途，如若侵权，请联系并删除。

### 目录
- [1. 王道数据结构](#1-------)
  * [1.1 环境配置](#11-----)
  * [1.2 data_struct/wangdao](#12-data-struct-wangdao)
  * [1.3  习题汇总](#13------)
    + [1.3.1 线性表](#131----)
    + [1.3.2 栈、队列](#132-----)
    + [1.3.3 二叉树](#133----)
    + [1.3.4 排序](#134---)
- [参考](#--)
****
#### 1. 王道数据结构
##### 1.1 环境配置
+ 编译器版本
```bash
g++ --version

g++ (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
##### 1.2 data_struct/wangdao
+ 编译
```c
g++ -o ch02.o ch02.cpp ch02_linear_table/*.cpp
g++ -o ch03.o ch03.cpp ch03_stack_queue/*.cpp
g++ -o ch05.o ch05.cpp ch05_tree/*.cpp
g++ -o ch08.o ch08.cpp ch08_sort/*.cpp -std=c++11
```
+ 目录结构
```
├── README.md
├── ch02.cpp
├── ch02_linear_table (顺序表、单链表)
│   ├── LinkList.cpp
│   ├── LinkList.hpp
│   ├── SqList.cpp
│   ├── SqList.hpp
│   ├── exercises.cpp
│   └── exercises.hpp
├── ch03.cpp
├── ch03_stack_queue (栈、队列)
│   ├── SqQueue.cpp
│   ├── SqQueue.hpp
│   ├── SqStack.cpp
│   ├── SqStack.hpp
│   ├── exercises.cpp
│   └── exercises.hpp
├── ch05.cpp
├── ch05_tree (二叉树、二叉排序树、树、森林)
│   ├── BiTree.cpp
│   ├── BiTree.hpp
│   ├── BinarySearchTree.cpp
│   ├── BinarySearchTree.hpp
│   ├── ThreadTree.cpp
│   ├── ThreadTree.h
│   ├── Tree.cpp
│   ├── Tree.hpp
│   ├── exercises.cpp
│   └── exercises.hpp
├── ch08.cpp
├── ch08_sort (插入、交换、选择、归并)
    ├── exercises.cpp
    ├── exercises.hpp
    ├── sort.cpp
    └── sort.hpp
```
##### 1.3  习题汇总
###### 1.3.1 线性表
> 详见: ch02_linear_table/exercises.hpp

+ 练习 2.2 线性表的顺序实现 p19-p21
```c
void Reverse(SqList &L);                                // 2. 将顺序表 L 的所有元素逆置
void Reverse(ElemType A[], int m, int n, int size);     // 8. 将数组顺序表位置互换
                                                        // 10. 将 R 中保存的序列循环左移 p (O<p<n ) 个位置
void del_x_2(SqList &L,ElemType x);                     // 3. 删除线性表中所有值为 x 的数据元素
bool Delete_Same(SqList& L);                            // 6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
bool Del_s_t(SqList &L, ElemType s, ElemType t);        // 4. 从有序顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素
bool Del_s_t2(SqList &L, ElemType s, ElemType t);       // 5. 从顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素
bool Merge(SqList A, SqList B, SqList &C);              // 7. 将两个有序顺序表合并为一个新的有序顺序表
void SearchExcgIst(ElemType A[], int n, ElemType x);    // 9. 线性表递增有序，在表中查找数值为 x 的元素
int MSearch(int A[],int B[],int n);                     // 11. 找出两个序列 A 和 B 的中位数。
double MSearch1(int A[], int m, int B[],int n);
int MSearch2(int A[],int B[],int n);                    /** ❌ */
bool Del_Min(SqList &L, ElemType &value);               // 1. 从顺序表中删除具有最小值的元素
int Majority (int A[], int n);                          // 12. 找出数组 A 的主元素
int findMissMin(int A[] , int n);                       // 13. 找出数组中未出现的最小正整数
```

+ 练习 2.2 线性表的链式表示 p40-p44
```c
LinkList Search_Lst_Common(LinkList L1, LinkList L2);   // 8. 给定两个单链表，编写算法找出两个链表的公共结点。
LNode* find_addr(LNode *strl , LNode *str2);            // 22.找出由 str1 和 str2 所指向两个链表共同后缀的起始位置
int Search_k(LinkList list, int k);                     // 21.查找链表中倒数第 k 个位直上的结点(k为正整数)
LNode* FindLoopStart(LNode *head);                      // 24.判断一个链表是否有环，如果有，找出环的入口点并返回，否则返回 NULL。
void change_list(LNode*&h);                             // 25. 单链表{a1,a2,··· ,an}转换为{a1,an,a2,an-1,a3,an-2,···}
void Del_X_1(LinkList &L, ElemType x);                  // 1. 设计一个递归算法, 删除不带头结点的单链表 L 中所有值为 x 的结点。
void Del_X_2(LinkList &L, ElemType x);                  // 2. 在带头结点的单链表 L 中，删除所有值为 x 的结点
void RangeDelete(LinkList &L, int min, int max);        // 7. 删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素
void Del_Same(LinkList &L);                             // 12.递增有序的单链表表去重(去掉数值相同的元素)
LinkList Delete_Min(LinkList &L);                       // 4. 带头结点的单链表 L 中删除一个最小值结点
void MinDelete(LinkList &head);                         // 9. 按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间
void Del_All(LinkList &L);                              // 19.反复找出单链表中结点值最小的结点并输出，然后将该结点从中删除，直到单链表空为止，再删除表头结点。
void R_Print(LinkList L);                               // 3. 带头结点的单链表从尾到头反向输出每个结点的值
LinkList Reverse_1(LinkList &L);                        // 5. 将带头结点的单链表就地逆置
void Sort(LinkList &L);                                 // 6. 有一个带头结点的单链表 L，设计一个算法使其元素递增有序。
LinkList DisCreat_1(LinkList &A);                       // 10.将一个带头结点的单链表 A 分解为两个带头结点的单链表 A 和 B
LinkList DisCreat_2(LinkList &A);                       // 11.单链表 A 分解为A={a1,a2,··· , an,}, B={bn,bn-1,...,b2,b1}
LinkList MergeList(LinkList La,LinkList Lb);            // 13.将两个按元素值递增次序排列的单链表归并为一个递减的单链表
LinkList Get_Common(LinkList A, LinkList B);            // 14.从两个元素递增有序的单链表(带头结点)中的公共元素产生单链表C
void Union(LinkList &la, LinkList &lb);                 // 15.求两个元素递增排列的单链表 A 与 B 的交集，并存放于 A 链表中。
int Symmetry(DLinkList L);                              // 17.判断带头结点的循环双链表是否对称。
LinkList Link(LinkList &h1 , LinkList &h2);             // 18.将循环单链表h2 链接到循环单链表h1，要求链接后的链表仍保持循环链表。
DLinkList Locate(DLinkList &L,ElemType x);              // 20.非循环双向链表符合要求的 Locate(L,x) 运算的算法
int Pattern(LinkList A,LinkList B);                     // 16. 判断序列 B 是否是序列 A 的连续子序列
void func(LNode* &h, int n);                            // 23.对于链表中 data 的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点
```

###### 1.3.2 栈、队列
+ 练习 3.1 栈 p71
```c
int dc(LNode<char> *L, int n);                                  // 4. 判断链表的全部 n 个字符是否中心对称
typedef struct sstk{                                            // 5. 共享栈
    int top[2];
    ElemType data[MaxStackSize];
};
int push(ElemType i, ElemType x);
int pop (ElemType i);
```

+ 练习 3.2 队列
```c
typedef struct tqueue{                                          // 1. 设置一个标志域 tag 的入队和出队算法
    ElemType data[MaxStackSize];
    int front,rear,tag;
};
int tEnQueue(tqueue &s, ElemType x);
int tDeQueue(tqueue &s, ElemType &x);
void Inverse(SqQueue<ElemType> &Q, SqStack<ElemType> &S);       // 2. Q 是一个队列，S 是一个空栈，实现将队列中的元素逆置的算法。
typedef struct SSQueue{                                         // 3. 利用两个栈 S1, S2 来模拟一个队列
    SqStack<ElemType> S1,S2;
};
int EnSSQueue(SSQueue &q, ElemType x);
int DeSSQueue(SSQueue &q, ElemType &x);
int SSQueueEmpty(SSQueue q);
```

+ 3.3 核和队列的应用 p96-97
```c
bool BracketsCheck(char *str);                                 // 1. 判别表达式中的括号是否配对
double p(int n,double x);                                      // 2. 利用一个找实现递归函数的非递归计算
```

###### 1.3.3 二叉树
+ 练习 5.3 二叉树的遍历和索引二叉树 (p149-p151)
```c
void InvertLevel(BiTree T);                             // 4. 二又树自下而上、从右到左的层次遍历算法。
int Btdepth(BiTree T);                                  // 5. 非递归求二叉树的高度。
int BtdepthR(BiTree T);
BiTNode* BiTreePreinCreate(ElemType *A, int l1, int h1, // 6. 根据先序遍历序列和中序遍历序列建立二叉链表 (二叉树中各结点的值互不相同)
                           ElemType *B, int l2, int h2);
bool IsComplete(BiTree T);                              // 7. 判别二叉树是否为完全二叉树。
int DsonNodes (BiTree T);                               // 8. 计算一棵给定二叉树的所有双分支结点个数。
int DsonNodes1 (BiTree T);
void swap(BiTree T);                                    // 9. 交换二叉树中所有结点的左、右子树。
void swap1(BiTree T);
ElemType PreNode(BiTree T, int k);                      // 10. 求先序遍历序列中第 k (1<= k <= 二又树中结点个数)个结点的值。
void SearchDeleteXTree(BiTree T, ElemType x);           // 11. 对于树中每个元素值为 x 的结点，删去以它为根的子树，并释放相应的空间。
void Search (BiTree T , ElemType x);                    // 12. 在二叉树中查找值为 x 的结点，打印值为 x 的结点的所有祖先
bool SearchR (BiTree T , ElemType x);
BiTree Ancestor(BiTree ROOT, BiTNode *p, BiTNode *q);   // 13. 找到 p 和 q的最近公共祖先结点 r。
BiTree AncestorR(BiTree T, BiTNode *p, BiTNode *q);
int BTWidth(BiTree T);                                  // 14. 求非空二又树 b 的宽度(即具有结点数最多的那一层的结点个数)。
void PreToPost(ElemType pre[],int l1, int h1,           // 15. 满二叉树已知其先序序列为 pre，求后序序列 post。
               ElemType post[],int l2,int h2);
BiTNode* LeafToLinikedList(BiTNode* T);                 // 16. 二叉树的叶结点按从左到右的顺序连成一个单链表
bool Similar(BiTree T1, BiTree T2);                     // 17. 判断两棵二叉树是否相似
ThreadNode* InPostPre(ThreadNode* T , ThreadNode* p);   // 18. 写出在中序线索二叉树里查找指定结点在后序的前驱结点的算法 。
int wpl(BiTree T);                                      // 19. 二又树的带权路径长度
void BtreeToExp(BiTree T, int depth);                   // 20. 将给定的表达式树(二叉树)转换为等价的中缀表达式并输出。
```

+ 练习 5.4 树、森林 (p176-p177)
```c
int leaves(CSTree T);                                   // 5. 编程求以孩子兄弟表示法存储的森林的叶子结点数。
void createCSTree_Degree(                               // 7. 己知一棵树的层次序列及每个结点的度，编写算法构造此树的孩子兄弟链表。
    CSTree&T, ElemType e[], int degree[], int n);
int Height (CSTree bt);                                 // 6. 以孩子兄弟链表为存储结构，请设计递归算法求树的深度。
```

+ 练习 5.5 树与二叉树的应用 (p195-p196)
```c
bool JudgeBST(BSTree bt);                               // 6. 试编写一个算法，判断给定的二叉树是否是二叉排序树。

int level(BSTree bst, BSTNode *p);                      // 7. 设计一个算法，求出在指定结点给定二叉排序树中的层次。
int levelR(BSTree bst, BSTNode *p);
                                                        /** ★★☆ */
bool Judge_AVL(BSTree bst, int &depth);                 // 8. 利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法。
int MinBST(BSTree bst);                                 // 9. 设计一个算法，求出给定二叉排序树中最小和最大的关键字。
int MaxBST(BSTree bst);
void OutPut(BSTNode *bt, int key);                      // 10. 设计一个算法 ，从大到小输出二叉排序树中所有值不小于 k 的关键字。
BSTNode *Search_Small(BSTNode*t , int k );              // 12. 二叉排序树上查找第 k (1<=k<=n) 小的元素，并返回指向该结点的指针。
```

+ 总结 p206-p207
```
void DelLeafNode(BiTree bt);                            // 6. 从二叉树中删去所有叶结点。     (层次遍历 => 参考练习5.3_11)
int GetLevel(BiTree bt,BiTNode *p);                     // 7. 计算指定结点 *p 所在的层次。  (层次遍历=>参考练习5.3_5)
```

###### 1.3.4 排序
+ 8.3 交换排序 p323-p324
```c
void BubbleSort(ElemType A[], int n);                   // 2. 双向冒泡排序算法
void move(ElemType A[], int n);                         // 3. 把所有奇数移动到所有偶数前边的算法
void move2(ElemType A[], int n);
int Partition2(ElemType A[], int low, int high);        // 4. 重新编写快速排序的划分算法，使之每次选取的枢轴值都是随机地从当前子表中选择的。
int kth_elem(ElemType A[] , int low, int high, int k);  // 5. 数组中找出第 k 小的元素
int setPartition(ElemType A[], int n);                  // 6. 将A划分为两个不相交的子集，满足 |n_1-n_2| 最小且 |S_1-S_2| 最大
int PartitionN(ElemType A[],int n);                     // 4. (8.6)数组{K_1,K_2，...，K_n}, 将 K_n，放在将元素排序后的正确位置上
void Flag_A_rrange(ElemType A[],int n);                 // 7. 荷兰国旗问题
```

+ 8.4 选择排序 p335
```c
void selectSort(LNode<ElemType> *&L);                   // 4. 在基于单链表表示的待排序关键字序列上进行简单选择排序。
bool IsMinHeap(ElemType A[], int len);                  // 5. 试设计一个算法，判断一个数据序列是否构成一个小根堆。
```

+ 8.6 各种内部排序算法的比较和应用
```c
void Insert_Sort(ElemType A[] , int m, int n);          // 2. 前m个元素递增有序，后n个元素递增有序，设计一个算法，使得整个顺序表有序。
```

##### 1.4 参考
[1][2021年王道数据结构考研复习指导](http://www.cskaoyan.com/)
[2][C++之函数/结构体/类 模板](https://zhuanlan.zhihu.com/p/37669989)