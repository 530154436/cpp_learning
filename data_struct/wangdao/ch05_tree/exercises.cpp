//
// Created by 郑楚彬 on 2020/8/18.
//
/**
 * 5.3 二叉树的遍历和线索二叉树-综合应用题 (p149-p151)
 */
#include "exercises.hpp"

/**
 * 4. 二又树自下而上、从右到左的层次遍历算法。
 *
 * 算法思想: 利用原有的层次遍历算法，出队的同时将各结点指针入栈，在所有结点入栈后再从栈顶开始依次访问即为所求的算法。
 */
void InvertLevel(BiTree T){
    if(!T) return;
    SqStack<BiTNode*> s; InitStack(s);
    SqQueue<BiTNode*> q; InitQueue(q);
    EnQueue(q, T);
    BiTNode *p;

    while(!QueueEmpty(q)){                  // 从上而下层次遍历
        DeQueue(q, p);                      // 出队、入栈
        Push(s, p);
        if(p->lchild)
        	EnQueue(q, p->lchild);          // 若左子女不空，则入队列
        if(p->rchild)
        	EnQueue(q, p->rchild);          // 若右子女不空，则入队列
    }

    while(!StackEmpty(s)){
    	Pop(s, p);
    	visit(p);
    }
}

/**
 * 5. 假设二又树采用二又链表存储结构, 设计一个非递归算法求二又树的高度。
 *
 * 算法思想:
 *    方法1: 层次遍历
 *        广度优先搜索的队列里存放的是「当前层的所有节点」。每次拓展下一层的时候，需要将队列里的所有节点都拿出来进行拓展，
 *        保证每次拓展完的时候队列里存放的是当前层的所有节点，并用一个变量来维护拓展的次数，即为该二叉树的深度。
 *    方法2: 后序遍历递归算法
 */
int Btdepth(BiTree T){
    int depth = 0;
    if(!T) return depth;

    BiTNode *p;
    SqQueue<BiTNode*> q; InitQueue(q);
    EnQueue(q, T);

    while(!QueueEmpty(q)){
        int len = QueueLength(q);           // 当前层的节点数
        while(len>0){                       // 遍历当前层的所有节点
            DeQueue(q, p);
            if(p->lchild)
                EnQueue(q, p->lchild);
            if(p->rchild)
                EnQueue(q, p->rchild);

            len--;
        }
        depth++;                            // 层数+1
    }
    return depth;
}

int BtdepthR(BiTree T){
    if(!T) return 0;
    int ldepth = BtdepthR(T->lchild);
    int rdepth = BtdepthR(T->rchild);
    return ldepth>rdepth?ldepth+1:rdepth+1;
}

/**
 * 6. 设一棵二又树中各结点的值互不相同，其先序遍历序列和中序遍历序列分别存于两个一维数组 A[1...n] 和 B[1...n] 中，
 *    试编写算法建立该二又树的二又链表。
 *
 * 算法思想:
 *    (1) 根据先序序列确定树的根结点。
 *    (2) 根据根结点在中序序列中划分出二叉树的左、右子树包含哪些结点，
 *        然后根据左、右子树结点在先序序列中的次序确定子树的根结点，即回到步骤 (1)。
 */
BiTNode* BiTreePreinCreate(ElemType *A, int l1, int h1, ElemType *B, int l2, int h2){
    if(l1>h1) return NULL;
    int middle = l2;
    while(middle<=h2 && A[l1]!=B[middle])                                   // 根结点在中序序列中的划分
        middle++;
    int lnum = middle-l2;                                                   // 左子树长度
    int rnum = h2-middle;                                                   // 右子树长度

    BiTNode* root = (BiTNode *)malloc(sizeof(BiTNode*));                    // 建根结点
    root->data = A[l1];
    root->lchild = BiTreePreinCreate(A, l1 + 1, l1 + lnum, B, l2, middle - 1);     // (A,l1+1,l1+lnum,B,l2,l2+lnum-1);
    root->rchild = BiTreePreinCreate(A, l1 + lnum + 1, h1, B, middle + 1, h2);     // (A,h1-rnum+1,h1,B,h2-rnum+1,h2);
    return root;
}

/**
 * 7. 二叉树按二叉链表形式存储，写一个判别二叉树是否为完全二叉树的算法
 *
 * 算法思想: 采用层次遍历，将所有结点加入队列(包括空结点)。遇到空结点时，查看其后是否有非空结点。 若有，则二叉树不是完全二叉树。
 */
