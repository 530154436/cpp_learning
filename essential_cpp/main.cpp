//
// Created by 郑楚彬 on 2019/12/12.
//
#include "exercises.hpp"

#include <iostream>
using namespace std;

void test_01(){
    char* ch="hello";
    cout<<ch[0];

    char ch_a[] = "hello";
    cout<<ch_a;

    string ch_str = "hello";
    cout<<ch_str;

    int* data= new int[10];
    data[1] = 1;
    cout<<data;
}

void test_02(){
    int a = 20, b = 10;
    cout << "交换前: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    swap_by_value(a, b); // 值传递
    cout << "交换后: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    /*-------------------------分界线1------------------*/
    cout << "交换前: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    swap_by_pointer(&a, &b); // 值传递
    cout << "交换后: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    /*-------------------------分界线2------------------*/
    cout << "交换前: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    swap_by_reference(a, b); // 引用传递
    cout << "交换后: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;

    int value=1024;
    int* pi = &value; // pi=0x7ffeef04a05c2028
    *pi = 2028;
    cout << *pi;

}

int main() {
    cout<< "G++ " << __VERSION__ << endl;
    //test_01();
    test_02();

    // 第1章
    //example_01_06();
    //example_01_07();
    //ex_01_01();
    //ex_01_02();
    //ex_01_05();
    //ex_01_06();
    //ex_01_07();

    // 第2章
    //int elem = 0;
    //example_02_01(10, elem);

    return 0;
}

