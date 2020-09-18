//
// Created by Edward on 2018/4/4.
//
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

/**
 * 打印整型数组
 *
 * @param a
 * @param n
 */
void printIntArray(char* name, int a[], int n){
    printf("%s [", name);
    for(int i=0; i<n; i++){
        printf(" %d ", a[i]);
    }
    printf("]\n");
}

void printIntArray(string name, int a[], int n){
    int i;
    cout<< name << "： ";
    for(i=0; i<n-1; i++){
        cout<< a[i] << ", ";
    }
    cout<< a[i]<<endl;
}