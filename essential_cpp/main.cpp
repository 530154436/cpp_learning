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

int main() {
    cout<< "G++ " << __VERSION__ << endl;
    //test_01();
    //test_02();

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
    //example_02_02();

    //const vector<int> *elems = example_02_03(3);
    //elems = example_02_03(5);
    //elems = example_02_03(7);
    //display(elems);

    int elem = 0;
    example_02_04(5, elem);
    cout<<"pos:"<<5<<", elem:"<<elem<<endl;
    example_02_04(7, elem);
    cout<<"pos:"<<7<<", elem:"<<elem<<endl;

    return 0;
}

