//
// Created by 郑楚彬 on 2020/6/28.
//
#include <iostream>
using namespace std;

long counter = 0;

long f(){
    return counter++;
}

long func1(){
    return f()+f()+f()+f();
}
long func2(){
    return 4*f();
}
long func1in(){
    long t = counter++;
    t += counter++;
    t += counter++;
    t += counter++;
    return t;
}
long func1opt(){
    long t = 4*counter+6;
    counter += 4;
    return t;
}

void test_call_func(){
    cout<<"func1: counter="<<func1()<<endl; // 6 = 0+1+2+3

    counter = 0; // 重置
    cout<<"func2: counter="<<func2()<<endl; // 0

    counter = 0;
    cout<<"func1in: counter="<<func1in()<<endl; // 6

    counter = 0;
    cout<<"func1opt: counter="<<func1opt()<<endl; // 6
}
