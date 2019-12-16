//
// Created by 郑楚彬 on 2019/12/12.
//

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void ex_01_01(){
    // p7
    string name;
    cout << "Please input your name:";
    cin >> name;
    cout << '\n'
         << "Hello "
         << name
         << '\n';
}

void ex_01_02(){
    //p7
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

void example_01(){
    // p7
    string user_name;
    const int seq_cnt = 6;

    // 初始化
    vector<int> fib,lucas,pell,tri,squre,penta;
    vector<int> *seq_addrs[seq_cnt] = {
        &fib, &lucas, &pell, &tri, &squre,&penta
    };
    int data[18] = {
        1,2,3,
        3,4,7,
        2,5,12,
        3,6,10,
        4,9,16,
        5,12,22
    };
    vector<int> *cur_vec_pointer;
    for(int i=0; i<seq_cnt; i++){
        cur_vec_pointer = seq_addrs[i];
        cur_vec_pointer->insert(cur_vec_pointer->begin(), data+(3*i), data+(3*i+3)); // 对vector赋值
    }
    // 打印数列信息
    for(int j=0; j<seq_cnt; j++){
        cur_vec_pointer = seq_addrs[j];
        cout<<j<<"数列: ";
        for(int i=0; i<cur_vec_pointer->size(); i++){
            cout<<cur_vec_pointer->at(i)<<' ';
        }
        cout<<endl;
    }

    bool next_seq = true;   // 显示下一组数列
    bool go_for_it = true;  // 用户想再猜一次
    bool got_it = false;    // 用户是否猜对
    int num_tries = 0;      // 用户猜过的总次数
    int num_right = 0;      // 用户答对的次数
    int user_guess;
    char try_again;

    while (next_seq){

        // 随机抽取一个数列
        int seq_index = rand() % seq_cnt;  // rand()返回[0,max_int]
        cur_vec_pointer = seq_addrs[seq_index];

        // 打印数列信息
        cout<<"Guess what it next item? ";
        for(int i=0; i<cur_vec_pointer->size()-1; i++){
            cout<<cur_vec_pointer->at(i)<<' ';
        }
        cout<<endl;

        while (go_for_it && !got_it){
            // 验证用户是否猜对
            cin>>user_guess;
            if (user_guess==cur_vec_pointer->at(2)) {
                got_it = true;
                num_right++;
            }else{
                cout<<"The answer is not right."
                    <<"Want to try again? (Y/N)";
                cin>>try_again;
                if(try_again=='N' || try_again=='n')
                    go_for_it = false;
            }
            num_tries++;
        }

        cout<<"Want to try another sequence? (Y/N)";
        cin>>try_again;
        if(try_again=='N' || try_again=='n') {
            next_seq = false;
            cout << "right/total="
                 << (float) num_right / num_tries;
        }else{
            got_it = false;
            go_for_it = true;
        }
    }
}

void example_02(){
    ofstream out_file("seq_data.txt");                   // 覆盖
    // ofstream out_file("seq_data.txt", ios_base::app); // 追加模式

}