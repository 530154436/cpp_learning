[TOC]
#### 1. 数组
+ **下标操作**
将array的`起始地址`加上索引值，产生出某个元素的地址，然后该地址再被提领(dereference)以返回元素值。如
  ```c++
array[2]   // 指针的算术运算和提领操作自动进行
*(array+2) // 若array(int)第1个元素的地址为100，则array+2的地址为 100+2*4(int长度为4)=1008，
  ```
+ **[注]**
程序代码中如果出现array,获得的是`元素地址`，如果出现\*array,则获得的是`元素值`。

#### 2. vector iterator
对于vector::iterator 而言，其递增函数前进至下一个元素的方式，是将目前的地址加上一个元素大小。
每个标注容器都提供有一个名为`begin()`的操作函数，可返回一个`iterator`，指向第1个元素。
+ 赋值(assign)、比较(compare)、递增(increment)、提领(dereference)操作
  ```c++
template <typename T>
void display(const vector<T> &vec, ostream &os){
    typename vector<T>::const_iterator iter = vec.begin();
    typename vector<T>::const_iterator end_it = vec.end();
    for(; iter!=end_it; iter++)
        os<< *iter << " ";
    std::cout<<std::endl;
}
  ```

#### 3. 遇到的问题
+ [Error] need ‘typename’ before ‘std::vector::iterator’ because ‘std::vector’ is a dependent scope
vector<int>::iterator it_int;是可以通过的, 而用模板参数类型T声明的vector<T>::iterator it; 却不能通过, 它们的`关键区别`在于vector<int>是实例化之后的一个实在的类型, 而vector<T>还是一个模板类型, 如何实例化还需要取决于外部实际传进来的类型参数T.
需要在std::vector<char>::iterator 之前加一个关键字`typename`来显式地说明它是一个类型而非成员变量.
