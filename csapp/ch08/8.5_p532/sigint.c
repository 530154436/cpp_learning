//
// Created by Edward on 2020/8/12.
//
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <signal.h>

void sigint_handler(int sig){
    printf("Caught SIGINT.\n");
    exit(0);
}

int main(){
    if(signal(SIGINT, sigint_handler)==SIG_ERR){
        printf("SIGINT ERROR.\n");
    }

    pause();
    return 0;
}