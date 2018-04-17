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

int main(){
    // test01();
    // test03();
    test04();
}