bool IsComplete(BiTree T){
    if(!T) return true;

    BiTNode *p;
    SqQueue<BiTNode *> q; InitQueue(q);
    EnQueue(q, T);

    while(!QueueEmpty(q)){
        DeQueue(q, p);
        if(p){                                  // 结点非空， 将其左、右子树入队列
            EnQueue(q, p->lchild);
            EnQueue(q, p->rchild);
        }else{                                  // 结点为空，检查其后是否有非空结点
            while(!QueueEmpty(q)){
                DeQueue(q, p);
                if(p) return false;             // 结点非空， 则二叉树为非完全二叉树
            }
        }
    }

    return true;
}

/**
 * 8. 假设二叉树采用二叉链表存储结构存储，试设计一个算法，计算一棵给定二叉树的所有双分支结点个数。
 *
 * 算法思想:
 *     方法1: 设置 count 变量，每遍历一个节点，判断是否为双分支节点，若是则 count++
 *     方法2: 递归模型
 *           f(b)=0                                 若b为空
 *           f(b)=f(b->lchild)+f(b一>rchild)+1      若为双分支节点
 *           f(b)=f(b->lchild)+f(b一>rchild)        其他情况单分支结点或叶子结点)
 */

void count_two_branch(BiTree T, int &count){
    if(!T) return;
    if(T->lchild && T->rchild)              // 双分支节点
        count++;
    count_two_branch(T->lchild, count);     // 遍历左子树
    count_two_branch(T->rchild, count);     // 遍历右子树
}

int DsonNodes (BiTree T){
    int count = 0;
    count_two_branch(T, count);
    return count;
}

int DsonNodes1 (BiTree T){
    if(!T) return 0;
    else if(T->lchild && T->rchild) return DsonNodes1(T->lchild)+DsonNodes1(T->rchild)+1;   // 双分支节点
    else return DsonNodes1(T->lchild)+DsonNodes1(T->rchild);                                // 单分支或叶子节点
}

/**
 * 9. 设树 B 是一棵采用链式结构存储的二叉树，编写一个把树 B 中所有结点的左、右子树进行交换的函数 。
 *
 * 算法思想:
 *    方法1(后序遍历、自底向上)
 *        (1) 交换 b 结点的左孩子的左、右子树
 *        (2) 交换 b 结点的右孩子的左、右子树
 *        (3) 交换 b 结点的左、右子树
 *        递归结束条件: 结点为空
 *
 *    方法2(前序遍历、自顶向下)
 *        (1) 交换 b 结点的左、右子树
 *        (2) 交换 b 结点的左孩子的左、右子树
 *        (3) 交换 b 结点的右孩子的左、右子树
 *        递归结束条件: 结点为空
 */
void swap(BiTree T){
    if(!T) return;
    BiTNode *p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
    swap(T->lchild);
    swap(T->rchild);
}

void swap1(BiTree T){
    if(!T) return;
    swap(T->lchild);
    swap(T->rchild);
    BiTNode *p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
}

/**
 * 10. 求先序遍历序列中第 k (1<= k <= 二又树中结点个数)个结点的值。
 *
 * 算法思想:
 *    设置一个 count 变量记录己访问过的结点的序号，其初值1。
 *    (1) 当二叉树 b 为空时返回特殊字梢 ’#’，
 *    (2) 当count==k时，表示找到了满足条件的结点，返回 b->data;
 *    (3) 当count!=k时，递归地在左子树中查找， 若找到则返回该值
 *    (4) 否则继续递归地在右子树中查找，并返回其结果 。
 */
ElemType findKth(BiTree T, int k, int &count){
    if(!T) return '#';                           // 空结点， 则返回特殊字符
    if(k==count)                                 // 相等，则当前结点即为第k个结点
        return T->data;
    count++;                                     // 下一个结点
    ElemType ch = findKth(T->lchild, k, count);  // 左子树中递归寻找
    if(ch!='#')                                  // 第k个节点在左子树中，则返回该值
        return ch;
    return findKth(T->rchild, k, count);         // 在右子树中递归寻找
}

ElemType PreNode(BiTree T, int k){
    int count = 1;
    return findKth(T, k, count);
}

