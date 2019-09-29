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
    char* name = "audio.dat";
    
    string opt="BP";
    name = "image.dat";

    //CABAC_separate(name,2);
    
    
    CABAC_run(name,6,opt);
    CABAC_run(name,7,opt);
    CABAC_run(name,8,opt);
    CABAC_run(name,9,opt);
    CABAC_run(name,10,opt);
     
    return 0;
    
}
