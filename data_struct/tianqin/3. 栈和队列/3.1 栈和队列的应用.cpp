//
// Created by Edward on 2018/4/2.
//

#include "../utility/Stack/LinkedStack.h"
#include "../utility/Stack/SqStack.h"
#include "../utility/Stack/SharedStack.h"
#include "../utility/LinearTable/LinkedList.h"
#include <math.h>

/**
 * 例题 1 c语言里算术表达式中的括号只有小括号。编写算法，判断一个表达式中的括号是否正确配对，
 *       表达式已经存入字符数组 exp[]中(元素从数组下标 1 开始存储)，表达式中的字符个数为 n。
 */
int match(char exp[], int n){
    // 两句完成栈的声明和初始化
    char stack[100]; int top=-1;
    int i;
    for(i=1; i<n; i++){
        if(exp[i]=='('){
            // 如果遇到“(”则入栈等待以后处理
            stack[++top] = '(';
        }
        if(exp[i]==')'){
            // 如果当前遇到的括号是“)”且栈已空，则不匹配，返回 0
            if(top==-1){
                return 0;
            }else{
                top--; // 如果栈不空则出栈
            }
        }
    }
    if(top==-1){
        //栈空，即所有括号都被处理掉则说明括号是匹配的
        return 1;
    }else{
        return 0;
    }
}

int test01(){
    char exp[11] = {'*', '(', '(', '(', ')', ')', '+', '-', ')', '(', ')'};
    int result = match(exp, 11);
    printf("表达式 %s", exp);
    printf("%d\n", result);
}

/**
 * 例题 2.编写一个函数，求后缀式的数值，其中后缀式存于一个字符数组 exp 中，
 *       exp 中最后一个字符为‘\0’，作为结束符，并且假设后缀式中的数字都只有一位。
 * 思路:
 *     当遇到数值的时候入栈，当遇到运算符的时候，连续两次出栈，将两个出栈 元素结合运算符进行运算。
 *     将结果当成新遇到的数值入栈。如此往复，直到扫描到终止符 ‘\0’,此时栈底元素值即为表达式的值。
 */

/**
 * 代数运算函数
 * @param a
 * @param Op
 * @param b
 * @return
 */
int op(int a, char Op, int b){
    // 函数是运算函数，来完成算式a Op b的运算。
    if(Op == '+') return a+b;
    if(Op == '-') return a-b;
    if(Op == '*') return a*b;
    if(Op == '/'){
        if(b==0){
            printf("ERROR");
            return 0;
        } else{
            return a/b;
        }
    }
}

/**
 * 后缀表达式求值
 * 从左向右扫描表达式
 *
 * @param exp
 * @return
 */
int com(char exp[]){
    int i,a,b,c;
    // 定义栈
    int stack[Max]; int top=-1;
    char operation;
    for(i=0; exp[i]!='\0'; i++){
        if('0'<=exp[i] && exp[i]<='9'){
            // 字符型和整形的转换，入栈
            stack[++top] = exp[i] - '0';
        }else{
            // 取第二个操作数(因为第二个操作数后入栈
            b = stack[top--];
            operation = exp[i];
            // 取第一个操作数。
            a = stack[top--];
            // 将两个操作数结合运算符 Op 进行运算，结果保存在 c 中
            c = op(a, operation, b);
            // 运算结果入栈
            stack[++top] = c;
        }
    }
    return stack[top];
}

/**
 * 前缀表达式求值
 * 从右向左扫描表达式
 *
 * @param exp
 * @param len
 * @return
 */
int com(char exp[], int len){
    int i,a,b,c;
    // 定义栈
    int stack[Max]; int top=-1;
    char operation;
    // 从右向左扫描表达式
    for(i=len-1; i>=0; i--){
        if('0'<=exp[i] && exp[i]<='9'){
            // 字符型和整形的转换，入栈
            stack[++top] = exp[i] - '0';
        }else{
            // 取第第一个操作数(因为第一个操作数后入栈)
            a = stack[top--];
            operation = exp[i];
            // 取第二个操作数。
            b = stack[top--];
            // 将两个操作数结合运算符 Op 进行运算，结果保存在 c 中
            c = op(a, operation, b);
            // 运算结果入栈
            stack[++top] = c;
        }
    }
    return stack[top];
}