/**
 * 11. 己知二叉树以二叉链表存储，编写算法完成: 对于树中每个元素值为 x 的结点，删去以它为根的子树，并释放相应的空间。
 *
 * 算法思想:
 *    (1) 后序遍历删除子树
 *        删除以元素值 x 为根的子树，只要能删除其左、右子树，就可以释放值为 x 的根结点，因此宜采用后序遍历。
 *    (2) 层次遍历查找并删除节点 x 及 左、右子树
 *        ① 找到某结点的父结点
 *        ② 删除值为x的结点，意味着应将其父结点的左(右)子女指针置空，
 */

void DeleteSubTree(BiTree T){                   //删除以bt为根的子树
    if(!T) return;
    DeleteSubTree(T->lchild);
    DeleteSubTree(T->rchild);
    free(T);
}

void SearchDeleteXTree(BiTree T, ElemType x){   /*删除x节点后，父节点的左右孩子需置为空，否则产生野指针*/
    if(!T) return;
    if(T->data==x){                             // 若根结点值为 x，则删除整棵树
        DeleteSubTree(T);
        return;
    }

    SqQueue<BiTNode*> q; InitQueue(q);
    EnQueue(q, T);
    BiTNode* p;
    while(!QueueEmpty(q)){
        DeQueue(q, p);
        visit(p);
        if(p->lchild){                          // 若左孩子非空
            if(p->lchild->data==x){             // 左子树符合，则删除左子树
                DeleteSubTree(p->lchild);
                p->lchild = NULL;               // 父结点的左孩子置空
            }else{
                EnQueue(q, p->lchild);          // 左孩子入队
            }
        }
        if(p->rchild){
            if(p->rchild->data==x){
                DeleteSubTree(p->rchild);
                p->rchild = NULL;
            }else{
                EnQueue(q, p->rchild);
            }
        }
    }
}

/**
 * 12. 在二叉树中查找值为 x 的结点，试编写算法(用 C 语言) 打印值为 x 的结点的所有祖先，假设值为 x 的结点不多于一个 。
 *
 * 算法思想:  采用非递归后序遍历，最后访问根结点，访问到值为 x 的结点时，栈中所有元素均为该结点的祖先，依次出栈打印即可 。
 *    方法1: 后序遍历(递归)
 *    方法2: 后序遍历(非递归)
 */
bool SearchR (BiTree T , ElemType x){
    if(!T) return false;
    if(T->data==x) return true;

    bool left = SearchR(T->lchild, x);
    bool right = SearchR(T->rchild, x);
    if(left || right){
        visit(T);
        return true;
    }
    return false;
}

void FindAncestorsForX(BiTree T, ElemType x, SqStack<BiTNode*> &s){ // 非递归后序遍历
    BiTNode *p = T;
    BiTNode *r = NULL;
    while(p || !StackEmpty(s)){
        if(p){
            Push(s, p);
            p = p->lchild;
        }else{
            GetTop(s, p);
            if(p->rchild && p->rchild!=r){
                p = p->rchild;
                Push(s, p);
                p = p->lchild;
            }else{
                Pop(s, p);
                if(p->data==x)                       // 只有这里跟非递归后序遍历不同
                    break;
                r = p;
                p = NULL;
            }
        }
    }
}

void Search (BiTree T , ElemType x){
    SqStack<BiTNode*> s; InitStack(s);
    BiTNode *p;
    FindAncestorsForX(T, x, s);
    while (!StackEmpty(s)){                 // 出栈打印祖先节点
        Pop(s, p);
        visit(p);
    }
}


/**
 * 13. 设一棵二叉树的结点结构为( LLINK, INFO, RLINK), ROOT 为指向该二又树根结点的指针，p 和 q 分别为指向该二叉树中任意两个结点的指针，
 *     试编写算法 ANCESTOR(ROOT,p,q, r)，找到 p 和 q的最近公共祖先结点 r。 （一个节点也可以是它自己的祖先）
 *
 * 算法思路:
 *    方法1 后序遍历(递归)
 *         以根节点为起点，往左右分支上寻找，如果找到了 p 或 q 节点，则返回该节点。
 *         否则，继续向叶子节点寻找，假想一下，如果一直递归到 null 还是找不到该节点，那么说明这个分支上不存在该节点。
 *
 *    方法2 后序遍历(非递归)
 *          分别求出 p、q 的所有祖先，然后对比
 *
 *    方法3 增加 *parent 指针域，指向父节点，转化为“两个链表求最近交点”
 *
 */
