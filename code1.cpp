#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
/*
３入力３階層のニューラルネットワーク
1
    4
2       6
    5
3
とりあえず動く物。汎用性、改修性は後回し。
*/

int main(void){
    //入力x1、x2、x3
    vector<double> x{1.0, 1.0, 1.0};
    //伝達関数f1、f2、f3、f4、f5、f6
    vector<double> u{0, 0, 0, 0, 0, 0};
    //出力z1、z2、z3、z4、z5、z6
    vector<double> z{0, 0, 0, 0, 0, 0};
    //{{セル1の重み}{セル2の重み}{セル3の重み}{セル4の重み}{セル5重み}{セル6の重み}}
    vector<vector<double>> weight = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 0.0}};//重み6x3
    //しきい値v1、v2、v3、v4、v5、v6
    vector<double> threshold{0.5, 0.5, 0.5, 0.5, 0.5, 0.5};

    //各階層1、2、3
    for(int i = 0; i < 3; i++){
        //1階層目
        if(i == 0){
            //セル番号1、2、3
            for(int j = 0; j < 3; j++){
                //入力x1、x2、x3
                for(int k = 0; k < 3; k++){
                    u[j] = u[j] + x[k]*weight[j][k];
                }
                u[j] = u[j] - threshold[j];
                z[j] = 1.0 / (1.0 + exp(-u[j]));
            }
        //2階層目
        } else if (i==1){
            //セル番号4、5
            for(int j = 3; j < 5; j++){
                for(int k = 0; k < 3; k++){//z
                    u[j] = u[j] + z[k]*weight[j][k];
                }
                u[j] = u[j] - threshold[j];
                z[j] = 1.0 / (1.0 + exp(-u[j]));
            }
        //3階層目
        } else {
            //セル番号6のみ
            for(int k = 0; k < 2; k++){//z
                u[5] = u[5] + z[k+3]*weight[5][k];
            }
            u[5] = u[5] - threshold[5];
            z[5] = 1.0 / (1.0 + exp(-u[5]));
        }
    }    
    for(int n = 0; n < 6; n++){
        cout << n+1 << "番目のセル" << "    " << z[n] << endl;
    }
    cout << "出力" << "    " << z[5] << endl;
}
