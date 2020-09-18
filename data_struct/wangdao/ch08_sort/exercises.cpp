//
// Created by Edward on 2020/9/10.
//

#include "exercises.hpp"
#include "../ch02_linear_table/LinkList.hpp"

/*
 * 8.3 交换排序 p323-p324
 */
/**
 * 2. 编写双向冒泡排序算法，在正反两个方向交替进行扫描，即第一趟把关键字最大的元素放在序列的最后面，
 *    第二趟把关键字最小的元素放在序列的最前面，如此反复进行。
 *
 * 算法思想:
 *    (1) 奇数趟时，从前向后比较相邻元素的关键字，遇到逆序即交换，直到把序列中关键字最大的元素移动到序列尾部。
 *    (2) 偶数趟时，从后往前比较相邻元素的关键字，遇到逆序即交换，直到把序列中关键字最小的元素移动到序列前端。
 */
void BubbleSort(ElemType A[], int n){
    int i=0, j=n-1;
    bool flag=true;

    while(i<j && flag){
        flag = false;

        for(int k=i; k<j; k++){         // 从前往后
            if(A[k]>A[k+1]){            // 发生逆序
                swap(A[k], A[k+1]);
                flag = true;
            }
        }
        j--;                            // 更新上界

        for(int k=n-1; k>i; k--){       // 从后往前
            if(A[k-1]>A[k]){
                swap(A[k-1], A[k]);
                flag = true;
            }
        }
        i++;                            // 修改下界
    }
}

/**
 * 3. 已知线性表按顺序存储，且每个元素都是不相同的整数型元素，设计把所有奇数移动到所有偶数前边的算法(要求时间最少，辅助空间最少)。
 *
 * 基本思想: 基于快速排序的划分
 *     先从前向后找到一个偶数元素L(i)，再从后向前找到一个奇数元素L(j)，将二者交换; 重复上述过程直到i大于j。
 */
void move(ElemType A[], int n){
    int i=0, j=n-1;

    ElemType tmp=A[i];
    while(i<j){

        while(i<j && A[j]%2==0) j--;
        A[i] = A[j];

        while(i<j && A[i]%2!=0) i++;
        A[j] = A[i];
    }
    A[i] = tmp;
}

void move2(ElemType A[], int n){
    int i=0, j=n-1;

    while(i<j){
        while(i<j && A[j]%2==0) j--;
        while(i<j && A[i]%2!=0) i++;
        if(i<j)
            swap(A[i], A[j]); //交换这两个元素
        i++,j--;
    }
}

/**
 * 4. 试重新编写考点精析中的快速排序的划分算法，使之每次选取的枢轴值都是随机地从当前子表中选择的。
 *
 * 算法思想:
 *    直接先随机地求出枢轴的下标，然后将枢轴值与 A[low] 交换，而后的思想就与前面的划分算法一样。
 */