BiTree AncestorR(BiTree T, BiTNode *p, BiTNode *q){

    if(T==NULL || p==T || q==T)                             // 如果找到了 p 或 q 节点，则返回该节点
        return T;

    BiTNode* left = AncestorR(T->lchild, p, q);
    BiTNode* right = AncestorR(T->rchild, p, q);

    if(left && right) return T;                             // 节点在根节点的两侧
    if(left) return left;                                   // 说明在 left 分支上找到 p 或 q 节点
    return right;                                           // 否则返回 right
}

void FindAncestorsForX(BiTree T, BiTNode *x, SqStack<BiTNode*> &s){ // 非递归后序遍历
    BiTNode *p = T;
    BiTNode *r = NULL;
    while(p || !StackEmpty(s)){
        if(p){
            Push(s, p);
            p = p->lchild;
        }else{
            GetTop(s, p);
            if(p->rchild && p->rchild!=r){
                p = p->rchild;
                Push(s, p);
                p = p->lchild;
            }else{
                if(p==x)                       // 只有这里跟非递归后序遍历不同
                    break;
                Pop(s, p);
                r = p;
                p = NULL;
            }
        }
    }
}

BiTree Ancestor(BiTree T, BiTNode *p, BiTNode *q){
    SqStack<BiTNode*> s1,s2;
    InitStack(s1); InitStack(s2);
    BiTNode *p1=NULL, *p2=NULL;

    FindAncestorsForX(T, p, s1);                     // 找到 p 节点的所有祖先
    FindAncestorsForX(T, q, s2);                     // 找到 q 节点的所有祖先

    int len1=StackLength(s1), len2=StackLength(s2);
    while(len1<len2){ Pop(s2, p); len2--; }
    while(len2<len1){ Pop(s1, p); len1--; }
    while(!StackEmpty(s1)){
        Pop(s1, p1); Pop(s2, p2);
        if(p1==p2)                                  // 最近的祖先
            break;
    }
    return p1!=p2?NULL:p1;
}

/**
 * 14. 假设二叉树采用二叉链表存储结构，设计一个算法，求非空二又树 b 的宽度( 即具有结点数最多的那一层的结点个数)。
 *
 * 算法思想: 采用层次遍历的方法求出所有结点的层次，并将所有结点和对应的层次放在一个队列中。
 *          然后通过扫描队列求出各层的结点总数，最大的层结点总数即为二叉树的宽度。
 */
int BTWidth(BiTree T){
    if(!T) return 0;
    SqQueue<BiTNode *> q; InitQueue(q);
    BiTNode *p;
    EnQueue(q, T);
    int len=0,maxLen=0;

    while(!QueueEmpty(q)){
        len = QueueLength(q);               // 当前层的节点数
        if(len>maxLen) maxLen=len;
        while(len>0){                       // 当前层的所有节点出队，下一层的所有节点入队
            DeQueue(q, p);
            if(p->lchild)
                EnQueue(q, p->lchild);
            if(p->rchild)
                EnQueue(q, p->rchild);
            len--;
        }
    }
    return maxLen;
}

/**
 * 15. 设有一棵满二叉树(所有结点值均不同)，已知其先序序列为 pre，设计一个算法求其后序序列 post。
 */
void PreToPost(ElemType pre[],int l1, int h1, ElemType post[],int l2,int h2){
    if(h1>=l1){
        post[h2] = pre[l1];                                     // 后序序列的最后以个结点等于先序序列的第1个节点(根结点)。
        int half = (h1-l1)/2;                                   // 取中间位置(偏移量)
        PreToPost(pre, l1+1, l1+half, post, l2, l2+half-1);     // 转换左子树
        PreToPost(pre, l1+half+1, h1, post, l2+half, h2-1);     // 转换右子树
    }
}


/**
 * 16. 设计一个算法将二叉树的叶结点按从左到右的顺序连成一个单链表，表头指针为 head。
 *     二叉树按二叉链表方式存储，链接时用叶结点的右指针域来存放单链表指针。
 *
 * 算法思路: 前序遍历
 *    设置前驱结点指针 pre，初始化为头结点(哑编码)。遍历到叶结点时，就将它前驱的 rchild 指针指向它。
 */
