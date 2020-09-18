//
// Created by Edward on 2020/8/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    // ﻿僵死进程
    if (fork() == 0) { /* Child */
        printf("Terminating Child, PID = %d\n", getpid());
        exit(0); }
    else {
        printf("Running Parent, PID = %d\n", getpid());
        while (1) ; /* Infinite loop */
    }
}