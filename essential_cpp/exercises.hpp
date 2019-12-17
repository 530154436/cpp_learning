#include <vector>
#include <iostream>
using namespace std;

// 自定义函数(用具方法)
extern void swap_by_value(int x, int y);
extern void swap_by_pointer(int *p1, int *p2);
extern void swap_by_reference(int &x, int &y);
extern void display(const vector<int> &vec);
extern void display(const vector<int> *vec);
extern void display(const vector<int> &vec, ostream &os=cout);

// 第1章样例、习题
extern void example_01_06();        // p7
extern void example_01_07();        // p33
extern void ex_01_01();             // p7
extern void ex_01_02();             // p7
extern void ex_01_05();             // p33
extern void ex_01_06();             // p33
extern void ex_01_07();             // p34

// 第2章样例、习题
extern bool example_02_01(int pos, int &elem);      // p36
extern void example_02_02();                        // p45 传值、传指针、传引用
extern const vector<int>* example_02_03(int size);  // p54 局部静态对象
extern bool example_02_04(int pos, int& elems);     // p55 内联函数
