```bash
g++ --version

g++ (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
├── README.md
├── ch02.cpp
├── ch02_linear_table
│   ├── LinkList.cpp
│   ├── LinkList.hpp
│   ├── SqList.cpp
│   ├── SqList.hpp
│   ├── exercises.cpp
│   └── exercises.hpp
├── ch03.cpp
├── ch03_stack_queue
│   ├── SqQueue.cpp
│   ├── SqQueue.hpp
│   ├── SqStack.cpp
│   ├── SqStack.hpp
│   └── exercises.hpp
├── ch05.cpp
├── ch05_tree
│   ├── BiTree.cpp
│   ├── BiTree.hpp
│   ├── BinarySearchTree.cpp
│   ├── BinarySearchTree.hpp
│   ├── ThreadTree.cpp
│   ├── ThreadTree.h
│   ├── Tree.cpp
│   ├── Tree.hpp
│   ├── exercises.cpp
│   └── exercises.hpp
└── templates
    ├── SqQueueTemplate.hpp
    ├── SqStackTemplate.hpp
    └── util.hpp

#### 2. 线性表
```bash
g++ -o ch02.o ch02.cpp ch02_linear_table/*.cpp
g++ -o ch05.o ch05.cpp ch05_tree/*.cpp
g++ -o ch08.o ch08.cpp ch08_sort/*.cpp -std=c++11
```

#### 参考
[1][C++之函数/结构体/类 模板](https://zhuanlan.zhihu.com/p/37669989)