//
// Created by 郑楚彬 on 2019/12/12.
//
#include <iostream>
#include <vector>
#include "exercises.hpp"
using namespace std;

bool example_02_01(int pos, int &elem){
    /**
     * 斐波拉契数列 p36
     * @param pos  第i个位置
     * @param elem 结果
     * @return 第@code{pos}个位置的元素
     */
    // 检查位置是否合理
    if(pos<=0 || pos>1000){
        elem = 0;
        cout<<"Position "<<pos<<" is not valid.";
        return false;
    }
    elem = 1;
    int b1=1,b2=1;
    for (int i = 2; i < pos; ++i) {
        elem = b1+b2;
        b1=b2, b2=elem;
        cout << i+1<< ": "<<elem << endl;
    }
    return true;
}

void example_02_02(){
    // p45
    int a = 20, b = 10;
    cout << "传值交换前: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    swap_by_value(a, b); // 值传递
    cout << "传值交换后: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    /*-------------------------分界线1------------------*/
    cout << "传指针交换前: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    swap_by_pointer(&a, &b); // 值传递
    cout << "传指针交换后: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    /*-------------------------分界线2------------------*/
    cout << "传引用交换前: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    swap_by_reference(a, b); // 引用传递
    cout << "传引用交换后: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;

    // 真实对象
    int value=1024;
    int* pi = &value; // pi=0x7ffeef04a05c2028
    *pi = 2028;
    cout << *pi;
}

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

inline bool is_size_ok(int size, const int max_size){
    if(size<0 || size>max_size){
        cout<<"Oops: requested size is not supported: "
            <<size<<" -- can't fulfill request.\n";
        return false;
    }
    return true;
}
inline const vector<int>* fibon_seq(int size){
    const int max_size = 1024;
    static vector<int> elems;
    cout<<"size: "<<size<<endl;
    if(!is_size_ok(size, max_size)) return 0;

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
bool example_02_04(int pos, int& elems){
    // p55
    const vector<int>* pseq = fibon_seq(pos);
    if(!pseq){
        elems =0;
        return false;
    }
    elems = (*pseq)[pos-1];
    return true;
}





