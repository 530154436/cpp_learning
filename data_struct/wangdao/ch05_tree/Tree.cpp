//
// Created by Edward on 2020/8/31.
//

#include "Tree.hpp"

/**
 * 打印节点的孩子、兄弟
 * @param node
 */
void display(CSNode *node){
    std::cout<<node->data<<": (";
    if(node->firstChild!=NULL)
        std::cout<<node->firstChild->data<<", ";
    else
        std::cout<<"NULL, ";
    CSNode* sibling = node->nextSibling;
    while(sibling){
        std::cout<<sibling->data<<"->";
        sibling = sibling->nextSibling;
    }
    std::cout<<"NULL)"<<std::endl;
}
