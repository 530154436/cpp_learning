cmake_minimum_required(VERSION 3.9)
project(TianqinDatastruct)

set(CMAKE_CXX_STANDARD 11)

add_executable(sqList "2.线性表/2.1. 顺序表.cpp" utility/LinearTable/SqList.h)
add_executable(linkedList "2.线性表/2.2. 单链表.cpp" utility/LinearTable/LinkedList.h)
add_executable(dLinkedList "2.线性表/2.3. 双链表.cpp" utility/LinearTable/DLinkedLIst.h)
add_executable(linerExercise "2.线性表/2.4. 习题集.cpp")