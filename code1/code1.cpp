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
/*
３入力３階層のニューラルネットワーク、誤差逆伝播法
1
    4
2       6
    5
3
とりあえず動く物。汎用性、改修性は後回し。
*/

int main(void){
    //入出力(x1、x2、x3、o)x100セット
    vector<vector<int>> data(100, vector<int>(4));
    //伝達関数の入力u1、u2、u3、u4、u5、u6
    vector<vector<double>> u(100, vector<double>(6));
    //vector<double> u{0, 0, 0, 0, 0, 0};
    //出力z1、z2、z3、z4、z5、z6
    vector<vector<double>> z(100, vector<double>(6));
    //vector<double> z{0, 0, 0, 0, 0, 0};
    //{{セル1の重み}{セル2の重み}{セル3の重み}{セル4の重み}{セル5重み}{セル6の重み}}
    vector<vector<double>> weight = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 0.0}};//重み6x3
    //しきい値v1、v2、v3、v4、v5、v6
    vector<double> threshold{0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
    
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

    //入力セット100の各々について
    for(int n = 0; n < 100; n++){
        //各階層1、2、3
        for(int i = 0; i < 3; i++){
            //1階層目
            if(i == 0){
                //セル番号1、2、3
                for(int j = 0; j < 3; j++){
                    //入力x1、x2、x3
                    for(int k = 0; k < 3; k++){
                        u[n][j] = u[n][j] + data[n][k]*weight[j][k];
                    }
                    u[n][j] = u[n][j] - threshold[j];
                    z[n][j] = 1.0 / (1.0 + exp(-u[n][j]));
                }
            //2階層目
            } else if (i==1){
                //セル番号4、5
                for(int j = 3; j < 5; j++){
                    for(int k = 0; k < 3; k++){//z
                        u[n][j] = u[n][j] + z[n][k]*weight[j][k];
                    }
                    u[n][j] = u[n][j] - threshold[j];
                    z[n][j] = 1.0 / (1.0 + exp(-u[n][j]));
                }
            //3階層目
            } else {
                //セル番号6のみ
                for(int k = 0; k < 2; k++){//z
                    u[n][5] = u[n][5] + z[n][k+3]*weight[5][k];
                }
                u[n][5] = u[n][5] - threshold[5];
                z[n][5] = 1.0 / (1.0 + exp(-u[n][5]));
            }
        }
    }
    /*
    for(int n = 0; n < 6; n++){
        cout << n+1 << "番目のセル" << "    " << z[n] << endl;
    }
    cout << "出力" << "    " << z[5] << endl;
    */
}
