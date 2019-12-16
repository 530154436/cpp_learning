//
// Created by 郑楚彬 on 2019/12/16.
//
#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;
}

void display(const vector<int> *vec){
    if (!vec){
        cout<<"display(): The vector pointer is 0.\n";
    }
    for(int i=0; i<vec->size(); i++){
        cout<<(*vec)[i]<<' ';
    }
    cout<<endl;
}

// 默认参数
void display(const vector<int> &vec, ostream &os=cout){
    for(int i=0; i<vec.size(); i++){
        os<<vec[i]<<' ';
    }
    os<<endl;
}

// 一、值传递
/*
形参意思是被调用函数的参数/变量，实参意思是主调函数中放到括号中的参数/变量。
传值方式下，形参是实参的拷贝：重新建立了变量，变量取值和实参一样。
即实参a和b的值为20和10,形参x和y的值都是20和10；而a与x的地址、b与y的地址并不相同
表明形参x和y是新建的变量，也即实参a, b是从形参复制了一份
*/
void swap_by_value(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// 二、传指针(地址),实质还是传值
void swap_by_pointer(int *p1, int *p2){
    int t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;
}

// 三、传引用
/*
传引用，传递的是实参本身，而不是实参的一个拷贝，形参的修改就是实参的修改,即值相同，地址也相同
相比于传值，传引用的好处是省去了复制，节约了空间和时间。
假如不希望修改变量的值，那么请选择传值而不是传引用。
*/
void swap_by_reference(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}