void LinkLeaf(BiTNode* T, BiTNode* &p){
    if(!T) return;
    if(T->lchild==NULL && T->rchild==NULL){     // 叶结点
        p->rchild = T;                          // 将叶结点链入链表
        p = T;
    }
    LinkLeaf(T->lchild, p);
    LinkLeaf(T->rchild, p);
}

BiTNode* LeafToLinikedList(BiTNode* T){
    BiTNode* head = (BiTNode*) malloc(sizeof(BiTNode*));    // 哑编码
    head->data = '0';

    BiTNode* p = head;
    LinkLeaf(T, p);

    while (head){
        std::cout<<head->data<<"->";
        head = head->rchild;
    }
    std::cout<<"NULL";
    return head;
}

/**
 * 17. 试设计判断两棵二叉树是否相似的算法。 所谓二叉树 T1 和 T2相似，指的是 T1 和 T2 都是空的二又树或都只有一个根结点;
 *     或 T1 的左子树和 T2 的左子树是相似的，且 T1 的右子树和 T2 的右子树是相似的。
 *
 * 算法思想:
 *     (1) 若 T1 和 T2 都是空树，则相似;
 *     (2) 若有一个为空另一个不空，则必然不相似;
 *     (3) 否则递归地比较它们的左、右子树是否相似。
 */
bool Similar(BiTree T1, BiTree T2){
    if(T1==NULL && T2==NULL) return true;           // 两树皆空
    if(T1==NULL || T2==NULL) return false;          // 只有一树为空
    bool left = Similar(T1->lchild, T2->lchild);    // 递归判断
    bool right = Similar(T1->rchild, T2->rchild);
    return left&&right;
}

/**
 * 18. 写出在中序线索二叉树里查找指定结点在后序的前驱结点的算法。
 */
ThreadNode* InPostPre(ThreadNode* T , ThreadNode* p){
    ThreadNode* q;
    if(p->rtag==0){                             // 若 p 有右子女，则右子女是其后序前驱
        q = p->rchild;
    }else if(p->ltag==0){                       // 若 p 只有左子女，则左子女是其后序前驱
        q = p->lchild;
    }else if(p->lchild==NULL){                  // p 是中序序列第一个结点，无后序前驱
        q = NULL;
    }else{                                      // 顺左线索向上找 p 的祖先，若存在，再找祖先的左子女 => 这部分不是很理解❌
        while (p->ltag==1 && p->lchild!=NULL)
            p = p->lchild;
        if(p->ltag==0)
            q = p->lchild;                      // p 结点的祖先的左子女是其后序前驱
        else
            q = NULL;                           // 仅有单支树( p 是叶子)，已到根结点，p 无后序前驱
    }
    return q;
}

/**
 * 19.【2014 统考真题】 二又树的带权路径长度( WPL )是二又树中所有叶结点的带权路径长度之和。
 *     给定一棵二叉树 T，采用二叉链表存储，结点结构为 left  weight  right, 其中叶结点的 weight 域保存该结点的非负权值 。
 *     设 root 为指向 T 的根结点的指针， 请设计求 T的 WPL 的算法。
 *
 * 算法思路:
 *     (1) 若该结点是叶结点，则计算该结点的深度与权值之积。
 *     (2) 若该结点是非叶结点， 则左子树不为空时，对左子树调用递归算法，右子树不为空，对右子树调用递归算法，深度均为本结点的深度加 1。
 *     (3) 最后返回计算出的 wpl 即可。
 *
 */
void WplSum(BiTree T, int depth, int &sum){
    if(!T) return;
    if(T->lchild==NULL && T->rchild==NULL){     // 若为叶结点，则累积 wpl
        sum += depth*(T->data-'0');             // 结点的深度与权值之积
    }
    WplSum(T->lchild, depth+1, sum);
    WplSum(T->rchild, depth+1, sum);
}

int wpl(BiTree T){
    int sum = 0;
    WplSum(T, 0, sum);
    return sum;
}

/**
 * 20.【2017 统考真题】请设计一个算法，将给定的表达式树(二叉树)转换为等价的中缀表达式(通过括号反映操作符的计算次序)并输出。
 *     例如，当下列两棵表达式树作为算法的输入时:
 *     输出的等价中缀表达式分别为(a+b)*(c女(-d))和(a*b)+(- (c-d))。
 *
 * 算法思想:
 *     表达式树的中序序列加上必要的括号即为等价的中缀表达式。可以基于二叉树的中序遍历策略得到所需的表达式。
 */
