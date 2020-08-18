//
// Created by 郑楚彬 on 2020/3/11.
//
#include "ch03/p125.hpp"
//#include "ch03/3_10/buffer_overflow.c"

void test(){
    int A[3];
    int *B;
    int *C[3];
    int (*D)[3];
    cout<< sizeof(A)<<endl;
    cout<< sizeof(*A)<<endl;

    cout<< sizeof(B)<<endl;
    cout<< sizeof(*B)<<endl;

    cout<< sizeof(C)<<endl;
    cout<< sizeof(*C)<<endl;
    cout<< sizeof(**C)<<endl;

    cout<< sizeof(D)<<endl;
    cout<< sizeof(*D)<<endl;

    char c = 'a';
    char *p = &c;
    cout<< (int *)p <<endl;
    cout<< (int *)(p+7)<<endl;
    cout<< (int *)p+7<<endl;
}

int main(){
    //p125();
    //test();
    //echo();
}