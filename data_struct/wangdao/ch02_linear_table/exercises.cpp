//
// Created by 郑楚彬 on 2020/9/3.
//
#include "exercises.hpp"
#include "../templates/SqStackTemplate.hpp"

/**
 * 1. 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置由最后一个元素填补，
 *    若顺序表为空则显示出错信息并退出运行。
 *
 * 算法思想:
 *     搜索整个顺序衰，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的原最小值元素的位置。
 */
bool Del_Min(SqList &L, ElemType &value){
    if(L.length==0)                             // 表空，中止操作返回
        return false;
    int i,index;
    value = L.data[0];
    for(i=1; i<L.length; i++){                  // 循环，寻找具有最小值的元素
        if(L.data[i]<value){
            value = L.data[i];
            index = i;
        }
    }
    L.data[index] = L.data[L.length-1];         // 空出的位置由最后一个元素填补
    L.length--;
    return true;
}

/**
 * 2. 设计一个高效算法，将顺序表 L 的所有元素逆置，要求算法的空间复杂度为 O(1)。
 *
 * 算法思想: 扫描顺序表L的前半部分元素，对于元素L.data[i) (O<=i<L.length/2),
 *         将其与后半部分的对应元素 L.data[L.length-i-1)进行交换。
 */
void Reverse (SqList &L){
    if(L.length==0)                             // 表空，中止操作返回
        return;
    int i,j;
    ElemType tmp;
    for(i=0,j=L.length-1; i<j; i++,j--){
        tmp = L.data[i];                        // 双指针、交换 L.data[i] 与 L.data[L.length-i-1]
        L.data[i] = L.data[j];
        L.data[j] = tmp;
    }
}

/**
 * 3. 对长度为 n 的顺序表 L，编写一个时间复杂度为 O(n)、空间复杂度为 O(1) 的算法，该算法删除线性表中所有值为 x 的数据元素。
 *
 * 算法思想: 用 k 记录顺序表 L 中等于 x 的元素个数，边扫描 L 边统计 k，并将不等于 x 的元素前移 k 个位置，最后修改 L 的长度。
 */
void del_x_2(SqList &L, ElemType x){
    if(L.length==0)                     // 表空，中止操作返回
        return;
    int k=0;                            // k记录值等于x的元素个数
    for(int i=0; i<L.length; i++){
        if(L.data[i]==x)
            k++;
        else
            L.data[i-k] = L.data[i];    // 当前元素前移k个位置
    }
    L.length -= k;
}

/**
 * 4. 从有序顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素， 如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
 *
 * 算法思想: 先寻找值大于等于 s 的第一个元素(第一个删除的元素)， 然后寻找值大于 t 的第一个元素(最后一个删除的元素的下一个元素)，
 *          要将这段元素删除，只需直接将后面的元素前移。
 */
bool Del_s_t(SqList &L, ElemType s, ElemType t){
    if(L.length==0 || s>=t)                     // 线性表为空或 s、 t 不合法，返回
        return false;
    int i,j;
    for(i=0; i<L.length && L.data[i]<s; i++);   // 寻找值大于等于s的第一个元素
    if (i>=L.length) return false;              // 所有元素值均小子 s， 返回

    for(j=i; j<L.length && L.data[j]<=t; j++);  // 寻找值大于t的第一个元素

    for(; j<L.length; i++,j++)
        L.data[i] = L.data[j];                  // 前移，填补被删元素位置
    L.length = i;
    return true;
}

/**
 * 5. 从顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素， 如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
 *
 * 算法思想: (与 3. 类似)
 *    从前向后扫描顺序表 L，用 k 记录下元素值在s与t之间元素的个数(初始时 k=0)。
 *    对于当前扫描的元素，若其值不在 s 到 t 之间，则前移 k 个位置; 否则执行 k++。
 */
bool Del_s_t2(SqList &L, ElemType s, ElemType t){
    if(L.length==0 || s>=t)                     // 线性表为空或 s、 t 不合法，返回
        return false;
    int k=0;
    for(int i=0; i<L.length; i++){
        if(s<=L.data[i] && L.data[i]<=t)
            k++;
        else
            L.data[i-k] = L.data[i];            // 当前元素前移 k个位置
    }
    L.length -= k;
    return true;
}

/**
 * 6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
 *
 * 算法思想: (类似于直接插入排序)
 *    有序顺序表值相同的元素一定在连续的位置上，用类似于直接插入排序的思想。
 *    初始时将第一个元素视为非重复的有序表, 之后依次判断后面的元素是否与前面非重复有序表的最后一个元素相同，
 *    若相同则继续向后判断，若不同则插入到前面的非重复有序表的最后，直至判断到表尾为止。
 */
bool Delete_Same(SqList& L){
    if(L.length<=0)
        return false;
    int i,j;                            // i存储第一个不相同的元素，j为工作指针
    for(i=0,j=1; j<L.length; j++){
        if(L.data[i]!=L.data[j])        // 查找下一个与上个元素值不同的元素
            L.data[++i] = L.data[j];    // 找到后，将元素前移
    }
    L.length = i+1;
    return true;
}