void test02(){
    // 5+((1+2)*4)−3 = 14
    // (3+4)*5-6 = 29

    // 后缀表达式
    char exp[20] = {'5', '1', '2', '+', '4', '*', '+', '3', '-', '\0'};
    // char exp[20] = {'3','4','+','5','*','6','-', '\0'};
    int result = com(exp);
    printf("%d\n", result);

    // 前缀表达式
    char exp1[20] = {'-', '+', '5', '*', '+', '1', '2', '4', '3'};
    // char exp1[20] = {'-', '*', '+', '3', '4', '5', '6'};
    int result1 = com(exp1, 9);
    printf("%d\n", result1);
}

/**
 * 中缀表达式转成后缀表达式
 */

/**
 * 求操作符的优先级
 * @param c     操作符
 * @param flag  1: 在栈中， 0: 不在栈中
 * @return
 */
int getPrecedence(char c, int flag){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            // 左括号比较特殊，在栈外优先级高，在栈顶优先级低
            if(flag==0){
                return 3;
            }else{
                return 0;
            }
        default:
            printf("ERROR: Invalid character.");
            return -1;
    }
}

/**
 * 判断是否为操作符
 * @param c
 * @return
 */
int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')'){
        return 1;
    }else{
        return 0;
    }
}

char* infix2Postfix(char *ch){
    // 输出栈
    char output[Max];
    int outputTop = -1;

    // 操作符栈
    char operators[Max];
    int top = -1;

    char c;
    while((c=*ch) != '\0'){
        // 操作数，直接输出
        if(!isOperator(c)){
            output[++outputTop] = c;
            ch++;
        // 操作符
        }else{
            // 栈为空，遇到运算符，入栈
            if(top == -1){
                operators[++top] = c;
                ch++;
            } else{
                if(c == ')'){
                    // ﻿遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出
                    while(top!=-1 && operators[top]!='('){
                        output[++outputTop] = operators[top--];
                    }
                    // '(' 出栈，但不输出
                    operators[top--];
                    ch++;
                } else{
                    char outPrecedence = getPrecedence(c, 0);
                    // ﻿栈不为空，并且栈顶元素大于或等于该运算符则弹出
                    while(top!=-1 && getPrecedence(operators[top], 1) >= outPrecedence){
                        output[++outputTop] = operators[top--];
                    }
                    operators[++top] = c;
                    ch++;
                }
            }
        }
    }
    // 将栈中剩余的元素弹出
    while(top!=-1){
        output[++outputTop] = operators[top--];
    }
    output[++outputTop] = '\0';
    return output;
}

void test03(){
    // char* exp = "5+((1+2)*4)-3";
    // char* exp = "(3+4)*5-6";
    // char* exp = "1+((2+3)*4)-5";
    char* exp = "a+b-a*((c+d)/e-f)+g";
    char* output = infix2Postfix(exp);
    printf("中缀表达式 %s\n", exp);
    printf("后缀表达式 %s\n", output);
}

/*============================= 真题仿造 =============================*/
/**
    2. 请利用两个栈 S1 和 S2 来模拟一个队列，假设栈中元素为 int 型，栈中元素最多为 MAX。
       已知栈的三个运算定义如下:
            PUSH(ST,x):元素 x 入 ST 栈;
            POP(ST,&x):ST 栈顶元素出栈，赋给变量 x;
            Sempty(ST):判 ST 栈是否为空。
       如何利用栈的运算来实现该队列的三个运算:
            enqueue:元素入队列;
            dequeue:元素出队列;
            queue_empty:判断队列是否为空，空返回 1 不，空返回 0。
    要求: (1)给出基本设计思想。
         (2)根据设计思想，采用 C 或 C++语言描述算法，关键之处给出注释。
 */

/**
    3. 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾结点，但不设头 指针，
       请写出相应的入队列和出队列算法。
 */
void enQueue(LNode *&rear, int &x){
    LNode *p = (LNode *) malloc(sizeof(LNode *));
    p->data = x;
    p->next = rear->next;
    rear->next = p;
    rear = p;
}

