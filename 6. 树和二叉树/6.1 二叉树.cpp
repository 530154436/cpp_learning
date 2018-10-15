//
// Created by 郑楚彬 on 2018/4/12.
//
#include "../utility/Tree/BiTree.h"

void test01(){
    BiTNode *root;
    char *eles = (char *)"ab#d##c#e##";
    init(root, eles);
    preorder(root);
}

/* ========================================================================== */
/*
 * 1. 表达式 a-(b+c)*(d/e)存储在下图所示的一棵以二叉链表为存储结构的二叉树中(二叉树节点的data
 *    域为字符型)，编写程序求出该表达式的值。
 */

int operation(int a, int b, char op){
    switch(op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        default:
            return 0;
    }
}

int test02(BiTNode *tree){
    if(tree!=NULL){
        // 如果当前节点的左子树和右子树非空，则用后序遍历方式求值
        if(tree->lchild!=NULL && tree->rchild!=NULL){
            int a = test02(tree->lchild);
            int b = test02(tree->rchild);
            char c = tree->data;
            return operation(a, b, c);
        }else{
            return tree->data-'0';
        }
    }else{
        return 0;
    }

}

/*
 * 2. 写一个算法求一棵二叉树的深度，二叉树以二叉链表为存储方式
 */
void test03(){
    BiTNode *root;
    char *eles = (char *)"ab#d##c#e##";
    init(root, eles);
    cout<< getDeepth(root)<< endl;
}


/*
 * 3. 查找值域等于key的节点
 */
void test04(){
    BiTNode *root, *tmp;
    char *eles = (char *)"ab#d##c#e##";
    init(root, eles);

    search(root, tmp, 'b');
    cout<< tmp->data << endl;
}

/*
 * 4. 求先序遍历序列中第k(0≤k≤二叉树中结点个数)个结点的值。
 */
int N=0; // 定义全局变量用于计数
void findKth(BiTNode *bt, int k){
    if(bt != NULL){
        // 第n个节点
        N++;
        if(N == k){
            cout << bt->data << endl;
            return;
        }
        findKth(bt->lchild, k);
        findKth(bt->rchild, k);
    }
}

void test05(){
    BiTNode *root, *tmp;
    char *eles = (char *)"ab#d##c#e##";
    init(root, eles);

    findKth(root, 4);
}

/*
 * 5. 假设二叉树采用二叉链表存储结构存储，设计一个算法，求出该二叉树的宽度
 *    (具有节点数最多的那一层上的节点个数)。
 */
typedef struct{
    BiTNode *p;
    int lno;
}St;

int maxNode(BiTNode *p){
    St queue[Max];
    int front=0, rear=0, LNO=0;
    BiTNode *q;

    if(p != NULL){
        // 第一个节点进队
        rear++;
        queue[rear].p = p;     // 根节点进队
        queue[rear].lno = 1;   // 根节点层数为1

        while(front != rear){
            // 节点出队时保存节点所在的层数
            front++;
            LNO = queue[front].lno;
            q = queue[front].p;

            if(q->lchild != NULL){
                // 左子树不为空，行数+1，并进队
                rear++;
                queue[rear].p = q->lchild;
                queue[rear].lno = LNO+1;
            }

            if(q->rchild != NULL){
                // 右子树不为空，行数+1，并进队
                rear++;
                queue[rear].p = q->rchild;
                queue[rear].lno = LNO+1;
            }
        }

        // 保留最大节点数
        int max=0;
        int i,j,n;

        // 按层数遍历队列
        for(j=1; j<=LNO; j++){
            n = 0;
            for(i=1; i<=rear; i++){
                // 统计每层节点数
                if(queue[i].lno == j){
                    n++;
                }
                if(n > max){
                    max = n;
                }
            }
        }
        return max;
    }else{
        return 0; // 空树直接返回0
    }
}

void test06(){
    BiTNode *root, *tmp;
    char *eles = (char *)"ab#d##cr##e##";
    init(root, eles);

    int max = maxNode(root);
    cout << max << endl;
}

/*
 * 二叉树非递归遍历测试
 */
void test07(){
    BiTNode *root, *tmp;
    char *eles = (char *)"123##5##4##";
    init(root, eles);

    cout << "非递归先序遍历:" << endl;
    preorderNonRecursion(root);

    cout << endl << "非递归中序遍历:" << endl;
    inorderNonRecursion(root);

    cout << endl << "非递归后序遍历:" << endl;
    postorderNonRecursion(root);

    cout << endl;
}
/* ========================================================================== */

