//
// Created by 郑楚彬 on 2018/4/2.
//

#include "../utility/Stack/LinkedStack.h"
#include "../utility/Stack/SqStack.h"

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
    printArray("表达式", exp, 11);
    printf("%d\n", result);
}

/**
 * 例题 2.编写一个函数，求后缀式的数值，其中后缀式存于一个字符数组 exp 中，
 *       exp 中最后一个字符为‘\0’，作为结束符，并且假设后缀式中的数字都只有一位。
 * 思路:
 *     当遇到数值的时候入栈，当遇到运算符的时候，连续两次出栈，将两个出栈 元素结合运算符进行运算。
 *     将结果当成新遇到的数值入栈。如此往复，直到扫描到终止符 ‘\0’,此时栈底元素值即为表达式的值。
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
            printf("%d\n", c);
        }
    }
    return stack[top];
}

void test02(){
    // 14
    //char exp[20] = {'5', '1', '2', '+', '4', '*', '+', '3', '-', '\0'};
    // 29
    char exp[20] = {'3','4','+','5','*','6','-', '\0'};
    int result = com(exp);
    printf("%d\n", result);
}

int main(){
    // test01();
    test02();
}