int deQueue(LNode *&rear, int &x){
    // 队列为空
    if(rear->next = rear)
        return 0;
    // 待删除节点
    LNode *first = rear->next->next;
    rear->next->next = first->next;
    x = first->data;

    //如果元素出队后队列为空需要特殊处理
    if(first == rear){
        rear = rear->next;
    }
    free(first);
    return 1;
}

/**
 *  4. 如果允许在循环队列的两端都可以进行插入和删除操作。要求:
 *   (1) 写出循环队列的类型定义;
 *   (2) 写出“从队尾删除”和“从队头插入”的算法。
 */
typedef struct deque{
    int data[MAX];
    int front;
    int rear;
}deque;


/*
 *  算法实现“从队头插入”元素 x。
 */
int enCycQueue(deque &cyc, int x){
    // 判断队满
    if(cyc.rear == (cyc.front-1+MAX) % MAX){
        return 0;
    }
    cyc.data[cyc.front] = x;
    cyc.front = (cyc.front-1+MAX) % MAX;
    return 1;
}

/*
 * 算法实现“从队尾删除”，若删除成功用 x 接纳删除元素，返回 1，否则返回 0。
 */
int deQueue(deque &cyc, int &x){
    // 判断队空
    if(cyc.front == cyc.rear){
        return 0;
    }
    x = cyc.data[cyc.rear];
    cyc.rear = (cyc.rear-1+MAX) % MAX;
    return 1;
}

/**
 * 5.设计一个循环队列，用 front 和 rear 分别作为队头和队尾指针，另外用一个标志 tag 表示队列是空还是不空，
 *   约定当 tag 为 0 时队空，当 tag 为 1 时队不空，这样就可以 用 front==rear 作为队满的条件。
 *   要求设计队列的结构和相关基本运算算法(队列元素 为 int 型)
 */
typedef struct TagQueue{
    int tag;
    int data[MAX];
    int front;
    int rear;
}TagQueue;

/*
 * 初始化
 */
void init(TagQueue &tq){
    tq.tag = 0;
    tq.front = tq.rear = 0;
}

/*
 * 判断队空
 */
int isTQEmpty(TagQueue &tq){
    if(tq.front==tq.rear && tq.tag==0){
        return 1;
    }else{
        return 0;
    }
}

/*
 * 判断队满
 */
int isTQFull(TagQueue &tq){
    if(tq.front==tq.rear && tq.tag==1){
        return 1;
    }else{
        return 0;
    }
}

/*
 * 进队
 */
int enTQ(TagQueue &tq, int x){
    if(isTQFull(tq)==1){
        return 0;
    }else{
        tq.rear = (tq.rear+1) % MAX;
        tq.data[tq.rear] = x;
        // 只要进队就把 tag 设置为 1
        tq.tag = 1;
        return 1;
    }
}

/*
 * 出队
 */
int deTQ(TagQueue &tq, int &x){
    if(isTQEmpty(tq)){
       return 0;
    }else{
        tq.front = (tq.front+1+MAX) % MAX;
        x = tq.data[tq.front];
        // 只要有元素出队，就把 tag 设置为 0
        tq.tag==0;
        return 1;
    }
}

/**
 * (9) 编写一个算法。将一个非负的十进制数 N 转化为一个二进制数
 */
int transform(int N, int p){
    int data[100];
    int top = -1;

    while(N!=0){
        data[++top] = N%p;
        N = N/p;
    }

    int result=0;
    while(top!=-1){
        // 进制转换
        result = result*10 + data[top--];
    }
    return result;
}


void test05(){
    int N=6, p=2, result;
    printf("%d转%d进制:", N, p);
    result = transform(N, p);
    printf(" %d ", result);
}

/**
 * (10) 编写一个算法，检查一个程序中的花括号，方括号和圆括号是否配对，若能够全部配对则返回1，否则返回0。
 * 对于一对单引号或双引号内的字符不进行括号配对检查。39-单引号，34-双引号.
 */
