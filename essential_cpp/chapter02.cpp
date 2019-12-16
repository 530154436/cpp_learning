//
// Created by 郑楚彬 on 2019/12/12.
//
#include <iostream>
using namespace std;

bool example_02_01(int pos, int &elem){
    /**
     * 斐波拉契数列
     * @param pos  第i个位置
     * @param elem 结果
     * @return 第@code{pos}个位置的元素
     */
    // 检查位置是否合理
    if(pos<=0 || pos>1000){
        elem = 0;
        cout<<"Position "<<pos<<" is not valid.";
        return false;
    }
    elem = 1;
    int b1=1,b2=1;
    for (int i = 2; i < pos; ++i) {
        elem = b1+b2;
        b1=b2, b2=elem;
        cout << i+1<< ": "<<elem << endl;
    }
    return true;
}



