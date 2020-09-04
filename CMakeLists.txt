cmake_minimum_required(VERSION 3.9)
project(TianqinDatastruct)

set(CMAKE_CXX_STANDARD 11)

# (天勤数据结构)数据结构
#add_executable(sqList "data_struct/tianqin/2.线性表/2.1. 顺序表.cpp" data_struct/tianqin/utility/LinearTable/SqList.h)
#add_executable(linkedList "data_struct/tianqin/2.线性表/2.2. 单链表.cpp" data_struct/tianqin/utility/LinearTable/LinkedList.h)
#add_executable(dLinkedList "data_struct/tianqin/2.线性表/2.3. 双链表.cpp" data_struct/tianqin/utility/LinearTable/DLinkedLIst.h data_struct/tianqin/utility/Printer.h data_struct/tianqin/utility/Tree/BiTree.h "data_struct/tianqin/6. 树和二叉树/6.1 二叉树.cpp")
#add_executable(linerExercise "data_struct/tianqin/2.线性表/2.4. 习题集.cpp")
#add_executable(stackExercise "data_struct/tianqin/3. 栈和队列/3.1 栈和队列的应用.cpp" data_struct/tianqin/utility/Stack/SqStack.h data_struct/tianqin/utility/Stack/LinkedStack.h data_struct/tianqin/utility/Printer.h data_struct/tianqin/utility/Stack/SharedStack.h data_struct/tianqin/utility/Queue/LinkedQueue.h data_struct/tianqin/utility/Queue/SqQueueTemplate.h)
#add_executable(biTreeExercise "data_struct/tianqin/6. 树和二叉树/6.1 二叉树.cpp" data_struct/tianqin/utility/Tree/ThreadBiTree.h data_struct/tianqin/utility/Search/BinarySortTree.h data_struct/tianqin/utility/Search/BalancedBinarySortTree.h leetcode/ds0_array/lc167.hpp)
#add_executable(graphExercise "data_struct/tianqin/7. 图/7.1 图的遍历算法操作.cpp" data_struct/tianqin/utility/Graph/MGraph.h data_struct/tianqin/utility/Graph/AGraph.h data_struct/tianqin/utility/Graph/algorithm.h "data_struct/tianqin/7. 图/7.2 图的应用.cpp" )
#add_executable(sortExercise "data_struct/tianqin/8.内部排序/8. 排序练习.cpp" data_struct/tianqin/utility/Sort/Sorting.h)
#add_executable(searchExercise "data_struct/tianqin/9. 查找/9. 查找练习.cpp" data_struct/tianqin/utility/Search/Search.h data_struct/tianqin/utility/Search/BalancedBinarySortTree.h data_struct/tianqin/utility/Search/BTree.h)

# 王道数据结构
file(GLOB WD_CH05_H "data_struct/wangdao/ch05_tree/*.hpp")
file(GLOB WD_CH05_C "data_struct/wangdao/ch05_tree/*.cpp")
file(GLOB WD_TEMP "data_struct/wangdao/templates/*.hpp")
add_executable(wd_ch05 "data_struct/wangdao/ch05.cpp" ${WD_CH05_H} ${WD_CH05_C} ${WD_TEMP})

file(GLOB WD_CH03_H "data_struct/wangdao/ch03_stack_queue/*.hpp")
file(GLOB WD_CH03_C "data_struct/wangdao/ch03_stack_queue/*.cpp")
add_executable(wd_ch03 "data_struct/wangdao/ch03.cpp" ${WD_CH03_H} ${WD_CH03_C})

file(GLOB WD_CH02_H "data_struct/wangdao/ch02_linear_table/*.hpp")
file(GLOB WD_CH02_C "data_struct/wangdao/ch02_linear_table/*.cpp")
add_executable(wd_ch02 "data_struct/wangdao/ch02.cpp" ${WD_CH02_H} ${WD_CH02_C})

## Essential C++
#add_executable(esesential_cpp essential_cpp/main.cpp essential_cpp/exercises.hpp essential_cpp/util.cpp
#        essential_cpp/chapter01.cpp essential_cpp/chapter02.cpp essential_cpp/chapter03.cpp)

# ------------------------------------------------------------------------------------------------
# 数据结构 + 算法
# ------------------------------------------------------------------------------------------------
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

# 算法 动态规划+贪心算法+回溯法
file(GLOB ALG_DP_GREEDY_BACKTRACKING "leetcode/alg_dp_greedy_backtracking/*.hpp")
add_executable(alg_dp_greedy_backtracking leetcode/lib.hpp leetcode/alg_dp_greedy_backtracking.cpp ${ALG_DP_GREEDY_BACKTRACKING} )

# 算法 数学+找规律+智力题
file(GLOB ALG_MATH "leetcode/alg_math/*.hpp")
add_executable(alg_math leetcode/lib.hpp leetcode/alg_math.cpp  ${ALG_MATH} )

# 算法 查找
file(GLOB SEARCH "leetcode/alg_search/*.hpp")
add_executable(alg_search leetcode/lib.hpp leetcode/alg_search.cpp  ${SEARCH} )

# ------------------------------------------------------------------------------------------------
# 深入理解计算机系统 (CSAPP)
# ------------------------------------------------------------------------------------------------

# 第1章
file(GLOB CH01 "csapp/ch01/*.hpp")
add_executable(csapp_ch01 csapp/ch01.cpp  ${CH01} )

# 第2章
file(GLOB CH02 "csapp/ch02/*.hpp")
add_executable(csapp_ch02 csapp/ch02.cpp  ${CH02} )

# 第3章
file(GLOB CH03 "csapp/ch03/*.hpp")
add_executable(csapp_ch03 csapp/ch03.cpp  ${CH03} )

# 第5章
file(GLOB CH05 "csapp/ch05/*.hpp")
add_executable(csapp_ch05 csapp/ch05.cpp  ${CH05} )