/**
 * 7. 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
 */
bool Merge(SqList A, SqList B, SqList &C){
    if (A.length + B.length > MaxSize)              // 大于顺序表的最大长度
        return false ;

    int i=0,j=0,k=0;
    while(i<A.length && j<B.length){                // 循环，两两比较，小者存入结果表
        if(A.data[i]<B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while(i<A.length) C.data[k++] = B.data[i++];    // 还剩一个没有比较完的顺序表
    while(j<B.length) C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}

/**
 * 8. 已知在一维数组 A[m+n] 中依次存放两个线性表 (a1,a2,a3,···,am) 和 (b1,b2,b3,···,bn)。
 *    试编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,b3,···,bn)放在(a1,a2,a3,···,am)的前面。
 *
 * 10.【2010 统考真题】设将 n(n>1) 个整数存放到一维数组 R 中。设计一个在时间和空间两方面都尽可能高效的算法。
 *     将 R 中保存的序列循环左移 p (O<p<n ) 个位直，即将 R 中的 数据由 (X0,X1,...,Xn-1) 交换为 (Xp,Xp+1,...,Xn-1,X0,X1,Xp-1)。
 */

void ReverseArray(ElemType A[], int l, int r){
    ElemType tmp;
    for(; l<r; l++,r--){
        tmp = A[l];
        A[l] = A[r];
        A[r] = tmp;
    }
}

void Reverse(ElemType A[], int m, int n, int arraySize){
    ReverseArray(A, 0, m+n-1);
    ReverseArray(A, 0, m-1);
    ReverseArray(A, m, m+n-1);
}

/**
 * 9. 线性表(a1,a2,a3,···,an)中的元素递增有序且按顺序存储于计算机内。要求设计一算法，完成用最少时间在表中查找数值为 x 的元素，
 *    若找到则将其与后继元素位置相交换，若找不到则将其插入表中并使表中元素仍递增有序。
 *
 * 算法思想: 折半查找
 */
void SearchExcgIst(ElemType A[], int n, ElemType x){
    int l=0, h=n-1, mid=0;              // low和 high 指向顺序表下界和上界的下标
    while(l<=h){
        mid = (h+l)/2;                  // 找中间位置, std::cout<<"(l,h,mid)=("<<l<<","<<h<<","<<mid<<")"<<std::endl;
        if(A[mid]==x){
            break;
        }else if(x<A[mid]){
            h = mid-1;                  // 到中点 mid 的右半部去查
        }else{
            l = mid+1; // x>A[mid]      // 到中点 mid 的左半部去查
        }
    }

    if(mid<n-1 && A[mid]==x){           // 若最后一个元素与 x 相等，则不存在与其后继交换的操作
        ElemType tmp = A[mid];
        A[mid] = A[mid+1];
        A[mid+1] = tmp;
    }

    if(l>h){                            // 查找失败，插入数据元素 x
        int i;
        for(i=n-1;i>h; i--)
            A[i+1] = A[i];              // 后移元素
        A[i+1] = x;                     // 插入 x
    }
}

/**
 * 11.【2011】一个长度为L(L>=1)的升序序列S，处在第「L/2 个位置的数称为 S 的中位数 。
 *     例如，若序列 S1 = (11 , 13, 15, 17, 19)，则 S1 的中位数是 15，
 *     两个序列的中位数是含它们所有元素的升序序列的中位数。
 *     例如，若 S2 = (2, 4, 6, 8, 20)，则 S1 和 S2 的中位数是 11。
 *     现在有两个等长升序序列 A 和 B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列 A 和 B 的中位数。
 *
 * 方法1: 双指针 => 等价于求第n个节点
 * 方法2: 分别求两个升序序列 A、 B 的中 位数，设为 a 和 b， 求序列 A、 B 的中位数过程如下:
 *     ① 若 a=b，则 a或b 即为所求中位数，算法结束。
 *     ② 若 a<b，则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求两次舍弃的长度相等。
 *     ③ 若 a>b，则舍弃序列 A 中较大的一半，同时舍弃序列 B 中较小的一半，要求两次舍弃的长度相等。
 *     在保留的两个升序序列中，重复过程1、2、 3，直到两个序列中均只含一个元素时为止，较小者即为所求的中位数。
 */
/*
 * 两个等长有序序列
 */
int MSearch(int A[],int B[],int n) {
    int i=0,j=0,median=0;
    for(int k=0; k<=n-1; k++){
        if(i<n && (j>=n||A[i]<B[j])){   // 较小者前进一步
            median=A[i++];
        }else{
            median=B[j++];
        }
    }
    return median;
}

/*
 * 两个不等长有序序列 相当于求两个有序序列的第n个节点
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
 */
double MSearch1(int A[], int m, int B[],int n) {
    int i=0,j=0,mid=(m+n)/2, pre=0,median=0;
    for(int k=0; k<=mid; k++){
        pre = median;
        if(i<m && (j>=n || A[i]<B[j])){
            median=A[i++];
        }else{
            median=B[j++];
        }
    }
    return (m+n)%2==0?(median+pre)/2.0:median;
}

int MSearch2(int A[],int B[],int n){
    int s1=0,d1=n-1,s2=0,d2=n-1,m1,m2;
    while(s1<d1 || s2<d2){
        m1 = (s1+d1)/2;
        m2 = (s2+d2)/2;
        if(A[m1]==B[m2]){
            return A[m1];
        }else if(A[m1]<B[m2]){
            if((s1+d1)%2==0){   // 若元素个数为奇数
                s1=m1;          // 舍弃 A 中间点以前的部分且保留中间点
                d2=m2;          // 舍弃 B 中间点 以后的部分且保留中间点
            }else{              // 元素个数为偶数
                s1=m1+1;        // 舍弃 A 中间点及中间点以前部分
                d2=m2;          // 舍弃 B 中间点 以后部分且保留中间点
            }
        }else{
            if((s2+d2)%2==0){
                d1=m1;
                s2=m2;
            }else{
                d1=m1;
                s2=m2+1;
            }
        }
    }
}

/**
 * 12.【2013】已知一个整数序列 A =(a0，a1，..., an-1)，其中 0≤ai<n (0≤i<n)。 若存在
 *    ap1 = ap2 =...= apm = x 且 m>n/2 (0≤pk<n，1≤k≤m)，则称 x 为 A 的主元素。
 *    例如A= ( 0，5，5，3，5，7，5，5 )，则 5 为主元素；又如 A= ( 0，5，5，3，5，1，5，7 )，
 *    则A 中没有主元素。假设 A 中的 n 个元素保存在一个一维数组中，请设计一个尽可能高效的算法，
 *    找出 A 的主元素。若存在主元素， 则输出该元素；否则输出-1。
 *
 * 算法思想:
 *     从前向后扫描数组元素，标记出一个可能成为主元素的元素 num。然后重新计数，确认 num 是否是主元素。算法可分为以下两步:
 *     (1)选取候选的主元素。
 *        ① 依次扫描所给数组中的每个整数，记录 num 的出现次数为 1;
 *        ② 遇到的下一个整数仍等于 num，则计数 cnt 加 1， 否则计数减 1:
 *        ③ 当计数减到 0 时，将遇到的下一个整数保存到 num 中，计数重新记为 1，
 *        ④ 开始新一轮计数，即从当前位置开始重复上述过程，直到扫描完全部数组元素 。
 *     (2)判断 num 是否是真正的主元素。再次扫描该数组，统计 num 出现的次数，若大 于 n/2，则为主元素；否则，序列中不存在主元素。
 *
 * https://leetcode-cn.com/problems/find-majority-element-lcci/
 */
int Majority (int A[], int n){
    if(n<1)
        return -1;
    int num=A[0],cnt=1;
    for(int i=0; i<n; i++){
        if(A[i]==num){
            cnt++;              // 对 A 中的候选主元素计数
        }else{
            if(cnt==0){         // 更换候选主元素，重新计数
                num = A[i];
                cnt = 1;
            }else{
                cnt--;          // 处理不是候选主元素的情况
            }
        }
    }

    if(cnt>0){
        cnt = 0;
        for(int i=0; i<n; i++)  // 统计候选主元素的实际出现次数
            cnt++;
    }
    return cnt>n/2?num:-1;      // 确认是否存在主元素
}

/**
 * 13.【2018】给定一个含 n (n>=1)个整数的数组，请设计一个在时问上尽可能高效的算法，找出数组中未出现的最小正整数。
 *     例如，数组 {-5，3, 2, 3} 中未出现的最小正整数是1; 数组 {1,2,3} 中未出现的最小正整数是 4。
 *
 * 算法思想:
 *     要求在时间上尽可能高效，因此采用空间换时间的办法。
 *     分配一个用于标记的数组 B[n+1],用来记录A中是否出现了1~n中的正整数，B[O]对应正整数 1, B[n]对应正整数n，初始化B中全部为0。
 *     由于 A 中含有n个整数，因此可能返回的值是1~n:
 *        ① 当 A 中 n 个数恰好为 1~n 时返回 n+1。
 *        ② 当数组 A 中出现了小于等于 0 或大于 n 的值时，会导致 1~n 中出现空余位置，返回结果必然在 1~n 中，
 *           因此对于 A 中 出现了小于等于 0 或大于 n 的值可以不采取任何操作。
 */
int findMissMin(int A[] , int n){
    int B[n+1],i;
    for(i=0; i<=n; i++)         // 赋初值为 0
        B[i] = 0;

    for(i=0; i<n; i++){
        if(A[i]>0 && A[i]<=n)   // 若 A[i] 的值介于 1~n，则标记数组 B
            B[A[i]] = 1;
    }

    for(i=1; i<=n; i++){        // 扫描数组B， 找到目标值
        if(B[i]==0)
            break;
    }
    return i;
}

/**
 * 1. 设计一个递归算法, 删除不带头结点的单链表 L 中所有值为 x 的结点。
 *
 *    终止条件: f(L, x)=不做任何事情,                 若 L 为空表
 *    递归主体: f(L, x)=删除*L结点, f(L->next, x);   若 L一>data==x
 */
void Del_X_1(LinkList &L, ElemType x){
    LNode*p;                  // 递归出口
    if(!L) return;
    if(L->data==x){             // 若L所指结点的值为 x, 删除*L，并让L指向下一结点
        p = L;
        L = L->next;
        free(p);
        Del_X_1(L, x);
    }else{
        Del_X_1(L->next, x);    // 若 L所指结点的值不为 x，则递归调用
    }
}

/**
 * 2. 在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，假设值为 x 的结点 不唯一，试编写算法以实现上述操作。
 *
 * 算法思想:
 *   用 p 从头至尾扫描单链表，pre 指向 *p 结点的前驱。若p所指结点的值为x，则删除，并让p移向下一个结点，否则让pre、p指针同步后移一个结点。
 */
void Del_X_2(LinkList &L, ElemType x){
    LNode *pre=L, *p=L->next,*q;
    while(p){
        q = p->next;
        if(p->data==x){
            pre->next = q;    // 删除 p 节点
            free(p);
        }else{                // 否则， pre 和 p 同步后移
            pre = p;
        }
        p = q;
    }
}

/**
 * 3. 设 L 为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值。
 *
 * 算法思想:
 *    借助一个辅助栈，每经过一个结点时，将该结点放入栈中。遍历完整个链表后，再从栈顶开始输出结点值即可。
 */
void R_Print(LinkList L){
    LNode* p=L->next;
    SqStack<LNode*> s; InitStack(s);

    while(p){
        Push(s, p);
        p = p->next;
    }

    while(!StackEmpty(s)){
        Pop(s, p);
        std::cout<<p->data<<" ";
    }
    std::cout<<std::endl;
}

/**
 * 4. 试编写在带头结点的单链表 L 中删除一个最小值结点的高效算法(假设最小值结点是唯一的)。
 *
 * 算法思想:
 *       用 p从头至尾扫描单链表，
 *            pre指向*p结点的前驱，
 *            minp保存值最小的结点指针(初值为 p),
 *            minpre 指向*minp 结点的前驱(初值为 pre)
 *       一边扫描，一边比较，若 p->data 小于 minp->data，则将 p、 pre 分别赋值给 minp、 minpre，
 *       当 p扫描完毕,minp 指向最小值结点，minpre 指向最小值结点的前驱结点，再将 minp 所指结点删除即可 。
 */
LinkList Delete_Min(LinkList &L){
    if(!L || !L->next)
        return L;

    LNode *pre=L,*p=L->next;
    LNode *minpre=pre,*minp=p;

    while(p){
        if(p->data<minp->data){     // 找到比之前找到的最小值结点更小的结点
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    std::cout<<minp->data<<" ";
    minpre->next = minp->next;
    free(minp);
    return L;
}

/**
 * 5. 试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为 0(1)。
 *
 * 算法思想:
 *    将头结点摘下，然后从第一结点开始，依次插入到头结点的后面(头插法建立单链)，直到最后一个结点为止
 */
LinkList Reverse_1(LinkList &L){
    LNode* p=L->next, *q;       // p 为工作指针，q 为 p 的后继，以防断链
    L->next = NULL;             // 先将头结点 L 的 next 域置为 NULL

    while(p){                   // 依次将元素结点摘下
        q = p->next;            // 暂存 p 的后继
        p->next = L->next;      // 将 p 结点插入到头结点之后
        L->next = p;
        p = q;
    }
    return L;
}

/**
 * 6. 有一个带头结点的单链表 L，设计一个算法使其元素递增有序。
 *
 * 算法思想:
 *    采用直接插入排序算法的思想，先构成只含一个数据结点的有序单链表，然后依次扫描单链表中剩下的结点 *p(直至 p==NULL 为止)，
 *    在有序表中通过比较查找插入 *p 的前驱结点 *pre，然后将 *p 插入到 *pre 之后
 */
void Sort(LinkList &L){
    LNode *p=L->next, *q, *pre;                         // q保*p后继结点指针，以保证不断链
    L->next = NULL;                                     // 构造只含一个数据结点的有序表
    while(p){
        q = p->next;                                    // 保存*p 的后继结点指针

        pre = L;
        while(pre->next && pre->next->data<=p->data)    // 找到第一个比*p大的前一个节点
            pre = pre->next;

        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

/**
 * 7. 设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，
 *    删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素(若存在) 。
 */
void RangeDelete(LinkList &L, ElemType min, ElemType max){
    LNode *pre=L, *p=L->next,*q;
    while(p){
        if(min<=p->data && p->data<=max){
            pre->next = p->next;    // 删除 p 节点
            free(p);
            p = pre->next;
        }else{                      // 否则， pre 和 p 同步后移
            pre = p;
            p = p->next;
        }
    }
}

/**
 * 8. 给定 两个单链表，编写算法找出两个链表的公共结点。
 *
 * 算法思想:
 *    使用两个指针 L1，L2 分别指向两个链表 headA，headB 的头结点，然后同时分别逐结点遍历，
 *    当 L1 到达链表 headA 的末尾时，重新定位到链表 headB 的头结点；
 *    当 L2 到达链表 headB 的末尾时，重新定位到链表 headA 的头结点。
 *    这样，当它们相遇时，所指向的结点就是第一个公共结点。
 *
 * 链接：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/shuang-zhi-zhen-fa-lang-man-xiang-yu-by-ml-zimingm/
 * 来源：力扣（LeetCode）
 */
LinkList Search_Lst_Common(LinkList headA, LinkList headB){
    LinkList L1 = headA->next;  // 第1个节点
    LinkList L2 = headB->next;

    if(!L1 || !L2)
        return NULL;

    while(L1!=L2){
        L1 = (L1?L1->next:L2);
        L2 = (L2?L2->next:L1);
    }

    return L1;
}

/**
 * 9. 给定一个带表头结点的单链表，设 head 为头指针，结点结构为(data,next), data 为整型元素，next 为指针，试写出算法。
 *    按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间(要求: 不允许使用数组作为辅助空间)。
 */
void MinDelete(LinkList &head){
    while(head->next){
        Delete_Min(head);
    }
    free(head);
}

/**
 * 10.将一个带头结点的单链表 A 分解为两个带头结点的单链表 A 和 B，
 *    使得 A 表中含有原表中序号为奇数的元素，而 B 表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
 *
 * 算法思想: 设置一个访问序号变量(初值为 0)，每访问一个结点序号自动加1，然后根据序号的奇偶性将结点插入到 A 表或 B 表中。
 *          重复以上操作直到表尾。
 */
LinkList DisCreat_1(LinkList &A){
    LNode *p=A->next, *q;                       // p 为链表工作指针，指向分解的结点
    A->next = NULL;                             // 置空新的 A 表

    LNode *B = (LNode*)malloc(sizeof(LNode));
    B->next = NULL;

    LNode *pa=A,*pb=B;                          // pa和pb将分别指向将创建的A表和B表的尾结点

    int cnt = 1;
    while(p){                                   // (尾插法)
        if(cnt%2!=0){
            pa->next = p;                       // 在A表尾插入新结点
            pa = p;                             // pa 指向新的尾结点
        }else{
            pb->next = p;
            pb = p;
        }
        p = p->next;
        cnt++;
    }
    pa->next = NULL;
    pb->next = NULL;
    return B;
}

/**
 * 11.设 C ={σ1,b1,a2,b2,...an,bn} 为线性表，采用带头结点的 hc 单链表存放，设计一个就地算法，将其拆分为两个线性表，
 *    使得 A = {a1,a2,··· , an,}, B= {bn,bn-1,...,b2,b1}
 *
 *  算法思想: 采用上题的思路，二者的差别仅在于对 B 表的建立不采用尾插法，而是采用头插法。
 */
LinkList DisCreat_2(LinkList &A){
    LNode *p=A->next, *q;                       // p 为链表工作指针，指向分解的结点
    A->next = NULL;                             // 置空新的 A 表

    LNode *B = (LNode*)malloc(sizeof(LNode));
    B->next = NULL;

    LNode *pa=A;                                // pb将分别指向将创建的A表和B表的尾结点

    int cnt = 1;
    while(p){
        q = p->next;
        if(cnt%2!=0){
            pa->next = p;                       // 在A表尾插入新结点 (尾插法)
            pa = p;                             // pa 指向新的尾结点
        }else{
            p->next = B->next;                  // 在B表头插入新结点 (头插法)
            B->next = p;
        }
        p = q;
        cnt++;
    }
    pa->next = NULL;
    return B;
}

/**
 * 12.在一个递增有序的线性表中，有数值相同的元素存在。 若存储方式为单链表，设计算法去掉数值相同的元素，使表中不再有重复的元素，
 *    例如(7, 10, 10, 21, 30, 42, 42, 42, 51, 70) 将变为 (7, 10, 21, 30, 42, 51, 70)。
 *
 * 算法思想: 由于是有序表，所有相同值域的结点都是相邻的。用 p 扫描递增单链表 L，
 *          若 *p 结点的值域等于 *p 后继结点的值域，则删除后者，否则 p 移向下一个结点。
 *
 * 83. 删除排序链表中的重复元素
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
 */
void Del_Same(LinkList &L){
    LNode *pre=L->next;
    if(!pre)
        return;
    LNode *p=pre->next, *q;
    while(p){
        q = p->next;
        if(pre->data==p->data){
            pre->next = q;      // 释放*p结点
            free(p);
        }else{
            pre = p;
        }
        p = q;
    }
}

/**
 * 13.假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表，
 *    并要求利用原来两个单链表的结点存放归并后的单链表。
 *
 * 算法思想: 两个链表已经按元素值递增次序排序，将其合并时，均从第一个结点起进行比较，将小的结点链入链表中，同时后移工作指针。
 *          该问题要求结果链表按元素值递减次序排列，故新链表的建立应该采用头插法。比较结束后，可能会有一个链表非空，此时用头插法
 *          将剩下的结点依次插入新链表中即可。
 */
LinkList MergeList(LinkList La, LinkList Lb){
    LNode* Lc = (LNode*) malloc(sizeof(LNode));
    Lc->next = NULL;

    LNode* pa=La->next, *pb=Lb->next, *q;
    while(pa&&pb){
        if(pa->data<pb->data){
            q = pa->next;
            pa->next = Lc->next;            // 头插法
            Lc->next = pa;
            pa = q;
        }else{
            q = pb->next;
            pb->next = Lc->next;           // 将 pa 结点链于结果表中，同时逆置 (头插法〉
            Lc->next = pb;
            pb = q;
        }
    }
    if(pa)
        pb = pa;
    while(pb){
        q = pb->next;
        pb->next = Lc->next;
        Lc->next = pb;
        pb = q;
    }
    return Lc;
}

/**
 * 14.设A和B是两个单链表(带头结点)，其中元素递增有序。 设计一个算法从A和B中的公共元素产生单链表C，要求不破坏 A、B 的结点。
 *
 * 算法思想: 表 A、 B 都有序，可从第一个元素起依次比较 A、 B 两表的元素，
 *          若元素值不等，则值小的指针往后移，
 *          若元素值相等，则创建一个值等于两结点的元素值的新结点，使用尾插法插入到新的链表中，并将两个原表指针后移一位
 *          直到其中一个链表遍历到表尾。
 */
LinkList Get_Common(LinkList A, LinkList B){
    LNode* Lc = (LNode*) malloc(sizeof(LNode));
    Lc->next = NULL;

    LNode *pa=A->next, *pb=B->next, *pc=Lc, *q;
    while(pa&&pb){
        if(pa->data<pb->data){                  // 若 A 的当前元素较小，后移指针
            pa = pa->next;
        }else if(pa->data>pb->data){
            pb = pb->next;
        }else{                                  // 找到公共元素结点
            q = (LNode*)malloc(sizeof(LNode));
            q->data = pa->data;
            pc->next = q;                       // 将 *q 链接到 c 上(尾插法〉
            pc = q;

            pa = pa->next;
            pb = pb->next;
        }
    }
    pc->next = NULL;                            // 置 c 尾结点指针为空
    return Lc;
}

/**
 * 15.已知两个链表 A 和 B 分别表示两个集合，其元素递增排列。编制函数，求 A 与 B 的交集，并存放于 A 链表中。
 */
void Union(LinkList &A, LinkList &B){
    LNode *pa=A->next, *pb=B->next, *ra, *q;
    A->next = NULL;
    ra = A;

    while(pa&&pb){
        if(pa->data<pb->data){          // 若 A 的当前元素较小，后移指针
            q = pa;
            pa = pa->next;
            free(q);
        }else if(pa->data>pb->data){
            q = pb;
            pb = pb->next;
            free(q);
        }else{                          // 找到公共元素结点
            ra->next = pa;              // A 中结点链接到结果表
            ra = pa;
            pa = pa->next;

            q = pb;                     // B 中结点释放
            pb = pb->next;
            free(q);
        }
    }
    ra->next = NULL;                    // 置 A 尾结点指针为空

    if(pa)
        pb = pa;

    while(pb){                          // 释放 A 或 B 中剩余结点
        q = pb;
        pb = pb->next;
        free(q);
    }
    free(B);                            // 释放B表的头结点
}

/**
 * 16.两个整数序列 A ={a1,a2,··· , am} 和 B={b1,b2,...,bn} 已经存入两个单链表中,设计一个算法，判断序列 B 是否是序列 A 的连续子序列。
 *
 * 算法思想:
 *    从两个链表的第一个结点开始，若对应数据相等，则后移指针;
 *    若对应数据不等，则 A 链表从上次开始比较结点的后继开始，B链表仍从第一个结点开始比较，
 *    直到B链表到尾表示匹配成功；A链表到尾而B链表未到尾表示失败。
 */
int Pattern (LinkList A, LinkList B){ // 注意: 假设链表没有头结点
    LNode *prea=A,*pa=A, *pb=B;
    while(pa&&pb){
        if(pa->data==pb->data){     // 结点值相同,A、B同时移动
            pa = pa->next;
            pb = pb->next;
        }else{
            pb = B;                 // B 从链表第一个结点开始
            prea = prea->next;      // A 链表从上次开始比较结点的后继开始 ***
            pa = prea;
        }
    }
    return pb==NULL?1:0;
}

/**
 * 17.设计一个算法用于判断带头结点的循环双链表是否对称。
 *
 * 算法思想: 让 p 从左向右扫描， q 从右向左扫描，直到它们指向同一结点
 *          若它们所指结点值相同，则继续进行下去，否则返回 0。若比较全部相等，则返回 1。
 */
int Symmetry(DLinkList L){
    DNode *p=L->next,*r=L->prior;
    while(p!=r&&p->next!=r){            // 循环跳出条件 ***
        if(p->data==r->data){
            p = p->next;
            r = r->prior;
        }else
            return 0;
    }
    return 1;                           // 比较结束后返回 1
}

/**
 * 18.有两个循环单链表，链表头指针分别为 h1 和 h2，编写一个函数将链表 h2 链接到链表 h1 之后，要求链接后的链表仍保持循环链表形式。
 *
 * 算法思想: 先找到两个链表的尾指针，将第一个链表的尾指针与第二个链表的头结点链接起来，再使之成为循环的。
 */
LinkList Link(LinkList &h1 , LinkList &h2){ // 无头结点
    if(!h1 || !h2)
        return h1;
    LNode *p1=h1,*p2=h2;
    while(p1->next!=h1)     // 寻找 h1 的尾结点
        p1 = p1->next;
    while(p2->next!=h2)     // 寻找 h2 的尾结点
        p2 = p2->next;

    p1->next = h2;          // 将 h2 链接到 h1 之后
    p2->next = h1;;         // 令 h2 的尾结点指向 h1
    return h1;
}

/**
 * 19.设有一个带头结点的循环单链表，其结点值均为正整数。设计一个算法，反复找出单链表中结点值最小的结点并输出，然后将该结点从中删除，
 *    直到单链表空为止，再删除表头结点。
 */
void Del_All(LinkList &L){
    while(L->next){
        Delete_Min(L);
    }
    free(L);
}

/**
 * 20.设头指针为 L 的带有表头结点的非循环双向链表，其每个结点中除有 pred(前驱指针)、data(数据)和 next(后继指针)域外，
 *    还有一个访问频度域 freq。在链表被启用前，其值均初始化为零。每当在链表中进行一次 Locate(L,x)运算时，令元素值为 x
 *    的结点中 freq 域的值增 1，并使此链表中结点保持按访问频度非增(递减)的顺序排列，同时最近访问的结点排在频度相同的结点
 *    前面，以便使频繁访问的结点总是靠近表头。试编写符合上述要求的 Locate(L,x) 运算的算法，该运算为函数过程，返回找到结
 *    点的地址，类型为指针型。
 *
 * 算法思想: 首先在双向链表中查找数据值为 x 的结点，查到后，将结点从链表上摘下，然后再顺着结点的前驱链查找该结点的
 *          插入位置(频度递减，且排在同频度的第一个，即向前找到第一个比它的频度大的结点，插入位置为该结点之后)，并插入到该位置 。
 */
DLinkList Locate(DLinkList &L, ElemType x){ // x的值需唯一...
    DNode *p=L->next,*q,*pre=L;
    while(p && p->data!=x)
        p = p->next;

    if(!p) return NULL;                 // 没找到值为 x 的结点
    p->freq += 1;                       // 令元素值为 x 的结点的 freq域加 1

    if(p->next)                         // 将 p 结点从链表上摘下
        p->next->prior = p->prior;
    p->prior->next = p->next;

    q = p->prior;
    while(q!=L && q->freq<=p->freq)     // 查找 p 结点的插入位置 (向前找到第一个比它的频度大的结点，插入位置为该结点之后)
        q = q->prior;

    p->next = q->next;                  //将 p 结点插入，一定是排在同频率的第一个
    q->next->prior = p;
    p->prior = q;
    q->next = p;

    return p;                           // 返回值为 x 的结点的指针
}

/**
 * 21.「2009」已知一个带有表头结点的单链表，结点结构为 |data|link|，假设该链表只给出了头指针 list。
 *     在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第 k 个位直上的结点(k为正整数)。
 *     若查找成功，算法输出该结点的 data 域的值，并返回1；否则，只返回0。
 *
 * 算法思想:
 *     定义两个指针变量 pre 和 p，初始时均指向头结点的下一个结点(链表表的第一个结点)， p 指针沿链表移动;
 *     当 p 指针移动到第 k 个结点时， pre 指针开始与 p 指针同步移动;
 *     当 p 指针移动到最后一个结点时， pre 指针所指示结点为倒数第 k个结点。
 */
int Search_k(LinkList list, int k){
    LNode *pre=list->next, *p=list->next;   // 指针 pre、 p 指示第一个结点
    while(p){                   // 遍历链表直到最后一个结点
        if(k>0){                // 只移动 p
            k--;
        }else{
            pre = pre->next;    // pre、p 同步移动
        }
        p = p->next;
    }
    if(k==0 && pre){
        std::cout<<pre->data<<std::endl;
        return 1;
    }else{
        return 0;           // 查找失败返回 o
    }
}

/**
 * 22.【2012】假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，可共享相同的后缀存储空间，
 *     例如，“loading”和“being”的存储映像如下图所示。设 str1 和 str2 分别指向两个单词所在单链表的头结点，
 *     链表节点结构为 |data|next|，请设计一个时间上尽可能高效的算法，找出由 str1 和 str2 所指向两个链表共同后缀的起始位置。
 *
 *  算法思想: 采用双指针法。
 *      用指针 p1、p2 分别扫描 str1 和 str2，当 p1、p2 指向同一个地址时，即找到共同后缀的起始位置。
 */
LNode* find_addr(LNode *str1 , LNode *str2){
    LNode *p1=str1->next, *p2=str2->next;
    if(!p1 || !p2)
        return NULL;
    while(p1!=p2){
        p1 = p1?p1->next:p2;
        p2 = p2?p2->next:p1;
    }
    return p1;
}

/**
 * 23.【2015】用单链表保存 m 个整数，结点的结构为 [data][link]，且 |data|<=n (n 为正整数)。现要求设计一个时间复杂度尽可能高效的算法，
 *     对于链表中 data 的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。
 *
 * 算法思想: 用空间换时间。
 *     使用辅助数组记录链表中已出现的数值，从而只需对链表进行一趟扫描。因为 |data|<=n，故辅助数组 q 的大小为 n+1，各元素的初值均为 0。
 *     依次扫描链表中的各结点，同时检查 q[|data|] 的值，若为 0 则保留该结点，井令 q[ldatal]=1；否则将该结点从链表中删除。
 */
void func(LNode* &h, int n){     // 带头结点
    int tag[n+1];               // 初始化数组并赋初值0
    for(int i=0; i<=n; i++)
        tag[i]=0;

    LNode *p=h->next,*pre=h,*q;
    while(p){
        ElemType e = p->data>0?p->data:-p->data;    // |data|
        if(tag[e]==0){
            tag[e] = 1;                             // 首次出现
            pre->next = p;                          // 尾插法新建链表、保留该节点
            pre = p;
            p = p->next;
        }else{
            q = p;                                  // 删除重复节点
            p = p->next;
            free(q);
        }
    }
    pre->next = NULL;                               // 链尾置空
}

/**
 * 24.设计一个算法完成以下功能:判断一个链表是否有环，如果有，找出环的入口点并返回，否则返回 NULL。
 *
 * 算法思想:
 *  1. 判断链表中是否有环：
 *    设置快慢两个指针分别为 fast 和 slow，初始时都指向链表头 head。
 *    ① 即 slow=slow->next; fast每次走两步，即 fast=fast->ηext->next。
 *    ② 由于 fast 比 slow 走得快，如果有环，fast 一定会先进入环，而 slow 后进入环。
 *    ③ 当两个指针都进入环后，经过若干次操作后两个指针定能在环上相遇。即可判断一个链表是否有环。
 *
 *  2. 设头结点到环的入口点的距离为 a，环的入口点沿着环的方向到相遇点的距离为 x，环长为 r，相遇时 fast 绕过了 n 圈。
 *     则 2(a+x)=a+nr+x
 *        => a=nr-x=(r-x)+(n-1)r，即从头结点到环的入口点的距离等于 n 倍的环长减去环的入口点到相遇点的距离。
 *     因此可设置两个指针，一个指向head，一个指向相遇点，两个指针同步移动(均为一次走一步)，相遇点即为环的入口点。
 *
 * https://leetcode-cn.com/problems/linked-list-cycle/
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
 */
LNode* FindLoopStart(LNode *head){  // 无头结点
    LNode *slow=head, *fast=head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)                                  // 快慢指针相遇
            break;
    }

    if(slow==NULL || fast==NULL || fast->next==NULL)    // 没有环，返回 nulptr
        return NULL;

    LNode *p1=head, *p2=slow;                           // 分别指向开始点、相遇点
    while(p1!=p2){                                      // 2(a+x) =a+nr+x，即 a=nr-x=(r-x)+(n-1)r，n>=1
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

/**
 * 25.【2019】设线性表 L = {a1,a2,··· ,an},采用带头结点的单链表保存，请设计一个空间复杂度为 O(1) 且时间上尽可能高效的算法，
 *     重新排列 L 中的各结点，得到线性表 L2 = {a1,an,a2,an-1,a3,an-2,···}。
 *
 * 算法思想:
 *      先将 L后半段原地逆置 [题目要求空间复杂度为 0(1)，不能借助栈]，否则每取最后一个结点都需要遍历一次链表。
 *       ① 先找出链表L的中间结点，为此设置两个指针p和q，
 *          指针p每次走一步，指针 q 每次走两步，当指针 q 到达链尾时，指针 p 正好在链表的中间结点
 *       ② 然后将 L 的后半段结点原地逆置。
 *       ③ 从单链表前后两段中依次各取一个结点
 *
 * https://leetcode-cn.com/problems/middle-of-the-linked-list
 */
void change_list(LNode* &h){
    if(!h->next)
        return;
    LNode *slow=h, *fast=h;                 // 链表第1个节点，保证节点数为2n+1时中点为第n+1个
                                            //                 节点数为2n时中点为第n个)
    while(slow && fast && fast->next){      // 找到链表中点 *slow
        slow = slow->next;                  // p 走一步
        fast = fast->next->next;
    }

    LNode *q=slow->next, *p,*r;             // q 为后半段链表的首结点
    slow->next = NULL;
    while(q){                               // 头插法逆置后半段链表
        p = q->next;
        q->next = slow->next;
        slow->next = q;
        q = p;
    }

    p = h->next;                            // p 为前半段链表的首结点
    q = slow->next;                         // q 为后半段链表的首结点
    slow->next=NULL;                        // 前半段最后一个节点置空

    while(q){                               // 将链表后半段的结点插入到指定位置
        r = q->next;
        q->next = p->next;                  // 将q所指结点插入到p所指结点之后
        p->next = q;
        p = q->next;                        // p 指向前半段的下一个插入点
        q = r;
    }
}
