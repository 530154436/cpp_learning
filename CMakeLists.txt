cmake_minimum_required(VERSION 3.9)
project(TianqinDatastruct)

set(CMAKE_CXX_STANDARD 11)

# (天勤数据结构)数据结构
add_executable(sqList "data_struct/2.线性表/2.1. 顺序表.cpp" data_struct/utility/LinearTable/SqList.h)
add_executable(linkedList "data_struct/2.线性表/2.2. 单链表.cpp" data_struct/utility/LinearTable/LinkedList.h)
add_executable(dLinkedList "data_struct/2.线性表/2.3. 双链表.cpp" data_struct/utility/LinearTable/DLinkedLIst.h data_struct/utility/Printer.h data_struct/utility/Tree/BiTree.h "data_struct/6. 树和二叉树/6.1 二叉树.cpp")
add_executable(linerExercise "data_struct/2.线性表/2.4. 习题集.cpp")
add_executable(stackExercise "data_struct/3. 栈和队列/3.1 栈和队列的应用.cpp" data_struct/utility/Stack/SqStack.h data_struct/utility/Stack/LinkedStack.h data_struct/utility/Printer.h data_struct/utility/Stack/SharedStack.h data_struct/utility/Queue/LinkedQueue.h data_struct/utility/Queue/SqQueue.h)
add_executable(biTreeExercise "data_struct/6. 树和二叉树/6.1 二叉树.cpp" data_struct/utility/Tree/ThreadBiTree.h data_struct/utility/Search/BinarySortTree.h data_struct/utility/Search/BalancedBinarySortTree.h)
add_executable(graphExercise "data_struct/7. 图/7.1 图的遍历算法操作.cpp" data_struct/utility/Graph/MGraph.h data_struct/utility/Graph/AGraph.h data_struct/utility/Graph/algorithm.h "data_struct/7. 图/7.2 图的应用.cpp" )
add_executable(sortExercise "data_struct/8.内部排序/8. 排序练习.cpp" data_struct/utility/Sort/Sorting.h)
add_executable(searchExercise "data_struct/9. 查找/9. 查找练习.cpp" data_struct/utility/Search/Search.h data_struct/utility/Search/BalancedBinarySortTree.h data_struct/utility/Search/BTree.h)

# Essential C++
add_executable(esesential_cpp essential_cpp/main.cpp essential_cpp/exercises.hpp essential_cpp/util.cpp
        essential_cpp/chapter01.cpp essential_cpp/chapter02.cpp )