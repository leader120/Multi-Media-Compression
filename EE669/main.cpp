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

#include "Homework2/BAC.hpp"
#include "Homework2/CABAC.hpp"

using namespace std;

int main() {

    
    char* name = "test.txt";
    cout<<FileSize(name)<<endl;
    name = "test.txt";
    BAC_run(name, 0x10000, 0x0000, 12, 0, "BP");
    //CABAC_run(name,3);
    name = "test.txt_BAC_encode.dat";
    cout<<"File size    "<<FileSize(name)<<endl;
    
    return 0;
    
}

