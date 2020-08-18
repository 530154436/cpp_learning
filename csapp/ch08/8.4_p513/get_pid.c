//
// Created by 郑楚彬 on 2020/8/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    //﻿获取进程 ID
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("PID: %d, PPID: %d \n", pid, ppid);
}