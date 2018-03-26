//
// Created by 郑楚彬 on 2018/3/26.
//
#include <stdio.h>
#include <iostream>
using namespace std;

void printArray(int a[], int len){
    printf("数组: [");
    for(int i=0; i<len-1; i++){
        printf("%d, ",a[i]);
    }
    printf("%d]\n", a[len-1]);
}