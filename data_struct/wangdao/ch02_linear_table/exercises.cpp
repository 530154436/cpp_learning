//
// Created by 郑楚彬 on 2020/9/3.
//
#include "exercises.hpp"

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
 */
//int MSearch(int A[],int B[],int n){
//
//}
/**
 * 12.【2013】已知一个整数序列 A =(a0，a1，..., an-1)，其中 0≤ai<n (0≤i<n)。 若存在
 *    ap1 = ap2 =...= apm = x 且 m>n/2 (0≤pk<n，1≤k≤m)，则称 x 为 A 的主元素。
 *    例如A= ( 0，5，5，3，5，7，5，5 )，则 5 为主元素；又如 A= ( 0，5，5，3，5，1，5，7 )，
 *    则A 中没有主元素。假设 A 中的 n 个元素保存在一个一维数组中，请设计一个尽可能高效的算法，
 *    找出 A 的主元素。若存在主元素， 则输出该元素；否则输出-1。要求：
 *  (1) 给出算法的基本设计思想。
 *  (2) 根据设计思想，采用 C 或 C++或 Java 语言描述算法，关键之处给出注释。
 *  (3) 说明你所设计算法的时间复杂度和空间复杂度。
 */
//int Majority (int A[], int n){
//
//}

/**
 * 13.【2018】给定一个含 n (n>=1)个整数的数组，请设计一个在时问上尽可能高效的算法，找出数组中未出现的最小正整数。
 *     例如，数组 {-5，3, 2, 3} 中未出现的最小正整数是1; 数组 {1,2,3} 中未出现的最小正整数是 4。
 */
//int findMissMin(int A[] , int n){
//
//}


/**
 * 1. 设计一个递归算法, 删除不带头结点的单链表 L 中所有值为 x 的结点。
 */

/**
 * 2. 在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，假设值为 x 的结点 不唯一，试编写算法以实现上述操作。
 */

/**
 * 3. 设 L 为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值。
 */

/**
 * 4. 试编写在带头结点的单链表 L 中删除一个最小值结点的高效算法(假设最小值结点是唯一的)。
 */

/**
 * 5. 试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为 0(1)。
 */

/**
 * 6. 有一个带头结点的单链表 L，设计一个算法使其元素递增有序。
 */

/**
 * 7. 设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，
 *    删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素(若存在) 。
 */

/**
 * 8. 给定 两个单链表，编写算法找出两个链表的公共结点。
 */

/**
 * 9. 给定一个带表头结点的单链表，设 head 为头指针，结点结构为(data,next), data 为整型元素，next 为指针，试写出算法。
 *    按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间(要求: 不允许使用数组作为辅助空间)。
 */

/**
 * 10.将一个带头结点的单链表 A 分解为两个带头结点的单链表 A 和 B，
 *    使得 A 表中含有原表中序号为奇数的元素，而 B 表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
 */





























