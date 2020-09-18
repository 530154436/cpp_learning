//
// Created by Edward on 2018/5/25.
//
/**
 * 直接查找法
 *
 * @param a
 * @param n
 * @param key
 * @return
 */
int sqSearch(int a[], int n, int key){
    for(int i=0; i<n; i++){
        if(a[i] == key)
            return i;
    }
    return -1;
}

/**
 * 折半查找 (要求线性表是有序的)
 *
 * @param R
 * @param low
 * @param high
 * @param key
 * @return
 */
int binarySearch(int R[], int low, int high, int key){
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(R[mid] == key){
            return mid;
        }else if(R[mid] > key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}