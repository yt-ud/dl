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
*/

int main(void){
    vector<double> x{1.0, 1.0, 1.0};//入力数３
    vector<double> z{0, 0, 0, 0, 0, 0, 0, 0, 0};//出力数９
    vector<double> weight{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};//重み17
    vector<double> threshold{0.5, 0.5, 0.5, 0.5, 0.5, 0.5};//しきい値６
    



}