/* ================================= 真题仿造 ================================= */
/*
 * 1. 已知一棵完全二叉树按顺序存储结构存储在数组tree[]中，假设二叉树节点类型为 char 型，
 *    节点个数为 n。设计一个算法，求出离下标分别为 i 和 j 的两个的最近公共祖先节点的值。
 *  (1) 给出基本设计思想
 *  (2) 根据设计思想，采用 c 或 c++ 语言描述算法，关键之处给出注释
 *  (3) 分析本算法的时间复杂度
 */

/**
 * 思路: 下标为 i 的双亲节点为 i/2
 *
 * @param tree
 * @param i
 * @param j
 * @return
 */
char findLastAncestor(char tree[], int i, int j){
    int p=i, q=j;
    while(p != q){
        if(p > q){
            p = p/2;
        }else{
            q = q/2;
        }
    }
    return tree[p];
}

void test08(){
    char tree[10] = "012300678";
    cout << findLastAncestor(tree, 6,7)<< endl;
}

/*
 * 2. 已知二叉树的节点在先序遍历下的序列存储在一维数组 pre[l1,...,r1] 中，在中序遍历下的
 *    序列存储在一维数组 in[l2,...,r2] 中(其中l1，r2与l2，r2指示了数组中元素(类型为char)
 *    存储的下标范围)，假定二叉树中节点数据值互不相同。试写出 pre[l1,...,r1] 和 in[l2,...,r2]
 *    构造二叉树的算法。
 *  (1) 给出基本设计思想
 *  (2) 根据设计思想，采用 c 或 c++ 语言描述算法，关键之处给出注释
 *  (3) 分析本算法的时间复杂度
 */
BiTNode * constructBiTree(char pre[], char in[], int l1, int r1,  int l2, int r2){
    if(l1 > r1){
       return NULL;
    }
    int i,j;
    BiTNode *root;
    // 将当前子树根节点赋值给新申请的节点
    for(i=l2; i<=r2; i++){
        if(pre[l1]==in[i]){
            root = (BiTNode *) malloc(sizeof(BiTNode *));
            root->data = pre[l1];
            root->lchild = NULL;
            root->rchild = NULL;
            break;
        }
    }
    // 确定左子树在先序序列和中序序列中的位置
    root->lchild = constructBiTree(pre, in, l1+1, l1+i-l2, l2, i-1);
    // 确定右子树在先序序列和中序序列中的位置
    root->rchild = constructBiTree(pre, in, l1+i-l2+1, r1, i+1, r2);
    return root;
}
/* ================================= 真题仿造 ================================= */

/* ================================= 习题心选 ================================= */
/*
 * 1. 假设二叉树采用二叉链存储结构，设计一个算法，计算一棵给定二叉树的所有节点数。
 */
int  COUNT = 0;
void count(BiTNode *root){
    if(root!=NULL){
        COUNT ++;
        // 统计左子树
        count(root->lchild);
        // 统计右子树
        count(root->rchild);
    }
}

/*
 * 2. 假设二叉树采用二叉链存储结构，设计一个算法，计算一棵给定二叉树的所有叶子节点数。
 */

// 解法 1
int  COUNT_1 = 0;
void count_1(BiTNode *root){
    if(root!=NULL){
        if(root->lchild==NULL && root->rchild==NULL){
            COUNT_1 ++;
        }
        // 统计左子树
        count_1(root->lchild);
        // 统计右子树
        count_1(root->rchild);
    }
}

// 解法 2
int count_2(BiTNode *root){
    if(root==NULL){ // 树空，返回 0
        return 0;
    } else if(root->lchild==NULL && root->rchild==NULL){ // 叶子节点，返回 1
       return 1;
    } else{
        int n1 = count_2(root->lchild); // 求出左子树叶子节点数
        int n2 = count_2(root->rchild); // 求出右子树叶子节点数
        return n1+n2;
    }
}

/*
 * 3. 假设二叉树采用二叉链存储结构，设计一个算法，利用节点的右孩子指针 rchild 将一棵二叉树
 *   的叶子节点按照从左往右的顺序串成一个单链表(在题目中定义两个指针，head与tail，其中，head
 *   指向第一个叶子节点，head 初值为 NULL，tail 指向最后一个叶子节点)
 */
void link(BiTNode *root, BiTNode *&head, BiTNode *&tail){
    if(root!=NULL){
        if(root->lchild==NULL && root->rchild==NULL){
            if(head == NULL){
                head = root;
                tail = root;
            }else{
                tail->rchild = root;
                tail = root;
            }
        }
        link(root->lchild, head, tail);
        link(root->rchild, head, tail);
    }
}

void test09(){
    BiTNode *root, *head, *tail;
    char *eles = (char *)"123##4##5##";
    init(root, eles);

    link(root, head, tail);
    while(head!=NULL){
        cout<<head->data<<'\t';
        head = head->rchild;
    }
    cout<<endl;
}

