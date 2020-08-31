//
// Created by 郑楚彬 on 2020/8/27.
//
#include <iomanip>
#include "ch05_tree/BiTree.hpp"
#include "ch05_tree/exercises.hpp"
#include "templates/util.hpp"

void travel(){
    string str = "12#46##7##3#5##";
    const char* elems = str.data();    // 构建二叉树
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
    BiTNode* root1 = BiTreePreinCreat(A, 0, 6, B, 0, 6);
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
    std::cout<<std::left<<std::setw(indent)<<"20. 给定的表达式树(二叉树)转换为等价的中缀表达式: ";
    BtreeToExp(root, 1); std::cout<< std::endl;
}

int main(){
    //travel();
    exercise_5_3();
    return 0;
}















