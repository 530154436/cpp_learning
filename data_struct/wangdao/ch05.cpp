//
// Created by 郑楚彬 on 2020/8/27.
//
#include <iomanip>
#include "ch05_tree/BiTree.hpp"
#include "ch05_tree/BinarySearchTree.hpp"
#include "ch05_tree/exercises.hpp"
#include "templates/util.hpp"

void bt_travel(){
    string str = "12#46##7##3#5##";
    const char* elems = str.data();
    BiTree root;
    Create(root, elems);    // 构建二叉树

    std::cout <<"先序遍历: "; // 1 2 4 6 3 5
    PreOrder(root);
    std::cout << std::endl;

    std::cout <<"中序遍历: "; // 2 6 4 1 3 5
    InOrder(root);
    std::cout << std::endl;

    std::cout <<"后序遍历: "; // 6 4 2 5 3 1
    PostOrder(root);
    std::cout << std::endl;

    std::cout <<"先序遍历(非递归): "; // 1 2 4 6 3 5
    PreOrder2(root);
    std::cout << std::endl;

    std::cout <<"中序遍历(非递归): "; // 2 6 4 1 3 5
    InOrder2(root);
    std::cout << std::endl;

    std::cout <<"后序遍历(非递归): "; // 6 4 2 5 3 1
    PostOrder2(root);
    std::cout << std::endl;

    std::cout <<"层次遍历: "; // 1 2 3 4 5 6
    LevelOrder(root);
    std::cout << std::endl;
}

void exercise_5_3(){
    // 缩进
    int indent = 85;
    string str = "12#46##7##3#5##";
    const char* elems = str.data();    // 构建二叉树
    BiTree root;
    Create(root, elems);


    std::cout<<std::left<<std::setw(indent)<<"4. 二又树自下而上、从右到左的层次遍历算法: ";
    InvertLevel(root);
    std::cout << std::endl;

    std::cout<<"5. 求二又树的高度:"<<std::endl;
    std::cout<<std::setw(indent-6)<<"   非递归算法:"; std::cout<< Btdepth(root) << std::endl;
    std::cout<<std::setw(indent-6)<<"   递归算法:"; std::cout<< BtdepthR(root) << std::endl;

    std::cout<<"6. 根据先序遍历序列和中序遍历序列建立二叉链表 (二叉树中各结点的值互不相同): "<<std::endl;
    std::cout<<std::left<<std::setw(indent-20)<<"   12#46##7##3#5##";
    ElemType A[7] = {'1','2','4','6','7','3','5'};
    ElemType B[7] = {'2','6','4','7','1','3','5'};
    BiTNode* root1 = BiTreePreinCreate(A, 0, 6, B, 0, 6);
    LevelOrder(root1); std::cout << std::endl;  // 1234567

    std::cout<<std::left<<std::setw(indent)<<"7. 判别二叉树是否为完全二叉树: ";
    std::cout<< IsComplete(root) << std::endl;

    std::cout<<std::left<<std::setw(indent)<<"8. 计算一棵给定二叉树的所有双分支结点个数: ";
    std::cout<< DsonNodes(root) << "==";
    std::cout<< DsonNodes1(root) << std::endl;

    std::cout<<"9. 交换二叉树中所有结点的左、右子树:"<<std::endl;
    std::cout<<std::setw(indent-6)<<"   交换前(层次遍历):";LevelOrder(root);std::cout << std::endl;
    swap(root);
    std::cout<<std::setw(indent-6)<<"   交换后(层次遍历):";LevelOrder(root);std::cout << std::endl;

    // 新建一棵树(第9题改变了树的结构)
    elems = str.data(); Create(root, elems);
    std::cout<<std::left<<std::setw(indent)<<"10.求先序遍历序列中第 k(1<=k<=二又树中结点个数)(5)个结点的值: ";
    std::cout<< PreNode(root, 5) << std::endl;

    std::cout<<std::left<<std::setw(indent)<<"11.对于树中每个元素值为 x(3) 的结点，删去以它为根的子树，并释放相应的空间: ";
    SearchDeleteXTree(root, '3');
    std::cout << std::endl;

    // 新建一棵树(第11题改变了树的结构)
    elems = str.data(); Create(root, elems);
    std::cout<<"12.打印值为 x 的结点的所有祖先，假设值为 x 的结点不多于一个: "<<std::endl;
    std::cout<<std::setw(indent-6)<<"   递归算法(x=7):"; SearchR(root, '7'); std::cout<< std::endl;
    std::cout<<std::setw(indent-6)<<"   非递归算法(x=7):"; Search(root, '7'); std::cout<< std::endl;

    std::cout<<"13.找到 p 和 q的最近公共祖先结点 r: "<<std::endl;
    std::cout<<std::setw(indent-6)<<"   递归算法(p=6,q=7):";
    std::cout<<AncestorR(root, root->lchild->rchild->lchild, root->lchild->rchild->rchild)->data<<std::endl;
    std::cout<<std::setw(indent-6)<<"   递归算法(p=6,q=7):";
    std::cout<<Ancestor(root, root->lchild->rchild->lchild, root->lchild->rchild->rchild)->data<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"14.求非空二又树 b 的宽度(即具有结点数最多的那一层的结点个数): ";
    std::cout<< BTWidth(root) << std::endl;

    std::cout<<"15.满二叉树(所有结点值均不同)，已知先序序列 pre，求后序序列 post: "<<std::endl;
    ElemType pre[7] = {'1','2','4','5','3','6','7'};
    ElemType post[7] = {'0','0','0','0','0','0','0'};
    PreToPost(pre, 0, 6, post, 0, 6);
    std::cout<<std::setw(indent-6)<<"   前序序列:"; display<char>(pre, 7); std::cout<< std::endl;
    std::cout<<std::setw(indent-6)<<"   后序序列:"; display<char>(post, 7); std::cout<< std::endl;

    std::cout<<std::left<<std::setw(indent)<<"16.二叉树的叶结点按从左到右的顺序连成一个单链表: "<<std::endl;
    std::cout<<std::left<<std::setw(indent-20)<<"   12#46##7##3#5##"; LeafToLinikedList(root);std::cout<<std::endl;
    str = "12##345##6##78##9##";
    elems = str.data();
    Create(root, elems);
    std::cout<<std::left<<std::setw(indent-20)<<"   12##345##6##78##9##"; LeafToLinikedList(root);std::cout<<std::endl;
    str = "136##45##2##78##9##";
    elems = str.data();    // 构建二叉树
    Create(root, elems);
    std::cout<<std::left<<std::setw(indent-20)<<"   136##45##2##78##9##"; LeafToLinikedList(root);std::cout<<std::endl;

    // 新建一棵树(第16题改变了树的结构)
    str = "12#46##7##3#5##"; elems = str.data(); Create(root, elems);
    std::cout<<std::left<<std::setw(indent)<<"19. 二又树的带权路径长度: ";
    std::cout<< wpl(root) << std::endl;

    // 新建一棵树(第19题改变了树的结构)
    str = "*+a##b##*c##-#d##"; elems = str.data(); Create(root, elems);
    std::cout<<"20. 给定的表达式树(二叉树)转换为等价的中缀表达式: "<<std::endl;
    std::cout<<std::left<<std::setw(indent-20)<<"   *+a##b##*c##-#d##";
    BtreeToExp(root, 1); std::cout<< std::endl;
}

