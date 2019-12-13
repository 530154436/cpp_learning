[TOC]
#### 1. 关键字
1. **using namespace std;**
`std`: 是标准库(string class、iostream::cin/cout)命名空间的名称。
`namespace`: 一种将库名称封装起来的方法。
`using` directive: 让命名空间中的名称曝光的方法。
`char`: 表示(character)类型，如'a'、'\n'、'\t'、'\0'、'\\'、'\''、'\"'。
`const`: 常量，获得初值之后，无法再有任何变动。

+ `main()`: 并非是程序语言定义的关键字。

#### 2. 易混淆概念
1. **#include<xxx.h> 和 #include "xxx.h" 的区别**
`#include<xxx.h>`: 用于标准或系统提供的头文件，到保存系统标准头文件的位置查找头文件。
`#include "xxx.h"`: 常用于程序员自己的头文件。用这种格式时，C编译器先查找当前目录是否有指定名称的头文件，然后在从标准头文件目录中查找。

#### 3. 出现的问题
1. **ld: 1 duplicate symbol for architecture x86_64**
出现错误的原因是：重复定义。