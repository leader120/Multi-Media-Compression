//
//  main.cpp
//  EE669
//
//  Created by Alex on 2019/9/6.
//  Copyright © 2019 Alex. All rights reserved.
//


#include "Homework1/ShannonFano.hpp"
#include "Homework1/Huffman_GS.hpp"
#include "Homework1/Huffman_adp.hpp"
#include "Homework2/BAC.hpp"
#include "Homework2/CABAC.hpp"
#include "Homework3/SQ.hpp"
#include "Homework3/VQ.hpp"

#include "Homework4/JPEG.hpp"

using namespace std;

void print(vector<vector<vector<double>>>& res){
    for(int i = 0; i < res.size(); ++i){
        cout<<endl;
        cout<<"Q "<<i<<endl;
        for(int p = 0; p < res[0].size(); ++p){
            for(int q = 0; q < res[1].size(); ++q){
                printf("%12f   ",res[i][p][q]);
            }
            cout<<endl;
        }
    }
    cout<<endl;
}

int main() {
    /*
    vector<vector<vector<double>>> data = imread_d("camera_man.raw", 16, 16, 1);
    WriteRaw(str2pchar(to_string(7)+".raw"), data);
    vector<vector<vector<double>>> data8x8 = block2D(data[0], 8);
    vector<vector<vector<int>>> res;
    for(int i = 0; i < data8x8.size(); ++i){
        res.push_back(QuantizedDCT(data8x8[i]));
        WriteRaw(str2pchar(to_string(i)+".raw"), data8x8[i]);
    }
    
    vector<vector<vector<double>>> res1;
    res1.push_back(GenerateQ(10));
    res1.push_back(GenerateQ(90));
    print(res1);
*/
    
    for(int i = 1; i < 6; ++i){
        string name = "jelly_beans";
        int H = 256;
        int K = 3;
        vector<vector<vector<double>>> data = imread_d(name+to_string(i)+".raw", K, H, H);
        vector<vector<vector<double>>> res = Deblocking_A(data);
        WriteRaw(str2pchar(name+to_string(i)+"_deblock.raw"), res);
        cout<<i<<endl;
        calPSNR(str2pchar(name+".raw"), str2pchar(name+to_string(i)+"_deblock.raw"), K, H, H);
        calSSIM(str2pchar(name+".raw"), str2pchar(name+to_string(i)+"_deblock.raw"), K, H, H);
    }
    return 0;
    
}
