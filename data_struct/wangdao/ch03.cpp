//
// Created by 郑楚彬 on 2020/8/27.
//
#include <iostream>
#include "templates/SqQueueTemplate.hpp"

int main(){
    SqQueue<int> Q;
    InitQueue(Q);

    EnQueue(Q, 100);

    int x;
    GetHead(Q, x);
    std::cout<<x<<std::endl;
    return 0;
}