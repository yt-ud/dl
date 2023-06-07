#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

//乱数による教師データの生成
int main(int argc, char const* argv[]){
    ofstream outputfile("train_data20230607.txt");

    for(int i = 0; i < 100; i++){
        outputfile << rand() % 10 << " " << rand() % 10 << " " << rand() % 10 << " " << rand() % 10 << endl;
    }
    outputfile.close();
}