void exercise_5_4(){
    CSTree T;
    int indent = 60;
    ElemType e[] = {'A','B','C','D','E','F','G'};
    int degree[] = {3, 2, 0, 1, 0, 0, 0};
    std::cout<<"7. 己知一棵树的层次序列及每个结点的度，编写算法构造此树的孩子兄弟链表。"<<std::endl;
    createCSTree_Degree(T, e, degree, 7);

    std::cout<<std::left<<std::setw(indent)<<"5. 编程求以孩子兄弟表示法存储的森林的叶子结点数: "<<leaves(T)<<std::endl;
    std::cout<<std::left<<std::setw(indent)<<"6. 以孩子兄弟链表为存储结构，请设计递归算法求树的深度: "<<Height(T)<<std::endl;
}

void exercise_5_5(){
    BSTree T=NULL;
    int n=5, indent=60;
    int elems[5] = {54, 20, 66, 40, 79};

    std::cout<<std::left<<std::setw(indent)<<"构造二叉排序树:";
    BST_Create(T, elems, n);
    display<BSTree>(T);

    std::cout<<std::left<<std::setw(indent)<<"二叉排序树插入28:";
    BST_Insert(T, 28);
    display<BSTree>(T);

    std::cout<<std::left<<std::setw(indent)<<"查询二叉排序树 33:"; std::cout<<BST_SearchR(T, 33); std::cout<<std::endl;
    std::cout<<std::left<<std::setw(indent)<<"查询二叉排序树 66:"; std::cout<<BST_Search(T, 66); std::cout<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"6. 试编写一个算法，判断给定的二叉树是否是二叉排序树:";
    std::cout<<JudgeBST(T); std::cout<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"7. 设计一个算法，求出在指定结点给定二叉排序树中的层次(P=40):";
    std::cout<<level(T, T->lchild->rchild); std::cout<<std::endl;

    int depth;
    std::cout<<std::left<<std::setw(indent)<<"8. 利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法:";
    std::cout<<Judge_AVL(T, depth); std::cout<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"9. 设计一个算法，求出给定二叉排序树中最小和最大的关键字:";
    std::cout<<"minVal="<<MinBST(T)<<", "<<"maxVal="<<MaxBST(T); std::cout<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"10.设计一个算法 ，从大到小输出二叉排序树中所有值不小于 k 的关键字:";
    OutPut(T, 40); std::cout<<std::endl;

    std::cout<<std::left<<std::setw(indent)<<"12. 二叉排序树上查找第 k (1<=k<=n) 小的元素，并返回指向该结点的指针(k=4):";
    BSTNode* p = Search_Small(T, 4);
    std::cout<<p->data<<std::endl;
}

int main(){
    bt_travel();        // 二叉树的遍历
    exercise_5_3();     // 二叉树
    exercise_5_4();     // 树、森林 (孩子兄弟链表)
    exercise_5_5();     // 二叉搜索树、平衡树
    return 0;
}