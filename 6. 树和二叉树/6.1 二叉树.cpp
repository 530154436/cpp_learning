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
int test03(){
    BiTNode *root;
    char *eles = (char *)"ab#d##c#e##";
    init(root, eles);
    cout<< getDeepth(root)<< endl;
}


/*
 * 3. 查找值域等于key的节点
 */
int test04(){
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

int test05(){
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
                LNO++;
                rear++;
                queue[rear].p = q->lchild;
                queue[rear].lno = LNO+1;
            }

            if(q->rchild != NULL){
                // 右子树不为空，行数+1，并进队
                LNO++;
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
    }else{
        return 0; // 空树直接返回0
    }
}

int test06(){
    BiTNode *root, *tmp;
    char *eles = (char *)"ab#d##c#e##";
    init(root, eles);

    int max = maxNode(root);
    cout << max << endl;
}

int main(){
    // test01();
    // test03();
    // test04();
    // test05();
    test06();
}