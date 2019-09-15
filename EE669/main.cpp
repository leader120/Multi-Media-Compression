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
using namespace std;

int main() {
    char* t = "audio.ah";

    /*
    HA_run("audio.dat", "-c");
    cout<<"file size: "<<FileSize(t)<<endl;
    
    HA_run("binary.dat", "-c");
    t = "binary.ah";
    cout<<"file size: "<<FileSize(t)<<endl;
    
    HA_run("image.dat", "-c");
    t = "image.ah";
    cout<<"file size: "<<FileSize(t)<<endl;
    */
    /*
   t = "test_SF.txt";
    cout<<"raw file size: "<<FileSize(t)<<endl;
    
    HA_run("test_SF.txt","-c");
    t = "test_SF.ah";
    cout<<"HA file size: "<<FileSize(t)<<endl;
     */
    HA_run("binary.dat","-c");
    t = "test_SF.txt_H_encode.dat";
    cout<<"H file size: "<<FileSize(t)<<endl;
    
    return 0;
}

