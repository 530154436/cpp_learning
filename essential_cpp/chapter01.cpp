//
// Created by 郑楚彬 on 2019/12/12.
//

#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

void example_01_06(){
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

void example_01_07(){
    // p33
    ifstream infile("data/seq_data.txt");                // Edit Configurations => Working dictionary
    // ofstream out_file("data/seq_data.txt");           // 写覆盖
    // ofstream out_file("seq_data.txt", ios_base::app); // 追加模式

    string name;
    int nt=0, nc=0;
    if (!infile || !infile.is_open()){
        cerr << "Unable to read file!\n";
    } else{
        while (infile>>name){
            infile>>nt>>nc;
            cout<<name<<", "
                <<nt<<", "
                <<nc<<endl;
        }
    }
}

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

void ex_01_05(){
    // p33
    cout<<"What's your name?"<<endl;

    // C-stype: char-array
    int cnt=0;
    char name[10];
    cin>>name;
    for(int i=0; i<10; i++){
        if(name[i]=='\0')
            break;
        cnt++;
    }
    if (cnt>2)
        cout<<"Name is not valid.(length must <=2, , char[])"<<endl;
    else
        cout<<name<<" Valid. (char[])"<<endl;

    // char*
    char* line=new char[10];
    cin>>line;
    if(strlen(line)>2)
        cout<<"Name is not valid.(length must <=2, char*)"<<endl;
    else
        cout<<line<<" Valid. (char*)"<<endl;

    //string
    string text;
    cin>>text;
    if(text.size()>2)
        cout<<"Name is not valid.(length must <=2, string)"<<endl;
    else
        cout<<text<<" Valid.(string)"<<endl;
}

void ex_01_06(){
    //p33

    // 数组实现
    int max_len=10;
    int i=0, cur_val=0, sum=0, cnt=0;
    int arr[max_len];

    // 监视读入的元素个数，确保数组的读取操作不会越界
    while (cin>>cur_val && cur_val!=-1 && i<max_len){
        arr[i++] = cur_val;
        cnt++;
    }
    for(i=0; i<cnt; i++) sum += arr[i];
    float avg = (cnt==0?0:(float)sum/cnt);
    cout<<"sum="<<sum<<", avg="<<avg<<endl;

    // vector 实现
    sum=0;
    vector<int> vec;
    while (cin>>cur_val && cur_val!=-1){
        vec.push_back(cur_val);
    }
    for(i=0; i<vec.size(); i++){
        sum += vec.at(i);
    }
    avg = (cnt==0?0:(float)sum/vec.size());
    cout<<"sum="<<sum<<", avg="<<avg<<endl;
}

void ex_01_07(){
    string cur_ch;
    vector<string> vec;

    fstream infile("data/ex0107.txt");
    if(!infile){
        cout<<"Read file failed."<<endl;
        return;
    }

    while (infile>>cur_ch){
        vec.push_back(cur_ch);
    }

    for(int i=0; i<vec.size(); i++) cout<< vec.at(i)<< " ";
    cout<<endl;

    // 排序
    sort(vec.begin(), vec.end());

    for(int i=0; i<vec.size(); i++) cout<< vec.at(i)<< " ";
    cout<<endl;
}