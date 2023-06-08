#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

//乱数による教師データの生成。
int main(int argc, char const* argv[]){
    ofstream outputfile("train_data20230607.txt");
    //srandの引数は乱数シードなので、不用意に変えないこと。
    srand(2023);
    for(int i = 0; i < 100; i++){
        outputfile << rand() % 10 << " " << rand() % 10 << " " << rand() % 10 << " " << rand() % 10 << " " << endl;
    }
    outputfile.close();
}


