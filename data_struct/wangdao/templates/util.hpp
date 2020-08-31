//
// Created by 郑楚彬 on 2020/8/30.
//
#ifndef TIANQINDATASTRUCT_UTIL_HPP
#define TIANQINDATASTRUCT_UTIL_HPP

#include <iostream>
using namespace std;

template <typename ElemType >
void display(ElemType a[], int n){
    for(int i=0; i<n; i++)
        std::cout<<a[i]<<' ';
}

#endif //TIANQINDATASTRUCT_UTIL_HPP
