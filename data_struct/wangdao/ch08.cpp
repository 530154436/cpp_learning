//
// Created by Edward on 2020/8/27.
//
#include <iomanip>
#include <iostream>
#include <iterator>
#include "templates/util.hpp"
#include "ch08_sort/exercises.hpp"

using namespace std;

void sort(){
    int indent=70;
    int A[8] = {49,38,65,97,76,13,27,49};
    int B[8];

    std::cout<<std::left<<std::setw(indent)<<"原始数组:"; display<int>(A, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"1. 直接插入排序: ";
    InsertSort(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"2. 折半插入排序: ";
    BinaryInsertSort(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent-3)<<"3. 希尔排序: ";
    ShellSort(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"4. 冒泡排序 (从后往前): ";
    BubbleSort1(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"   冒泡排序 (从前往后): ";
    BubbleSort2(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent-3)<<"5. 快速排序: ";
    QuickSort(B, 0, 7); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent-3)<<"6. 选择排序: ";
    SelectSort(B, 8); display<int>(B, 8);

    int C[9]; // 数组下标从1开始
    std::copy(std::begin(A),std::end(A),std::begin(C)+1);
    std::cout<<std::left<<std::setw(indent-3)<<"7. 堆排序: ";
    HeapSort(C, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent-3)<<"8. 归并排序: ";
    MergeSort(B, 0, 7); display<int>(B, 8);
}

void exercise_8_3(){
    int indent=70;
    int A[8] = {49,38,65,97,76,13,27,49};
    int B[8];
    std::cout<<std::left<<std::setw(indent)<<"原始数组:"; display<int>(A, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"2. 双向冒泡排序算法:";
    BubbleSort(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"3. 把所有奇数移动到所有偶数前边的算法1:";
    move(B, 8); display<int>(B, 8);
    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"   把所有奇数移动到所有偶数前边的算法2:";
    move2(B, 8); display<int>(B, 8);

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"5. 数组中找出第 k=2、6 小的元素:";
    std::cout<<kth_elem(B,0,7,1)<<"、";
    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<kth_elem(B,0,7,5)<<std::endl;

    std::copy(std::begin(A),std::end(A),std::begin(B));
    std::cout<<std::left<<std::setw(indent)<<"6. 将A划分为两个不相交的子集:";
    std::cout<<setPartition(B, 8)<<std::endl;

    int C[8] = {0,1,2,1,2,0,2,1};
    std::cout<<std::left<<std::setw(indent)<<"7. 荷兰国旗问题 {0,1,2,1,2,0,2,1}:";
    Flag_A_rrange(C, 8); display<int>(C, 8);
}

void exercise_8_4_8_6(){
    int indent=70;
    LNode<int>* L1;
    int a[10]={7, 8, 4, 11, 12, 4, 4, 6, 8, 10}; List_TailInsert(L1, a, 10);
    std::cout<<std::left<<std::setw(indent)<<"原始链表:"; display<int>(L1);

    std::cout<<std::left<<std::setw(indent+28)<<"4. 在基于单链表表示的待排序关键字序列上进行简单选择排序:";
    selectSort(L1->next);  display<int>(L1);

    int A[9] = {10,11,23,34,1,2,5,18,20};
    std::cout<<std::left<<std::setw(indent+28)<<"2. 前m个元素递增有序，后n个元素递增有序，设计一个算法，使得整个顺序表有序:"<<std::endl;
    std::cout<<std::left<<std::setw(indent)<<"   {10,11,23,34,1,2,5,18,20}:";
    Insert_Sort(A, 4, 5);
    display<int>(A, 9);

    int B[9] = {10,11,23,34,1,2,5,18,20};
    std::cout<<std::left<<std::setw(indent+28)<<"4. 数组{K_1,K_2，...，K_n}, 将 K_n，放在将元素排序后的正确位置上:"<<std::endl;
    std::cout<<std::left<<std::setw(indent)<<"   {10,11,23,34,1,2,5,18,20}:";
    PartitionN(B, 9); display<int>(B, 9);

    int C[8] = {0,1,2,3,4,5,6,7};
    int D[7] = {0,1,2,3,4,5,6};
    std::cout<<std::left<<std::setw(indent+28)<<"5. 判断一个数据序列是否构成一个小根堆:"<<std::endl;
    std::cout<<std::left<<std::setw(indent)<<"   {0,1,2,3,4,5,6,7}"; std::cout<<IsMinHeap(C, 7)<<std::endl;
    std::cout<<std::left<<std::setw(indent)<<"   {0,1,2,3,4,5,6,7}"; std::cout<<IsMinHeap(D, 6)<<std::endl;
}

int main(){
    //sort();
    //exercise_8_3();
    exercise_8_4_8_6();
    
    return 0;
}