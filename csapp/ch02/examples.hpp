//
// Created by 郑楚彬 on 2020/3/12.
//
#include <iostream>
using namespace std;

void p22(){
    cout<<200*300*400*500<<endl;        // -884901888
    cout<<(500*400)*(300*200)<<endl;    // -884901888
    cout<<((200*500)*300)*400<<endl;    // -884901888
    cout<<400*(200*(300*500))<<endl;    // -884901888

    cout<<(3.14+1e20)-1e20<<endl;       // 0
    cout<<(3.14+(1e20-1e20))<<endl;     // 3.14
}
