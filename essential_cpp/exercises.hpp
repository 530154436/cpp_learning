//#ifendif防止多次包含一个文件
#ifndef EXERCISES_H
#define EXERCISES_H

#include <vector>
#include <iostream>
using namespace std;

const int seq_cnt = 6;

// 自定义函数(工具方法)
extern void swap_by_value(int x, int y); // extern 声明
extern void swap_by_pointer(int *p1, int *p2);
extern void swap_by_reference(int &x, int &y);

// 第1章样例、习题
extern void example_01_06();        // p7
extern void example_01_07();        // p33
extern void ex_01_01();             // p7
extern void ex_01_02();             // p7
extern void ex_01_05();             // p33
extern void ex_01_06();             // p33
extern void ex_01_07();             // p34

// 第2章样例、习题
extern bool example_02_01(int pos, int &elem);           // p36
extern void example_02_02();                             // p45 传值、传指针、传引用
extern const std::vector<int>* example_02_03(int size);  // p54 局部静态对象
extern bool example_02_04(int pos, int& elems);          // p55 内联函数
extern bool example_02_05(int pos, int& elems, const std::vector<int>* (*seq_ptr)(int)); // p61 函数指针
extern bool ex_02_02(int pos, int &elem);                // p64 练习2.2

// ------------------------------------------------------------ //
// 函数模板的实现需要写在头文件中
template <typename T>
void display(const std::vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        std::cout<<vec[i]<<' ';
    }
    std::cout<<std::endl;
}
template <typename T>
void display(std::vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        std::cout<<vec[i]<<' ';
    }
    std::cout<<std::endl;
}
template <typename T>
void display(const std::vector<T> *vec){
    if (!vec){
        std::cout<<"display(): The vector pointer is 0.\n";
    }
    for(int i=0; i<vec->size(); i++){
        std::cout<<(*vec)[i]<<' ';
    }
    std::cout<<std::endl;
}
template <typename T>
void display(const std::vector<T> &vec, std::ostream &os=std::cout){
    for(int i=0; i<vec.size(); i++){
        os<<vec[i]<<' ';
    }
    os<<std::endl;
}
inline bool is_size_ok(int size, const int max_size){
    if(size<=0 || size>max_size){
        std::cout<<"Oops: requested size is not supported: "
            <<size<<" -- can't fulfill request.\n";
        return false;
    }
    return true;
}
inline const  std::vector<int>* fibon_seq(int size){
    const int max_size = 1024;
    static  std::vector<int> elems;
    std::cout<<"size: "<<size<< std::endl;
    if(!is_size_ok(size, max_size)) return 0;

    // 如果size<=elems.size()则不必重新计算
    for(long i=elems.size(); i<size; ++i){
        if(i==0 || i==1){
            elems.push_back(1);
        }else{
            elems.push_back(elems[i-1]+elems[i-2]);
        }
        std::cout<<elems[i]<<" ";
    }
    std::cout<< std::endl;
    return &elems;
}
inline std::vector<int>* pentagonal_seq(int pos){
    static std::vector<int> elems;
    // 如果size<=elems.size()则不必重新计算
    cout<<"Pentagonal Series: ";
    for(int i=(int)elems.size()+1; i<=pos; i++){
        elems.push_back(i*(3*i-1)/2);
        cout<<elems[i-1]<<" ";
    }
    cout<<endl;
    return &elems;
}

inline int ex2_5_max(int a, int b){  return a>b?a:b; }
inline float ex2_5_max(float a, float b){  return a>b?a:b; }
inline string ex2_5_max(string a, string b){  return a>b?a:b; }

template <typename T> T ex2_6_max(T a, T b){ return a>b?a:b; }

#endif     //防止文件被重复包含