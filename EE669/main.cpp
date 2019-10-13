//
//  main.cpp
//  EE669
//
//  Created by Alex on 2019/9/6.
//  Copyright © 2019 Alex. All rights reserved.
//

/*
#include "Homework1/ShannonFano.hpp"
#include "Homework1/Huffman_GS.hpp"
#include "Homework1/Huffman_adp.hpp"
*/


#include "Homework3/SQ.hpp"
#include "Homework3/VQ.hpp"

using namespace std;


int main() {
    /*
    vector<vector<vector<int>>> tmp = imread("couple.quantized.raw", 256, 256, 1);

    
    WriteRaw(n, tmp);
    
*/
    
    
//vector<string> train ={"f16.256","couple.256","elaine.256"};
//    vector<string> nn = {"moon.256","chem.256","house.256","f16.256","couple.256","elaine.256"};
    
vector<string> train ={"couple.256"};
    
    
    VQ_Block_run(train, 2);
    

    
     
    
    
    
    
    /*
    
    vector<string> train ={"chem.256","house.256","moon.256"};
    char n[20] = "tmp_1.raw";
    
    vector<string> nn = {"moon.256","chem.256","house.256","f16.256","couple.256","elaine.256"};
    for(int i = 0; i < 20; ++i){
        //n[4] = (char)(i+'0');
        double t = 0;
        cout<<i<<endl;
       // for(int j = 0; j < 6; ++j){
            t += SQ_run(train, nn[0], n, 5, i);
        t += SQ_run(train, nn[1], n, 5, i);
        t += SQ_run(train, nn[2], n, 5, i);
        t /=3;
        double PSNR(10*log10(255*255/t));
        cout<<PSNR<<endl;
      //  }
      //  cout<<"\\\\"<<endl;;
    }
    cout<<endl;
     */
    return 0;
    
}
