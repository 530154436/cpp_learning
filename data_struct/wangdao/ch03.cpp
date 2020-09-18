//
// Created by Edward on 2020/8/27.
//
#include <iomanip>
#include <iostream>
#include "ch03_stack_queue/exercises.hpp"

int main(){
    int elems[5] = {54, 20, 66, 40, 79};

    LNode<char> *L1, *L2;
    char a[5]={'l', 'x', 'x', 'x', 'l'};      List_TailInsert(L1, a, 5);
    char b[6]={'l', 'x', 'x', 'x', 'y', 'l'}; List_TailInsert(L2, b, 5);

    int indent=90;
    std::cout<<std::left<<std::setw(indent)<<"4. 判断链表的全部 n 个字符是否中心对称: ";
    std::cout<<"lxxxl => "<<dc(L1, 5)<<", lxxxyl => "<<dc(L2, 6)<<std::endl;


    std::cout<<std::left<<std::setw(indent-5)<<"3. 利用两个栈 S1, S2 来模拟一个队列: ";
    int x;
    SSQueue q; InitStack(q.S1); InitStack(q.S2);
    std::cout<<"EnSSQueue(q, 1)="<<EnSSQueue(q, 1)<<",DeSSQueue(q, x)="<<DeSSQueue(q, x)<<std::endl;


    std::cout<<std::left<<std::setw(indent-5)<<"1. 判别表达式中的括号是否配对: ";
    char ch1[6]={'(',')','{','}','[',']'};
    char ch2[6]={'(','{','[',']','}',')'};
    std::cout<<"(){}[] => "<<BracketsCheck(ch1)<<", ({[]}) => "<<BracketsCheck(ch2)<<std::endl;


    std::cout<<std::left<<std::setw(indent-5)<<"2. 利用一个找实现递归函数的非递归计算: p(n=3, x=2)=";
    std::cout<<p(3, 2)<<std::endl;


    std::cout<<std::left<<std::setw(indent-5)<<"*. 设计一个栈，使它可以在O(1)的时间复杂度内实用 Push、 Pop 和 min 操作: ";
    MinStack s; InitStack(s.s); InitStack(s.min_stack);
    std::cout<<"Push(5),Push(2),Push(3),Pop(),Pop() => min=";
    Push(s, 5); min(s,x); std::cout<<x<<",";
    Push(s, 2); min(s,x); std::cout<<x<<",";
    Push(s, 3); min(s,x); std::cout<<x<<",";
    Pop(s, x); min(s,x); std::cout<<x<<",";
    Pop(s, x); min(s,x); std::cout<<x<<std::endl;

    return 0;
}