int Partition2(ElemType A[], int low, int high){

    int pivot_pos = low+rand()%(high-low+1);    // 随机枢值下标

    swap(A[pivot_pos], A[low]);     // 将枢轴值交换到第一个元素
    ElemType pivot = A[low];        // 置当前表中的第一个元素为枢轴值

    while(low<high){
        while(low<high && A[high]>=pivot) --high;
        A[low] = A[high];

        while(low<high && A[low]<=pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

/**
 * 5. 试编写一个算法，使之能够在数组 L[1...n] 中找出第 k 小的元素(即从小到大排序后处于第 k 个位置的元素)。
 *
 * 基本思想: 基于快速排序的划分
 *     从数组 L[1...n] 中选择枢轴 pivot 进行和快速排序一样的划分操作后， 表 L[1...n] 被划分为 L[1...m-1] 和 L[m+1...n]，
 *     其中 L(m)=pivot。
 *
 *     (1) 当m=k时
 *         显然 pivot 就是所要寻找的元素， 直接返回 pivot 即可。
 *
 *     (2) 当m<k时
 *         所要寻找的元素一定落在 L[m+1...n]中， 因此可对 L[m+1...n] 递归地查找第 k-m 小的元素。
 *
 *     (3) 当 m>k时，
 *         所要寻找的元素一定落在 L[1...m-1]中，因此可对 L[1...m-1] 递归地查找第 k 小的元素。
 */

int Parttion(ElemType A[] , int low, int high){
    ElemType pivot = A[low];
    while(low<high){
        while(low<high && A[high]>=pivot) --high;
        A[low] = A[high];

        while(low<high && A[low]<=pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

int kth_elem(ElemType A[] , int low, int high, int k){
    int pivot_pos = Parttion(A, low, high); // 快排的划分

    if(pivot_pos==k) {
        return A[pivot_pos];
    }                     // 由于与 k 相同，直接返回 pivot 元素
    else if(k<pivot_pos)
        return kth_elem(A, low, pivot_pos-1, k);   // 在前一部分表中递归寻找
    else
        return kth_elem(A, pivot_pos+1, high, k);  // 在后一部分表中递归寻找
}

/**
 * 6.【2016 统考真题】己知由 n(n>=2) 个正整数构成的集合 A= {a_k|O<=k<n} 时，将其划分为两个不相交的子集 A_1 和 A_2，
 *    元素个数分别是 n_1 和 n_2，A_1 和 A_2 中的元素之和分别为 S_1 和 S_2。设计一个尽可能高效的划分算法，
 *    满足 |n_1-n_2| 最小且 |S_1-S_2| 最大。
 *
 *  由题意知，将最小的 [n/2] 个元素放在 A1 中，其余的元素放在 A2中， 分组结果即可满足题目要求。 => [n/2] 枢轴位置
 */
int setPartition(ElemType A[], int n){
    int k = n/2-1;
    kth_elem(A, 0, n-1, n/2-1);

    int s1=0, s2=0;
    for(int i=0; i<=k; i++) s1+=A[i];
    for(int i=k+1; i<n; i++) s2+=A[i];

    return s2-s1;
}

/**
 * 7. 荷兰国旗问题:设有一个仅由红、白、蓝三种颜色的条块组成的条块序列，请编写一个时间复杂度为 O(n)的算法，使得这些条块
 *    按红、白、蓝 (0、1、2) 的顺序排好，即排成荷兰国旗图案。
 */
void Flag_A_rrange(int A[], int n){
    int i=0, k=n-1, j=0;
    while(j<=k){
        switch(A[j]){                           // 判断条块的颜色
            case 0: swap(A[j], A[i]); ++i; ++j; // 红色(0)，则和 i 交换
                break;
            case 1: j++;
                break;
            case 2: swap(A[j], A[k]); --k;      // 蓝色(2)，则和 k 交换
                break;                          // 这里没有 j++ 语旬以防止交换后 a[j] 仍为蓝色的情况
            default:
                break;
        }
    }
}


/*
 * 8.4 选择排序 p335
 */
/**
 * 4. 编写一个算法，在基于单链表表示的待排序关键字序列上进行简单选择排序。
 *
 * 算法思想:
 *     (1) 每趟在原始链表中摘下关键字最大的结点，把它插入到结果链表的最前端。
 *     (2) 由于在原始链表中摘下的关键字越来越小，在结果链表前端插入的关键字也越来越小，
 *         因此最后形成的结果链表中的结点将按关键字非递减的顺序有序链接。
 */
void selectSort(LNode<ElemType> *&L){   // 假设链表不带表头结点。
    LNode<ElemType> *h=L, *preMax,*pMax,*pre,*p;
    L = NULL;

    while(h){
        preMax=NULL; pMax=h;    // pMax 为最大结点、preMax 为其前驱
        pre=NULL; p=h;          // p 为工作指针、 pre 为其前驱

        while(p){               // 求最大值的节点
            if(p->data>pMax->data){
                preMax = pre;
                pMax = p;
            }
            pre = p;
            p = p->next;
        }

        if(pMax==h)             // 最大结点在原链表前端
            h = h->next;
        else                    // 最大结点在原链表内(摘下)
            preMax->next = pMax->next;

        pMax->next=L; L=pMax;   // 结点 s 插入到结果链前端
    }
}

/**
 * 5. 试设计一个算法，判断一个数据序列是否构成一个小根堆。
 *
 * 算法思想:
 *    将顺序表 L[1...n] 视为一个完全二叉树，扫描所有分支结点，遇到孩子结点的关键字小于根结点的关键字时返回 false，扫描完后返回 true。
 */
bool IsMinHeap(ElemType A[], int n){    // 数组下标从1开始

    // 从最后一个父节点开始 (偶数时单分支、奇数时双分支)
    if(n%2==0){
        if(A[n/2]>A[n])
            return false;
    }else{
        if(A[n/2]>A[2*(n/2)+1] || A[n/2]>A[n])
            return false;
    }

    for(int i=n/2-1; i>=1; i--){            // 双分支
        if(A[i]>A[2*i] || A[i]>A[2*i+1])    // 父节点>左孩子 或 父节点>右孩子
            return false;
    }
    return true;
}

/*
 * 8.6 各种内部排序算法的比较和应用
 */
/**
 * 2. 设顺序表用数组 A[] 表示，表中元素存储在数组下标 1~m+n 的范围内，前 m 个元素递增有序，后 n 个元素递增有序，设计一个算法，
 *    使得整个顺序表有序。
 *
 * 算法思想:
 *     将数组 A[1...m+n] 视为一个 已经过 m 趟插入排序的表 ， 则从 m+1 趟开始，将后 n 个元素依次插入前面的有序表中
 */
void Insert_Sort(ElemType A[] , int m, int n){
    int i,j,tmp;
    for(i=m; i<m+n; i++){   // 插入排序
        if(A[i]<A[i-1]){
            tmp = A[i];
            for(j=i-1; j>=0&&tmp<A[j]; j--)
                A[j+1] = A[j];
            A[j+1] = tmp;
        }
    }
}

/**
 * 4. 设有一个数组中存放了一个无序的关键序列 K_1,K_2，...，K_n。 现要求将 K_n，放在将元素排序后的正确位置上，
 *    试编写实现该功能的算法，要求比较关键字的次数不超过 n。
 *
 * 基本思想:
 *    以 K_n 为枢轴进行一趟快速排序。将快速排序算法改为以最后一个为枢轴
 */

int PartitionN(ElemType A[],int n){
    int low=0,high=n-1;
    swap(A[low], A[n-1]);

    ElemType pivot = A[low];    // 快排
    while(low<high){
        while(low<high && A[high]>=pivot) high--;
        A[low] = A[high];

        while(low<high && A[low]<=pivot) low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}