void BtreeToExp(BiTree T, int depth){
    if(!T) return;
    if(T->lchild==NULL && T->rchild==NULL)  // 若为叶结点,输出操作数，不加括号
        std::cout<<T->data;
    else{
        if(depth>1) std::cout<<"(";         // 若有子表达式则加 1 层括号
        BtreeToExp(T->lchild, depth+1);
        std::cout<<T->data;                 // 输出操作符
        BtreeToExp(T->rchild, depth+1);
        if(depth>1) std::cout<<")";         // 若有子表达式则加 1 层括号
    }
}

/**
 * 7. 己知一棵树的层次序列及每个结点的度，编写算法构造此树的孩子兄弟链表。
 *
 * 算法思想:
 *    可设立一个辅助数组 poiηter[] 存储新建树的各结点的地址，再根据层次序列与每个结点的度，逐个链接结点。
 */
void createCSTree_Degree(CSTree&T, ElemType e[], int degree[], int n){
    CSNode* nodes[n];

    for(int i=0; i<n; i++){                                     // 初始化
        nodes[i] = (CSNode*) malloc(sizeof(CSNode*));
        nodes[i]->data = e[i];
        nodes[i]->firstChild = nodes[i]->nextSibling = NULL;
    }

    int j = 1;                                                  // j 为子女结点序号
    for(int i=0; i<n; i++){
        int d = degree[i];                                      // 结点 i 的度数
        if(d>=1){
            nodes[i]->firstChild = nodes[j];                    // 建立 i 与子女 j 间的链接
            j++;
            for(int k=2; k<=d; k++){                            // 建立孩子兄弟的联系
                nodes[j-1]->nextSibling = nodes[j];
                j++;
            }
        }
        display(nodes[i]);
    }

    T = nodes[0];
}

/**
 * 5. 编程求以孩子兄弟表示法存储的森林的叶子结点数。
 *
 * 算法思想:
 *    当森林(树) 以孩子兄弟表示法存储时
 *    (1) 若节点没有孩子(firstchild=null)，则它必是叶子
 *    (2) 总的叶子结点个数 = 孩子子树(firstchild)上的叶子数和 + 兄弟弟子树(nextSibling)上的叶结点个数之矛[I0
 */
int leaves(CSTree T){
    if(!T)
        return 0;
    else if(T->firstChild==NULL)                                // 若结点无孩子，则该结点必是叶子
        return 1+leaves(T->nextSibling);                        // 返回叶子结点和其兄弟子树中的叶子结点数
    else
        return leaves(T->firstChild)+leaves(T->nextSibling);    // 孩子子树和兄弟子树中叶子数之和
}

/**
 * 6. 以孩子兄弟链表为存储结构，请设计递归算法求树的深度。
 *
 * 算法思想:
 */
int Height (CSTree bt){
    if(!bt) return 0;
    int ch = Height(bt->firstChild);    // 第一子女树高
    int sh = Height(bt->nextSibling);   // 兄弟树高
    return ch+1>sh?ch+1:sh;
}

/**
 * 6. 试编写一个算法，判断给定的二叉树是否是二叉排序树。
 *
 * 算法思想:
 *    对给定的二叉树进行中序遍历，若始终能保持前一个值比后一个值小，则说明该二叉树是一棵二叉排序树。
 *
 * LeetCode 98. 验证二叉搜索树
 * https://leetcode-cn.com/problems/validate-binary-search-tree/submissions/
 * https://leetcode-cn.com/problems/validate-binary-search-tree/solution/bao-zhun-sheng-guo-guan-fang-ti-jie-by-novice2mast/
 */
bool Judge(BSTree bt, int &prev){
    if(!bt) return true;                // 空树
    bool l = Judge(bt->lchild, prev);   // 判断左子树是否是二叉排序树
    if(!l || prev>=bt->data)            // 若左子树返回值为false 或前驱大于等于当前结点
        return false;
    prev = bt->data;                    // 保存当前结点的关键字
    return Judge(bt->rchild, prev);     // 判断右子树
}

bool JudgeBST(BSTree bt){
    int prev = INT_MIN;
    return Judge(bt, prev);
}

