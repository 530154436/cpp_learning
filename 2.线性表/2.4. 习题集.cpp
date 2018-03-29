//
// Created by 郑楚彬 on 2018/3/29.
//
#include "../utility/LinkedList.h"
#include "../utility/DLinkedLIst.h"
#include "../utility/SqList.h"


/*============================================ 真题仿造 ============================================*/
/**
 *  1. 设顺序表用数组 A[]表示，表中元素存储在数组下标 1~m+n 的范围内，前 m 个元素递增有序，后 n 个元素递增有序，
 *     设计一个算法，使得整个顺序表有序。(P47)
 *    (1) 给出算法的基 设计思想。
 *    (2) 根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
 *    (3) 说明你所设计算法的时间复杂度和空间复杂度。
 *
 *  算法思路：
 *      取表 R 中的第一个元素 A[m+1]存入辅助变量 temp 中，让 temp 逐个与 A[m],A[m-1],...,A[1]进行比较，
 *      当 temp<A[j](1≤j≤m)时，将 A[j]后移一位; 否则将 temp 存入 A[j+1]中。
 */
void resort(int A[], int m, int n){
    int i,j,temp;
    for(i=m; i<m+n; i++){
        temp = A[i];

        // 比 temp 大的数后移
        for(j=i-1; j>0&&A[j]>temp; j--){
            A[j+1] = A[j];
        }

        // A[j] 是第一个比 temp 小的数
        A[j+1] = temp;
    }
}

void test01(){
    SqList A;
    int a[13] = {1, 3, 5, 7, 8, 9, 11, 12, 2, 4, 6, 8, 10};
    createSqList(A, a, 13);
    printSqList("排序前-A", A);
    resort(A.data, 8, 5);
    printSqList("排序后-A", A);
}

/**
 * 2. 已知递增有序的单链表 A,B(A,B 中元素个数分别为 m,n 且 A,B 都带有头结点) 分别存储了一个集合，请设计算法以求出两个集合
 *    A 和 B 的差集 A-B(即仅由在 A 中出现 而不在 B 中出现的元素所构成的集合)。将差集保存在单链表 A 中，并保持元素的递增有序 性。 (P47)
 *   (1) 给出算法的基 设计思想。
 *   (2) 根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
 *   (3) 说明你所设计算法的时间复杂度。
 *
 *  算法思路:
 *     设置两个指针 p,q 开始时分别指向 A 和 B 的开始结点，同时遍历链表 A B；
 *      1) 若 B < A， 则 q 指针后移；
 *      2) 若 A < B， 则 p 指针后移；
 *      3) 若 A = B， 则 删除节点。
 *     最后 p 与 q 任一指针为 NULL 的时候算法结束。
 */
void difference(LNode *&A, LNode *&B){
    if(A==NULL || B==NULL){
        return;
    }

    LNode *p = A->next;
    LNode *pre = A; //pre 为 A 中 p 所指结点的前驱结点的指针。删除必须知道前驱节点的指针!!!!!
    LNode *q = B->next;

    while(p!=NULL && q!=NULL){
        if(p->data > q->data){
            q = q->next;
        } else if(p->data < q->data){
            pre = p;
            p = p->next;
        } else{
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
    }
}

void test02(){
    LNode *A, *B;
    int a[5] = {4, 7, 8, 11, 23};
    int b[5] = {1, 2, 4, 11, 20};
    createListR(A, a, 5);
    createListR(B, b, 5);
    printLinkedListH("A", A);
    printLinkedListH("B", B);
    difference(A, B);
    printLinkedListH("A-B", A);
}
/*============================================ 真题仿造 ============================================*/

/*============================================ 习题心选 ============================================*/
/**
 * 1. 设计一个算法，将顺序表中的所有元素逆置。
 *
 *  思路:
 *      两个变量 i，j 指示顺序表的第一个元素和最后一个元素，交换 i，j 所指元素，然后 i 向后移动一个位置，j 向前移动一个位置，
 *      如此循环， 直到 i 与 j 相遇时结束，此时顺序表 L 中的元素已经逆置。
 */
void reverse01(int a[], int n){
    if(n<0 || a==NULL){
        return;
    }
    int i, mid, tmp;
    mid = n/2;
    for(i=0; i<mid; i++ ){
        tmp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = tmp;
    }
}

void reverse02(SqList &A){
    int i, j, tmp;
    // 交换两端的元素
    for(i=0, j=A.length-1; i<j; i++, j--){
        // 交换数组元素
        tmp = A.data[i];
        A.data[i] = A.data[j];
        A.data[j] = tmp;
    }
}

void test03(){
    SqList A;
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    createSqList(A, a, 8);
    printSqList("逆置前_A", A);

    // reverse01(A.data, 8);
    reverse02(A);
    printSqList("逆置后_A", A);
}

/**
 * 2. 设计一个算法，从一给定的顺序表 L 中删除下标 i 到 j(i≤j，包括 i，j)之间的所有元素，假定 i,j 都是合法的。
 *
 * 思路：
 *     从第 j+1 个元素开始到最后一个元素为止，用这之间的每个元素去覆盖从这个元素开始往前数第 j-i+1 个元素
 */
void delRange(SqList &sqList, int i, int j){
    int m;
    int len = j-i+1;
    for(m=j+1; m<sqList.length; m++){
        sqList.data[m-len] = sqList.data[m];
    }
    sqList.length -= len;
}

void test04(){
    SqList A;
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    createSqList(A, a, 8);
    printSqList("删除前_A", A);

    delRange(A, 1, 7);
    printSqList("删除后_A", A);
}

/**
 * 3.有一个顺序表 L，其元素为整型数据，设计一个算法，将 L 中所有小于表头元素的整数放在前半部分，
 *   大于的整数放在后半部分，数组从下表 1 开始存储。
 */
/*============================================ 习题心选 ============================================*/

int main(){
    // test01();
    // test02();

    // test03();
    test04();
}