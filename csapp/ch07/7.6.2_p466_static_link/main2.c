//
// Created by 郑楚彬 on 2020/7/22.
//
#include <stdio.h>
#include "vector.h"

int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];

int main(){
    addvec(x, y, z, 2);

    printf("x = [%d, %d]\n", x[0], x[1]);
    printf("y = [%d, %d]\n", y[0], y[1]);
    printf("z = x + y = [%d, %d]\n", z[0], z[1]);

    return 0;
}