/* ================================= 习题心选 ================================= */
/*
 * 5. 在二叉树的二叉链存储结构中，增加一个纸箱双亲节点的 parent 指针，设计一个算法，给这个指针
 *    赋值，并输出所有节点的路径。
 */
void initParent(BiTNode *p, BiTNode *pre){
    if(p!=NULL){
        p->parent = pre;    // 根赋值
        pre = p;
        initParent(p->lchild, pre); // 左子树赋值
        initParent(p->rchild, pre); // 右子树赋值
    }
}

void printPath(BiTNode *p){
    while(p!=NULL){
        cout<< p->data<<"->";
        p=p->parent;
    }
    cout<<"NULL"<<endl;
}

void printAll(BiTNode *p){
    if(p!=NULL){
        printPath(p);
        printAll(p->lchild); // 输出左子树所有路径
        printAll(p->rchild); // 输出右子树所有路径
    }
}

void test10(){
    BiTNode *root;
    char *eles = (char *)"123##4##5##";
    init(root, eles);

    initParent(root, NULL);
    printAll(root);
    cout<<endl;
}

/*
 * 6. 假设满二叉树 b 先序遍历序列已经存在数组中，长度为 n ，设计一个算法将其转换为后序遍历序列
 */
void change(char pre[], int l1, int r1, char post[], int l2, int r2){
    if(l1<=r1){
        // 将根放于末尾
        post[r2] = pre[l1];

        // 改变左子树部分
        change(pre, l1+1, (l1+1+r1)/2, post, l2, (l2+r2-1)/2);
        // 改变左子树部分
        change(pre, (l1+1+r1)/2+1, r1, post, (l2+r2-1)/2+1, r2-1);
    }
}

void test11(){
    int n=7;
    char pre[7] = {'1','2','3','4','5','6','7'};
    char post[7];
    change(pre, 0, n-1, post, 0, n-1);

    int i=0,j=0;
    while(j<n){
        cout<< pre[j]<<" ";
        j++;
    }
    cout<< endl;

    while(i<n){
        cout<< post[i]<<" ";
        i++;
    }
    cout<< endl;
}

/*
 * 7. 假设二叉树采用二叉链存储结构，设计一个算法，求二叉树 b 中值为 x 的节点的层号。
 */
int LNO=1;
void findX(BiTNode *p, char x){
    if(p!=NULL){
        if(p->data == x){
            cout << x << ", 层号:"<<LNO<< endl;
        }
        // 进入左右子树，层号+1
        ++LNO;
        findX(p->lchild, x);
        findX(p->rchild, x);
        --LNO;
        // 返回上一层，层号-1
    }
}

void test12(){
    BiTNode *root;
    char *eles = (char *)"323##4##3##";
    init(root, eles);
    findX(root, '3');
}

/*
 * 10. 二叉树的双序遍历是指，对于二叉树的每一个接单来说，先访问这个节点，再按双序遍历遍历
 *   它的左子树，然后再一次访问这个节点，接下来按双序遍历遍历它的右子树。试写出执行这种双
 *   序遍历的算法。
 */
void doubleOrder(BiTNode *p){
    if(p!=NULL){
        cout<<p->data<<endl;
        doubleOrder(p->lchild);
        cout<<p->data<<endl;
        doubleOrder(p->rchild);
    }
}

/*
 * 11. 设中序索引二叉树的类型为 TBTNode *inThrTree:
 *   (1) 设计算法，在一棵中序索引树中寻找节点 t 的子树上中序下的最后一个节点。
 *   (2) 设计算法，在一棵中序索引树中寻找节点 t 的中序下的前驱。
 *   (3) 设计算法，在一棵中序索引树中寻找节点 t 的前序下的后继。
 */

/* ================================= 习题心选 ================================= */


/* =================================  思考题  ================================= */
/*
 * 1. 假设二叉树采用二叉链存储结构，设计一个算法，输出根节点到每个叶子节点的路径。
 */
int top=-1;
int i=0;
BiTNode* stack[100];
void printAllLeafPath(BiTNode *p){
    if(p!=NULL){
        stack[++top] = p;
        // 如果是叶子节点，则打印路径
        if(p->lchild==NULL && p->rchild==NULL){
            for(i=0; i<=top; i++){
                cout<<stack[i]->data<<" -> ";
            }
            cout<<"NULL"<<endl;
        }
        printAllLeafPath(p->lchild);
        printAllLeafPath(p->rchild);
        top--;
    }
}

void test13(){
    BiTNode *root;
    char *eles = (char *)"123##4##58##9##";
    init(root, eles);
    printAllLeafPath(root);
}

/* =================================  思考题  ================================= */
int main(){
    // test01();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    // test08();
    // test09();
    // test10();
    // test11();
    // test12();
    test13();
}