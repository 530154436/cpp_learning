# 1 "sum.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "sum.c"



int sum(int *a, int n){
    int i, s = 0;
    for(i=0; i<n; i++){
     s += a[i];
    }
    return s;
}
