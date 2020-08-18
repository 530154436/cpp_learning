//
// Created by 郑楚彬 on 2020/8/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    // 创建进程
    int x = 1;
    pid_t pid = fork();
    if(pid==0){ // 子进程
        printf("child: x=%d\n", ++x);
        exit(0);
    }
    printf("parent: x=%d\n", --x);
    exit(0);
}
