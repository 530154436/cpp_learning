//
// Created by 郑楚彬 on 2018/4/4.
//
#include <stdio.h>

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