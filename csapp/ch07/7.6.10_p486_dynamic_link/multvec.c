//
// Created by 郑楚彬 on 2020/7/22.
//

int multcnt = 0;

void multvec(int *x, int *y, int *z, int n){
    multcnt++;

    int i;
    for (i=0; i<n; i++)
        z[i] = x[i] * y[i];
}