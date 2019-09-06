//
//  ShannonFano.hpp
//  EE669
//
//  Created by Alex on 2019/9/6.
//  Copyright © 2019 Alex. All rights reserved.
//

#ifndef ShannonFano_hpp
#define ShannonFano_hpp

#include "HW1_utli.hpp"

int SF_Separate(const vector<double>& freq, int start, int end){
    double left = 0;
    double right = 0;
    while(start < end){
        if(left > right){
            right += freq[end-1];
            end--;
        }
        else if(left < right){
            left += freq[left];
            start++;
        }
        else{
            left += freq[left];
            start++;
        }
    }
    return start;
}

void SF_Assign(vector<string>& code, int start, int end, int sep){
    int i = start;
    for(; i < sep; ++i){
        code[i] += '0';
    }
    for(; i < end; ++i){
        code[i] += '1';
    }
}

map<char, string> SF_convert(const vector<char>& label, const vector<string>& code){
    map<char, string> mp;
    for(int i = 0; i < label.size(); ++i){
        mp[label[i]] = code[i];
    }
    return mp;
}

map<char, string> SF_CodingDict(const vector<char>& data){
    vector<double> freq;
    vector<char> dict;
    GetStatics(data, freq, dict);
    vector<string> code(freq.size());
    queue<vector<int>> sk;
    sk.push({0, (int)freq.size()});
    while(!sk.empty() == true){
        int sep = SF_Separate(freq, sk.front()[0], sk.front()[1]);
        SF_Assign(code, sk.front()[0], sk.front()[1], sep);
        if(sep-1 > sk.front()[0]){
            sk.push({sk.front()[0], sep});
        }
        if(sep+1 < sk.front()[1]){
            sk.push({sep, sk.front()[1]});
        }
        sk.pop();
    }
    cout<<"Shannon Fano encoding"<<endl;
    cout<<"  "<<"char"<<"  "<<"code"<<endl;
    for(int i = 0; i < freq.size(); ++i){
        cout<<"   "<<dict[i]<<"     "<<code[i]<<endl;
    }
    return SF_convert(dict, code);
}

void SF_encode(const vector<char>& data, map<char, string> mp, const string& name){
    ofstream file("./"+name+"H_encode.dat");
    for(int i = 0; i < data.size(); ++i){
        file<<mp[data[i]];
    }
}


void SF_run(const string& name){
    ifstream f(name, ios_base::binary);
    vector<char> v((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    if(v.size() <= 0){
        cout<<"Can not read File."<<endl;
        return;
    }
    map<char, string> mp = SF_CodingDict(v);
    SF_encode(v, mp, name);
}

#endif /* ShannonFano_hpp */
