//
// Created by 郑楚彬 on 2020/6/28.
//
#include <iostream>
using namespace std;

void psum1(float a[], float p[], long n){
    long i;
    p[0] = a[0];
    for(i=1; i<n; i++)
        p[i] = p[i-1]+a[i];
}

void psum2(float a[], float p[], long n){
    long i;
    p[0] = a[0];
    for(i=1; i<n-1; i+=2){
        float mid_val = p[i-1] + a[i];
        p[i] = mid_val;
        p[i+1] = mid_val + a[i+1];
    }
    if(i<n)
        p[i] = p[i-1] + a[i];
}