//
// Created by 郑楚彬 on 2020/6/28.
//
#include <iostream>
using namespace std;

void twiddle1(long *xp, long *yp){
    *xp += *yp;
    *xp += *yp;
}

void twiddle2(long *xp, long *yp){
    *xp += 2* *yp;
}

void test_ma(){
    // 当 xp 和 yp 指向同一个存储器位置时，两个程序结果不在相同，因此编译器不会优化它。
    long x=2, y=3;
    long *xp=&x, *yp=&y;
    long t1;

    // 例1
    // 指针不同
    twiddle1(xp, yp);
    cout<<"twiddle1: addr(xp)="<<xp<<", xp="<<*xp<<endl;

    x=2, y=3;
    twiddle2(xp, yp);
    cout<<"twiddle2: addr(xp)="<<xp<<", xp="<<*xp<<endl;

    // 指针相同
    x=2, y=3;
    twiddle1(xp, xp);
    cout<<"twiddle1: addr(xp)="<<xp<<", xp="<<*xp<<endl;  // 4*xp

    x=2, y=3;
    twiddle2(xp, xp);
    cout<<"twiddle2: addr(xp)="<<xp<<", xp="<<*xp<<endl;  // 3*xp

    // 例2
    x=1000, y=3000;
    long a=1,b=1;
    long *p, *q;

    // 指针不同
    p=&a, q=&b;
    *q = y;
    *p = x;
    t1 = *q;
    cout<<"t1="<<t1<<endl;

    // 指针相同
    p=&a, q=&a;
    *q = y;
    *p = x;
    t1 = *q;
    cout<<"t1="<<t1<<endl;
}