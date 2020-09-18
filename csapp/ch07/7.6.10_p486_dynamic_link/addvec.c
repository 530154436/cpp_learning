//
// Created by Edward on 2020/7/22.
//
#include <stdio.h>

int addcnt = 0;

void addvec(int *x, int *y, int *z, int n){
    addcnt++;

    int i;
    for (i=0; i<n; i++)
        z[i] = x[i] + y[i];
}