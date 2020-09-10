//
// Created by 郑楚彬 on 2020/9/3.
//
#include "exercises.hpp"

/**
 * 4. 设单链表的表头指针为 L，结点结构由 data 和 next 两个域构成，其中 data 域为字符型。
 *    试设计算法判断该链表的全部 n 个字符是否中心对称。例如 xyx、 xyyx 都是中 心对称。
 *
 * 算法思想:
 *      使用栈来判断链表中的数据是否中心对称。
 *      (1) 让链表的前一半元素依次进栈。
 *      (2) 在处理链表的后一半元素时，当访问到链表的一个元素后，就从栈中弹出一个元素，两个元素比较，若相等， 则将链表中的下一个元素与栈中再弹出的元素比较，直至链表到尾。
 *      (3) 这时若栈是空栈，则得出链表中心对称的结论; 否则，当链表中的一个元素与栈中弹出元素不等时，结论为链表非中心对称，结束算法的执行。
 */
int dc(LNode<char> *L, int n){    // L:带头结点的 n 个元素单链表
    SqStack<char> s; InitStack(s);
    char item;
    LNode<char> *p = L->next;

    for(int i=0; i<n/2; i++){      // 链表前一半元素进找
        Push(s, p->data);
        p = p->next;
    }

    if(n%2==1)                      // 若 n 是奇数，后移过中心结点
        p = p->next;

    while(p){                       // 检测是否中心对称
        Pop(s, item);
        if(item!=p->data)
            return 0;
        p = p->next;
    }

    return StackEmpty(s)?1:0;       // 栈为空，链表中心对称
}

/**
 * 5. 设有两个找 s1、 s2 都采用顺序栈方式，并共享一个存储区[0,..,maxsize-1]，为了尽量利用空间，
 *    减少溢出的可能，可采用拽顶相向、迎面增长的存储方式。试设计 s1、 s2 有关入栈和出找的操作算法。
 */
sstk s; // 栈顶 top1、top2 初始化为 -1、Maxsize

int push(ElemType i, ElemType x){         // i=0 表示左边的 s1 栈， i=1 表示右边的 s2 栈， x 是入栈元素
    if(i<0||i>1)
        return 0;
    if(s.top[0]==s.top[1]+1)    // 栈满
        return 0;

    switch(i){
        case 0: s.data[++s.top[0]] = x;    // s1 入栈
            break;
        case 1: s.data[--s.top[1]] = x;    // s2 入栈
        default:
            break;
    }
    return 1;
}

int pop (ElemType i){
    if(i<0||i>1)
        return 0;
    if(s.top[i]==-1)        // 栈空
        return 0;

    switch(i){
        case 0:
            return s.data[s.top[0]--];    // s1 出栈
        case 1:
            return s.data[s.top[1]++];    // s2 出栈
        default:
            return 0;
    }
}

/*
 * 练习 3.2 队列
 */
/**
 * 1. 若希望循环队列中的元素都能得到利用，则需设直一个标志域 tag， 并以 tag 的值为 0 或 1 来区分队
 *    头指针 front 和队尾指针 rear 相同时的队状态是“空”还是“满”。 试编写与此结构相应的入队和出队算法。
 *
 * 算法思想:
 *      在循环队列的类型结构中，增设一个 tag 的整型变量，进队时置 tag 为 1， 出队时置 tag 为 O
 *      (因为只有入队操作可能导致队满，也只有出队操作可能导致队空)。队列 Q 初始时，置 tag=O、 front=rear=O。
 */
int tEnQueue(tqueue &s, ElemType x){
    if(s.front==s.rear && s.tag==1) // 两个条件都满足时则队满
        return 0;
    s.data[s.rear] = x;
    s.rear = (s.rear+1) % MaxStackSize;
    s.tag=1;
    return 1;
}

int tDeQueue(tqueue &s, ElemType &x){
    if(s.front==s.rear && s.tag==0)
        return 0;
    x = s.data[s.front];
    s.front = (s.front+1) % MaxStackSize;
    s.tag = 0;
    return 1;
}

/**
 * 2. Q 是一个队列，S 是一个空栈，实现将队列中的元素逆置的算法。
 *
 * 算法思想:
 *      让队列中的元素逐个地出队列，入栈; 全部入栈后再逐个出栈，入队列。
 */
void Inverse(SqQueue<ElemType> &Q, SqStack<ElemType> &S){
    int p;
    while(!QueueEmpty(Q)){
        DeQueue(Q, p);          // 队列中全部元素依次出队
        Push(S, p);             // 元素依次入栈
    }
    while(!StackEmpty(S)){
        Pop(S, p);              // 栈中全部元素依次出栈
        EnQueue(Q, p);          // 再入队
    }
}

/**
 * 3. 利用两个栈 S1, S2 来模拟一个队列，已知栈的 4 个运算定义如下:
 *      Push(S, x);
 *      Pop (S , x);
 *      StackEmpty(S);
 *      StackOverflow(S);
 *    如何利用找的运算来实现该队列的 3 个运算
 *      Enqueue;
 *      Dequeue;
 *      QueueEmpty;
 *
 *  算法思想:
 *      1)对 S2 的出栈操作用做出队，若 S2 为空，则先将 S1 中的所有元素送入 S2。
 *      2)对 S1 的入栈操作用做入队，若 S1 满， 必须先保证 S2 为空，才能将 S1 中的元素全部插 入 S2 中。
 *
 *  面试题09. 用两个栈实现队列
 *  链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
 */
int EnSSQueue(SSQueue &q, ElemType x){
    if(StackOverflow(q.S1) && !StackEmpty(q.S2))    // 队列满
        return 0;

    if(StackOverflow(q.S1) && StackEmpty(q.S2)){    // S1栈满且S2为空，将 S1 中的所有元素送入 S2
        while(!StackEmpty(q.S1)){
            Pop(q.S1, x);
            Push(q.S2, x);
        }
    }

    Push(q.S1, x);                                  // 此时 S1 不满
    return 1;
}

int DeSSQueue(SSQueue &q, ElemType &x){
    if(StackEmpty(q.S1) && StackEmpty(q.S2))        // 队空
        return 0;

    if(!StackEmpty(q.S1) && StackEmpty(q.S2)){      // S1不为空，S2为空
        while(!StackEmpty(q.S1)){
            Pop(q.S1, x);
            Push(q.S2, x);
        }
    }

    Pop(q.S2, x);                                   // 此时 S2 不空
    return 1;
}

int SSQueueEmpty(SSQueue q){
    return StackEmpty(q.S1) && StackEmpty(q.S2);
}

/*
 * 3.3 核和队列的应用 p96-97
 */
/**
 * 1. 假设一个算术表达式中包含圆括号、方括号和花括号 3 种类型的括号，编写一个算法来判别表达式中的括号是否配对，
 *    以字符“\0”作为算术表达式的结束符。
 *
 * 20. 有效的括号
 * 链接：https://leetcode-cn.com/problems/valid-parentheses
 */

/**
 * 3. 利用一个找实现以下递归函数的非递归计算:
 *              1,                              n=0
 *    P_n(x) =  2x,                             n=1
 *              2xP_{n-1}(x)-2(n-1)P_{n-2}(x),  n>1
 */

/*
 * 思维拓展
 */
/**
 * 1. 设计一个栈，使它可以在O(1)的时间复杂度内实用 Push、 Pop和min操作。所谓min操作，是指得到栈中最小的元素。
 *
 * 面试题30. 包含min函数的栈
 * 链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
 */

