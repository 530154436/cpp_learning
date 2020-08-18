//
// Created by 郑楚彬 on 2020/3/12.
//
#include <stdlib.h>
#include <stdio.h>

char* gets(char* s){

    // s为字符数组首地址
    int c;
    char *dest = s;

    // *dest++ = c; => *(dest++) = c;
    while ((c=getchar())!='\n' && c!=EOF)
        *dest++ = c;

    if (c==EOF && dest==s)
        return NULL;
    *dest++ = '\0';

    return s;
}

void echo(){
    char buff[4];
    gets(buff);
    puts(buff);
}

int main(){
    echo();
}