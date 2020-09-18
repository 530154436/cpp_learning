//
// Created by Edward on 2020/3/12.
//
#include <iostream>
using namespace std;

/**
 xp in %rdi、y in %rsi

 movq (%rdi), %rax      # Get x at xp
 movq %rsi, (%rdi)      # Store y at xp
 ret                    # Return
 */
long exchange(long *xp, long y){
    long x = *xp;
    *xp = y;
    return x;
}

void p125(){
    long a = 4;
    long b = exchange(&a, 3);
    cout<<"a="<<a<<", b="<<b<<endl;
}