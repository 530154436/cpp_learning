cmake_minimum_required(VERSION 3.9)
project(TianqinDatastruct)

set(CMAKE_CXX_STANDARD 11)

# (天勤数据结构)数据结构
add_executable(sqList "data_struct/2.线性表/2.1. 顺序表.cpp" data_struct/utility/LinearTable/SqList.h)
add_executable(linkedList "data_struct/2.线性表/2.2. 单链表.cpp" data_struct/utility/LinearTable/LinkedList.h)
add_executable(dLinkedList "data_struct/2.线性表/2.3. 双链表.cpp" data_struct/utility/LinearTable/DLinkedLIst.h data_struct/utility/Printer.h data_struct/utility/Tree/BiTree.h "data_struct/6. 树和二叉树/6.1 二叉树.cpp")
add_executable(linerExercise "data_struct/2.线性表/2.4. 习题集.cpp")
add_executable(stackExercise "data_struct/3. 栈和队列/3.1 栈和队列的应用.cpp" data_struct/utility/Stack/SqStack.h data_struct/utility/Stack/LinkedStack.h data_struct/utility/Printer.h data_struct/utility/Stack/SharedStack.h data_struct/utility/Queue/LinkedQueue.h data_struct/utility/Queue/SqQueue.h)
add_executable(biTreeExercise "data_struct/6. 树和二叉树/6.1 二叉树.cpp" data_struct/utility/Tree/ThreadBiTree.h data_struct/utility/Search/BinarySortTree.h data_struct/utility/Search/BalancedBinarySortTree.h leetcode/ds0_array/lc167.hpp)
add_executable(graphExercise "data_struct/7. 图/7.1 图的遍历算法操作.cpp" data_struct/utility/Graph/MGraph.h data_struct/utility/Graph/AGraph.h data_struct/utility/Graph/algorithm.h "data_struct/7. 图/7.2 图的应用.cpp" )
add_executable(sortExercise "data_struct/8.内部排序/8. 排序练习.cpp" data_struct/utility/Sort/Sorting.h)
add_executable(searchExercise "data_struct/9. 查找/9. 查找练习.cpp" data_struct/utility/Search/Search.h data_struct/utility/Search/BalancedBinarySortTree.h data_struct/utility/Search/BTree.h)

# Essential C++
add_executable(esesential_cpp essential_cpp/main.cpp essential_cpp/exercises.hpp essential_cpp/util.cpp
        essential_cpp/chapter01.cpp essential_cpp/chapter02.cpp essential_cpp/chapter03.cpp)

# sword means offer ==> smo 、 leetcode ==> lc

# 数据结构0 数组
file(GLOB ARRAY "leetcode/ds0_array/*.hpp")
add_executable(ds0_array leetcode/lib.hpp leetcode/ds0_array.cpp ${ARRAY} )

# 数据结构1 字符串
file(GLOB STRING "leetcode/ds1_string/*.hpp")
add_executable(ds1_string leetcode/lib.hpp leetcode/ds1_string.cpp ${STRING})

# 数据结构2 链表
file(GLOB LL "leetcode/ds2_linked_list/*.hpp")
add_executable(ds2_linked_list leetcode/lib.hpp leetcode/ds2_linked_list.cpp ${LL})

# 数据结构3 栈
file(GLOB STACK "leetcode/ds3_stack/*.hpp")
add_executable(ds3_stack leetcode/lib.hpp leetcode/ds3_stack.cpp  ${STACK})

# 数据结构4 队列
file(GLOB QUEUE "leetcode/ds4_queue/*.hpp")
add_executable(ds4_queue leetcode/lib.hpp leetcode/ds4_queue.cpp ${QUEUE})

# 数据结构5 树
file(GLOB TREE "leetcode/ds5_tree/*.hpp")
add_executable(ds5_tree leetcode/lib.hpp leetcode/ds5_tree.cpp ${TREE})

# 数据结构6 堆(优先队列)
file(GLOB HEAP "leetcode/ds6_heap/*.hpp")
add_executable(ds6_heap leetcode/lib.hpp leetcode/ds6_heap.cpp ${HEAP})

# 算法 递归
file(GLOB RECURSION "leetcode/alg_recursion/*.hpp")
add_executable(alg_recursion leetcode/lib.hpp leetcode/alg_recursion.cpp  ${RECURSION} )

# 算法 位运算
file(GLOB BITWISE "leetcode/alg_bitwise/*.hpp")
add_executable(alg_bitwise leetcode/lib.hpp leetcode/alg_bitwise.cpp  ${BITWISE} )

# 算法 动态规划+贪心算法
file(GLOB ALG_DP_GREEDY "leetcode/alg_dp_greedy/*.hpp")
add_executable(alg_dp_greedy leetcode/lib.hpp leetcode/alg_dp_greedy.cpp  ${ALG_DP_GREEDY} )

# 算法 数学+找规律+智力题
file(GLOB ALG_MATH "leetcode/alg_math/*.hpp")
add_executable(alg_math leetcode/lib.hpp leetcode/alg_math.cpp  ${ALG_MATH} )
