#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int main(void){
    //入出力(x1、x2、x3、o)x100セット
    vector<vector<int>> data(100, vector<int>(4));
    
    //学習データファイルの読み込み
    ifstream inputfile("train_data20230607.txt");
    if(!inputfile.is_open())
        cout << "ファイルの読み込みに失敗しました。";

    int lineno = 0;
    int strno;
    string strline;
    string str;
    while(getline(inputfile, strline)){
        strno = 0;
        stringstream ss{strline};
        while(getline(ss, str, ' ')){
            data[lineno][strno] = stoi(str);
            strno++;
        }
        lineno++;
    }

    cout << "-------------" << endl;
    for(int i=0; i<100; i++){
            cout << i << " : " << data[i][0] << " " << data[i][1] << " " << data[i][2] << " " << data[i][3] << endl;
    }
}