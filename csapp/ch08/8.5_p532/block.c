//
// Created by Edward on 2020/8/12.
//

#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);


#include <signal.h>
int sigemptyset(sigset_t *set);                   //初始化set为空集合
int sigfillset(sigset_t *set);                    //把每个信号都添加到set中
int sigaddset(sigset_t *set, int signum);         //将signum信号添加到set中
int sigdelset(sigset_t *set, int signum);         //将signum从set中删除
int sigismember(const sigset_t *set, int signum); //如果signum是set中的成员，则返回1，否则返回0