int bracketsCheck(char chars[]){
    char *p =chars, ch;
    char stack[100];
    int top = -1;
    while(*p != '\0'){
        if(*p == 34){
            p++;
            while(*p != 34){
                p++;
            }
            p++;
        }else if(*p == 39){
            p++;
            while(*p != 39){
                p++;
            }
            p++;
        }else{
            switch(*p){
                case '(':
                case '[':
                case '{':
                    stack[++top] = *p;
                    p++;
                    break;
                case ')':
                    if(stack[top] == '('){
                        top--;
                        return 1;
                    }else{
                        return 0;
                    }
                case '}':
                    if(stack[top] == '{'){
                        top--;
                        return 1;
                    }else{
                        return 0;
                    }
                case ']':
                    if(stack[top] == '['){
                        top--;
                        return 1;
                    }else{
                        return 0;
                    }

            }
        }
        p++;
    }
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

/*============================= 真题仿造 =============================*/

/*=============================  思考题  =============================*/
/**
 * (1) 求解二次方根 根号A 的迭代函数如下：
 *    式中，p是 A的近似二次方根，e是结果允许误差。试写出相应的递归算法和非递归算法。(绝对值函数fabs()可直接调用)
 */
int sqrt1(float A, float p, float e){
    // 递归
    if(fabs(p*p -A) < e){
        return p;
    }else{
        return sqrt1(A, (p+A/p)/2, e);
    }
}

int sqrt2(float A, float p, float e){
    // 非递归
    while(fabs(p*p -A) >= e){
        p = (p+A/p)/2;
    }
    return p;
}

/**
 * (2) 设计一个递归算法求 n 个不同字符的所有全排序列。
 *
 *  全排列就是从第一个数字起每个数分别与它后面的数字交换
 */
void perm2(char str[], int k, int n){
    int i,j;
    char tmp;
    if(k==n){
        for(j=0; j<=n-1; j++){
            cout<<str[j];
        }
        cout<<endl;
    }else{
        for(i=k; i<n; i++){
            // 交换
            tmp = str[k];
            str[k] = str[i];
            str[i] = tmp;
            // cout<<str[k]<<','<<str[i]<<endl;

            // 递归调用
            perm2(str, k+1, n);

            //换过去后再还原
            tmp = str[i];
            str[i] = str[k];
            str[k] = tmp;
            // cout<<str[k]<<','<<str[i]<<endl;
        }
    }
}

void test06(){
    char ch[100]={'1', '2', '3','4'};
    perm2(ch, 0, 4);
}

/**
 * 计算卡特兰数
 */
int countCatalan(int n){
    if(n==0 || n==1){
        return 1;
    }
    // 必须初始化
    int sum=0;
    for(int i=0; i<n; i++){
        sum += countCatalan(i) * countCatalan(n-1-i);
    }
    return sum;
}

void test07(){
    for(int i=0; i<10; i++){
        cout<< countCatalan(i)<<endl;
    }
}

/*
  判读是否为合法出栈序列

【思路】借用一个辅助的栈，遍历压栈顺序，先将第一个放入栈中，这里是1，然后判断栈顶元素是不是出栈顺序的第一个元素，
      若不是则继续压栈，直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移动一位，直到不相等，这样循环等压栈顺序
      遍历完成，如果辅助栈还不为空，说明弹出序列不是该栈的弹出顺序。
 */
/**
 *
 * @param input  入栈序列
 * @param output 出栈序列
 * @param n      元素个数
 * @return
 */
int checkPopSequence(int* input, int* output, int n){
    int stack[n];
    int top = -1;
    int outputIndex = 0;
    for(int i=0; i<n; i++){
        stack[++top] = input[i];
        // 辅助栈不为空，且栈顶元素与输出序列一致
        while(top!=-1 && stack[top]==output[outputIndex]){
            top--;
            outputIndex++;
        }
    }
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

void test08(){
    int input[5] = {1,2,3,4,5};
    int output[5] = {4,5,3,2,1};
    int error[5] = {4,3,5,1,2};
    cout << checkPopSequence(input, output, 5)<<endl;
    cout << checkPopSequence(input, error, 5)<<endl;
}
/*=============================  思考题  =============================*/


int main(){
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    test08();
}