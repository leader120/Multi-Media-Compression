//
//  HW1_utli.hpp
//  EE669
//
//  Created by Alex on 2019/9/6.
//  Copyright © 2019 Alex. All rights reserved.
//

#ifndef HW1_utli_hpp
#define HW1_utli_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

void mySort(vector<double>& freq, vector<char>& label){
    for (int i = 0; i < freq.size(); i++){
        for (int j = 0; j < freq.size()-i-1; j++){
            if (freq[j] > freq[j + 1]){
                double temp;
                temp = freq[j + 1];
                freq[j+1] = freq[j];
                freq[j] = temp;
                char tempc;
                tempc = label[j + 1];
                label[j+1] = label[j];
                label[j] = tempc;
            }
        }
    }
}

void GetStatics(const vector<char>& data, vector<double>& freq, vector<char>& dict){
    map<char, int> mp;
    for(int i = 0; i < data.size(); ++i){
        mp[data[i]]++;
    }
    map<char, int>::iterator iter = mp.begin();
    while(iter != mp.end()){
        freq.push_back((double)iter->second/(double)data.size());
        dict.push_back(iter->first);
        iter++;
    }
    mySort(freq, dict);
}

#endif /* HW1_utli_hpp */
