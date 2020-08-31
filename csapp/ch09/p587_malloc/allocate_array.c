//
// Created by 郑楚彬 on 2020/8/20.
//
#include <stdio.h>
#include <stdlib.h>
int main(){
    int *array, i, n;
    printf("n: ");
    scanf("%d", &n);
    array = (int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++) {
        printf("Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("Array(%d): [ ", n);
    for(i=0; i<n-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d ]", array[n-1]);

    free(array);
    exit(0);
}