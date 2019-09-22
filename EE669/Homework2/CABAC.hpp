//
//  CABAC.hpp
//  EE669
//
//  Created by Alex on 2019/9/21.
//  Copyright © 2019 Alex. All rights reserved.
//

#ifndef CABAC_hpp
#define CABAC_hpp

#include "HW2_utli.hpp"

void CABAC_run(const char* name, int contextbits){
    vector<int> contextlist(contextbits,0);
    
    FILE *f;
    char *output=new char[64];
    strcat(output, name);
    strcat(output, "_CABAC_encode.dat");
    
    f = fopen(output, "wb");
    
    QM coder(f);
    coder.StartQM("encode");
    
    ifstream ff(name, ios_base::binary);
    vector<unsigned char> v((istreambuf_iterator<char>(ff)), istreambuf_iterator<char>());

    for(int k = 0; k < v.size(); ++k){
        string bits = Byte2Bit(v[k]);
        for(int j = 0; j < 8; ++j){
            int newbit = bits[j]-'0';
            int context = 0;
        
            // Calculate context
            for(int i = 0; i< contextbits; i++){
                context += pow(2,i)*contextlist[i];
            }
        
            // Encode use context
            coder.encode(newbit, context);
        
            // Update context
            for(int i = contextbits-1; i >= 0; i--){
                if(i == 0){
                    contextlist[i] = contextbits;
                }
                else{
                    contextlist[i] = contextlist[i-1];
                }
            }
        }
    }
    coder.Flush();
}
#endif /* CABAC_hpp */