/**
 * 7. 设计一个算法，求出在指定结点给定二叉排序树中的层次。
 *
 * 算法思想:
 *    在二叉排序树中，查找一次就下降一层。 因此，查找该结点所用的次数就是该结点在二叉排序序树中的层次。
 */
void SearchCount(BSTree bst, BSTNode *p, int &cnt){    // 类似递归查找
    if(!bst) return;
    cnt++;                               //std::cout<<bst->data<<":"<<p->data<<" => "<<cnt<<std::endl;
    if(bst->data==p->data)
        return;
    else if(p->data<bst->data)
        SearchCount( bst->lchild, p, cnt);
    else
        SearchCount( bst->rchild, p, cnt);
}

int levelR(BSTree bst, BSTNode *p){
    int cnt = 0;
    SearchCount(bst, p, cnt);
    return cnt;
}

int level(BSTree bst, BSTNode *p){   // 类似非递归查找
    int cnt = 0;
    while(bst){
        cnt++;
        if(bst->data==p->data)
            break;
        else if(p->data<bst->data)
            bst = bst->lchild;
        else
            bst = bst->rchild;
    }
    return cnt;
}

/**
 * 8. 利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法。
 *
 * 算法思想:
 *    采用后序遍历，设置二叉树的高度标记 depth，计算当前节点左右子树的高度，并判断左右子树之差的绝对值是否大于1，
 *    是则返回 false，否则返回 true。
 *
 * 剑指 Offer 55 - II. 平衡二叉树
 * https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
 */
bool Judge_AVL(BSTree bst, int &depth){
    if(!bst) return true;

    int dl=0, dr=0;                             // 左右子树的高度
    bool lJude = Judge_AVL(bst->lchild, dl);    // 递归判断左子树
    bool rJude = Judge_AVL(bst->rchild, dr);    // 递归判断右子树
    depth = 1+(dl>dr?dl:dr);                    // 计算当前节点的高度
    return abs(dl-dr)<=1 && lJude && rJude;     // 若子树高度差的绝对值<=1、且左、右子树都平衡时， 二叉树平衡
}

/**
 * 9. 设计一个算法，求出给定二叉排序树中最小和最大的关键字。
 *
 * 算法思想: 在一棵二叉排序树中，最左下结点即为关键字最小的节点， 最右下结点即为关键字最大的结点。
 *          本算法只要找出这两个结点即可，而不需要比较关键字
 */
int MinBST(BSTree bst){
    int val=INT_MIN;
    while(bst){                 // 求出二叉排序树中最小关键字结点
        val = bst->data;
        bst = bst->lchild;
    }
    return val;
}

int MaxBST(BSTree bst){
    int val=INT_MIN;
    while(bst){                 // 求出二叉排序树中最大关键字结点
        val = bst->data;
        bst = bst->rchild;
    }
    return val;
}

/**
 * 10. 设计一个算法 ，从大到小输出二叉排序树中所有值不小于 k 的关键字。
 *
 * 算法思想: 由二叉排序树的性质可知，右子树中所有的结点值均大于根结点值，左子树中所有的结点值均小于根结点值。
 *          为了从大到小输出，先遍历右子树，再访问根结点，后遍历左子树。
 */
void OutPut(BSTNode *bt, int key){
    if(!bt) return;
    OutPut(bt->rchild, key);
    if(bt->data>=key)
        std::cout<<bt->data<<" ";
    OutPut(bt->lchild, key);
}

/**
 * 12. 编写一个递归算法，在一棵有 n 个结点的、随机建立起来的二叉排序树上查找第 k (1<=k<=n) 小的元素，并返回指向该结点的指针。
 *     要求算法的平均时间复杂度为 O(log2n)。 二叉排序树的每个结点中除 data, lchild, rchild 等数据成员外，增加一个 couηt 成员，
 *     保存以该结点为栋的子树上的结点个数。
 *
 * 算法思想: 二叉搜索树的中序遍历是按从小大到排序的.
 *
 * 230. 二叉搜索树中第K小的元素
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
 */
void CountKth(BSTNode* root, int k, BSTNode* &res, int &cnt){
    if(!root) return ;
    CountKth(root->lchild, k, res, cnt);
    if(++cnt==k){
        res = root;
        return;
    }
    CountKth(root->rchild, k, res, cnt);
}

BSTNode* Search_Small(BSTNode* root, int k) {
    int cnt=0;
    BSTNode* res=NULL;
    CountKth(root, k, res, cnt);
    return res;
}