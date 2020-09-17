//
// Created by 郑楚彬 on 2020/8/27.
//
#include <iomanip>
#include <iostream>
#include "templates/util.hpp"
#include "ch08_sort/sort.hpp"

int main(){
    int indent=70;
    int A[8] = {49,38,65,97,76,13,27,49};
    int B[8];

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"1. 直接插入排序 {49,38,65,97,76,13,27,49}: ";
    InsertSort(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"2. 折半插入排序 {49,38,65,97,76,13,27,49}: ";
    BinaryInsertSort(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent-3)<<"3. 希尔排序 {49,38,65,97,76,13,27,49}: ";
    ShellSort(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent-3)<<"4. 冒泡排序 {49,38,65,97,76,13,27,49}: ";
    BubbleSort(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent-3)<<"5. 快速排序 {49,38,65,97,76,13,27,49}: ";
    QuickSort(B, 0, 7); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent-3)<<"6. 选择排序 {49,38,65,97,76,13,27,49}: ";
    SelectSort(B, 8); display<int>(B, 8);

    int C[9]; // 数组下标从1开始
    std::copy(std::begin(A),std::end(A),std::begin(C)+1);
    std::cout<<std::left<<std::setw(indent-3)<<"7.  堆排序  {49,38,65,97,76,13,27,49}: ";
    HeapSort(C, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent-3)<<"8. 归并排序 {49,38,65,97,76,13,27,49}: ";
    MergeSort(B, 0, 7); display<int>(B, 8);
    
    return 0;
}