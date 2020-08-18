//
// Created by 郑楚彬 on 2020/7/22.
//
#include <stdio.h>
#include "math.h"

int addcnt = 0;

void addvec(int *x, int *y, int *z, int n){
    addcnt++;

    int i;
    printf("2+2 = %d\n", add(2,2));
    printf("2-2 = %d\n", sub(2,2));
    for (i=0; i<n; i++)
        z[i] = x[i] + y[i];
}