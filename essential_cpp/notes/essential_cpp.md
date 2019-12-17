[TOC]
#### 1. 关键字
1. **using namespace std;**
`std`: 是标准库(string class、iostream::cin/cout)命名空间的名称。
`namespace`: 一种将库名称封装起来的方法。
`using` directive: 让命名空间中的名称曝光的方法。
`char`: 表示(character)类型，如'a'、'\n'、'\t'、'\0'、'\\'、'\''、'\"'。
`const`: 常量，获得初值之后，无法再有任何变动。
`&`: 取址运算符，如 int value=1024; int* pi = &value(value的内存地址)
`*`: 取位于指针所指内存地址上的对象: \*pi==1024(读value值); \*pi=2048(写值至value，`value值改变`)

+ `main()`: 并非是程序语言定义的关键字。

#### 2. 易混淆概念
1. **#include<xxx.h> 和 #include "xxx.h" 的区别**
`#include<xxx.h>`: 用于标准或系统提供的头文件，到保存系统标准头文件的位置查找头文件。
`#include "xxx.h"`: 常用于程序员自己的头文件。用这种格式时，C编译器先查找当前目录是否有指定名称的头文件，然后在从标准头文件目录中查找。

2. **指针的双重性质**
null指针: 一个未指向任何对象的指针，其地址值为0。int *p=0。
既可以让我们操作指针包含的内存地址，也可以让我们操作所指的对象值。(int \*p=&val;)
p;   => 计算p所持有的内存地址，即val的内存地址
\*p; => 求val的值

注: 使用指针之前需要检查指针是否非空。`.`为dot成员选择运算符，如果用指针，则需要改成arrow成员选择运算符`->``

3. **char\*、char ch[]和string区别**
> https://haoqchen.site/2018/09/09/string-and-char/
https://www.cnblogs.com/zhuluqing/p/8761640.html

    + 字符串指针 char* ch="hello";
    "hello"是字符串常量，不可改变，即通过ch[0]="s"会编译出错。
    ch保存“hello"这个字符串常量的首地址。

    + 字符数组 char ch[]="hello";
    字符串以字符数组的形式保存,以”\0”结尾,数组内元素可以改变。

    + 字符串 string ch
    string 由C++提供的字符串类,封装了字符串操作,比C语言的char*操作起来更安全;

4. **array和vector的区别**
(1) array的大小必须固定，vector可以动态的随着元素的插入而扩展空间。
(2) array并不存储自身大小。

5. **函数调用**
当我们调用一个函数时，会在内存中建立一块特殊区域，称为"程序堆栈"。这块特殊区域提供了`每个函数参数的存储空间`。
它也提供了函数所定义的每个对象的内存空间，这些对象称为`局部对象`。一旦函数完成，这块内存就会被释放掉，即从程序堆栈中被pop出来。
通常，函数声明会被放在`头文件`，每个打算使用该函数的文件，都会包含对应的头文件。
头文件只被编译一次，当我们想要使用该函数时，会将它链接(link)到我们的程序。

6. **局部静态对象**
在局部变量之前加上关键字static，局部变量就被定义成为一个局部静态变量。
(1) 内存中的位置：`静态存储区`
(2) 初始化：未经初始化的全局静态变量会被程序自动初始化为0（自动对象的值是任意的，除非他被显示初始化）
(3) 作用域：作用域仍为局部作用域，当定义它的函数或者语句块结束的时候，作用域随之结束。
[`注`] 和局部非静态对象不同的是，局部静态对象所处的内存空间，即使在不同的函数函数调用过程中，依然存在。elems的内存不再像以前一样地在fibon_seq()每次调用找那时就被破坏又被重新建立。
```c++
const vector<int>* example_02_03(int size){
    static vector<int> elems;
    const int max_size = 1024;
    cout<<"size: "<<size<<endl;

    if(size<=0 || size>max_size){
        cout<<"Oops: requested size is not supported: "
            <<size<<" -- can't fulfill request.\n";
        return 0; // 即空指针
    }
    // 如果size<=elems.size()则不必重新计算
    for(long i=elems.size(); i<size; ++i){
        if(i==0 || i==1){
            elems.push_back(1);
        }else{
            elems.push_back(elems[i-1]+elems[i-2]);
        }
        cout<<elems[i]<<" ";
    }
    cout<<endl;
    return &elems;
}
int main(){
    const vector<int> *elems = example_02_03(3);
    elems = example_02_03(5);
    elems = example_02_03(7);
    display(elems);
    return 9;
}
```
#### 3. 出现的问题
1. **ld: 1 duplicate symbol for architecture x86_64**
出现错误的原因是：重复定义。