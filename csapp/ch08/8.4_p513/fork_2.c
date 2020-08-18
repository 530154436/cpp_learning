//
// Created by 郑楚彬 on 2020/8/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    // 连续fork
    printf("L0\n");
    fork();
    printf("L1\n");
    fork();
    printf("Bye\n");
}