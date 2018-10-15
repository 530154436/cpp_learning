cmake_minimum_required(VERSION 3.9)
project(TianqinDatastruct)

set(CMAKE_CXX_STANDARD 11)

# 第一章
add_executable(sqList "2.线性表/2.1. 顺序表.cpp" utility/LinearTable/SqList.h)
add_executable(linkedList "2.线性表/2.2. 单链表.cpp" utility/LinearTable/LinkedList.h)
add_executable(dLinkedList "2.线性表/2.3. 双链表.cpp" utility/LinearTable/DLinkedLIst.h utility/Printer.h utility/Tree/BiTree.h "6. 树和二叉树/6.1 二叉树.cpp")
add_executable(linerExercise "2.线性表/2.4. 习题集.cpp")
add_executable(stackExercise "3. 栈和队列/3.1 栈和队列的应用.cpp" utility/Stack/SqStack.h utility/Stack/LinkedStack.h utility/Printer.h utility/Stack/SharedStack.h utility/Queue/LinkedQueue.h utility/Queue/SqQueue.h)
add_executable(biTreeExercise "6. 树和二叉树/6.1 二叉树.cpp" utility/Tree/ThreadBiTree.h utility/Search/BinarySortTree.h utility/Search/BalancedBinarySortTree.h)
add_executable(graphExercise "7. 图/7.1 图的遍历算法操作.cpp" utility/Graph/MGraph.h utility/Graph/AGraph.h utility/Graph/algorithm.h "7. 图/7.2 图的应用.cpp" )
add_executable(sortExercise "8.内部排序/8. 排序练习.cpp" utility/Sort/Sorting.h)
add_executable(searchExercise "9. 查找/9. 查找练习.cpp" utility/Search/Search.h utility/Search/BalancedBinarySortTree.h utility/Search/BTree.h)