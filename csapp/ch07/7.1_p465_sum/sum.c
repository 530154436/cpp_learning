//
// Created by 郑楚彬 on 2020/7/8.
//
int sum(int *a, int n){
    int i, s = 0;
    for(i=0; i<n; i++){
    	s += a[i];
    }
    return s;
}