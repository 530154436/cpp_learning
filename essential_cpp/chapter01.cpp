//
// Created by 郑楚彬 on 2019/12/12.
//

#include <string>
#include <iostream>
using namespace std;

void ex_01_01(){
    string name;
    cout << "Please input your name:";
    cin >> name;
    cout << '\n'
         << "Hello "
         << name
         << '\n';
}

void ex_01_02(){
    string first_name, last_name;
    cout << "Please input your first_name:";
    cin >> first_name;
    cout << "Please input your last_name:";
    cin >> last_name;
    cout << '\n'
         << "Hello "
         << last_name
         << " "
         << first_name
         << '\n';
}
