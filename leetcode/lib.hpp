//#ifendif防止多次包含一个文件
#ifndef EXERCISES_H
#define EXERCISES_H

#include <stack>
#include <utility>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

template <typename T>
void display(std::vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        std::cout<<vec[i]<<' ';
    }
    std::cout<<std::endl;
};

void display(std::vector<pair<int,int>> &vec){
    for(int i=0; i<vec.size(); i++){
        std::cout<<vec[i].first<<':'<<vec[i].second<<' ';
    }
    std::cout<<std::endl;
};

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void swap(TreeNode* &a, TreeNode* &b){
    TreeNode* tmp = a;
    a = b;
    b = tmp;
}

#endif     //防止文件被重复包含