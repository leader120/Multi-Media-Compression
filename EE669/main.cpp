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
        cout<<"Block "<<i<<endl;
        for(int p = 0; p < res[0].size(); ++p){
            for(int q = 0; q < res[1].size(); ++q){
                printf("%12f   ",res[i][p][q]);
            }
            cout<<endl;
        }
    }
    cout<<endl;
}
void print(vector<vector<vector<int>>>& res){
    for(int i = 0; i < res.size(); ++i){
        cout<<endl;
        cout<<" Block "<<i<<endl;
        for(int p = 0; p < res[0].size(); ++p){
            for(int q = 0; q < res[1].size(); ++q){
                printf(" %4d",res[i][p][q]);
            }
            cout<<endl;
        }
    }
    cout<<endl;
}

int main() {
    /*
    vector<vector<vector<double>>> data = imread_d("camera_man.raw", 1, 16, 16);
    //print(data);
    WriteRaw(str2pchar(to_string(7)+".raw"), data);
    vector<vector<vector<double>>> data8x8 = block2D(data[0], 8);
    //print(data8x8);
    vector<vector<vector<int>>> res;
    
    for(int i = 0; i < data8x8.size(); ++i){
        res.push_back(QuantizedDCT(data8x8[i],50));
        //WriteRaw(str2pchar(to_string(i)+".raw"), data8x8[i]);
    }
    print(res);
    //vector<vector<vector<double>>> res1;
    //res1.push_back(GenerateQ(10));
    //res1.push_back(GenerateQ(90));
    */

    
    string name = "boat";
    int H = 512;
    int W = H;

    int K = 3;
    vector<int> tmmp = {100,60,40,20,10,1};
    for(int k = 1; k < 6; ++k){
        vector<vector<vector<double>>> data = imread_d(name+to_string(k)+"_deblocking.raw", 3, H, W);
        WriteRaw(str2pchar(name+to_string(k)+"_deblocking.raw"),data[0]);
        //calPSNR(str2pchar(name+".raw"), str2pchar(name+to_string(k)+"_deblock.raw"), K, H, W);
        //calSSIM(str2pchar(name+".raw"), str2pchar(name+to_string(k)+"_deblock.raw"), K, H, W);
    }
    
    return 0;
}
