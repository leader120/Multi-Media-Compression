//
//  Huffman_GS.hpp
//  EE669
//
//  Created by Alex on 2019/9/6.
//  Copyright © 2019 Alex. All rights reserved.
//

#ifndef Huffman_GS_hpp
#define Huffman_GS_hpp

#include "HW1_utli.hpp"

struct Tree{
    Tree* left;
    Tree* right;
    char isleaf;
};



int H_selectMin(vector<double>& freq){
    double min1 = INT_MAX;
    int idx = -1;
    for(int i = 0; i < freq.size(); ++i){
        if(freq[i] > 0 && freq[i] != 1 && freq[i] < min1){
            min1 = freq[i];
            idx = i;
        }
    }
    return idx;
}

Tree* H_Buildtree(const vector<double>& freq, const vector<char>& dict){
    vector<double> tfreq(freq);
    vector<Tree*> tmp(dict.size(), NULL);
    int idx, idx1;
    int t = 0;
    while(1){
        idx = H_selectMin(tfreq);
        if(idx == -1){
            break;
        }
        Tree* node = new Tree;
        Tree* n1 = new Tree;
        Tree* n2 = new Tree;
        if(tmp[idx] != NULL){
            n1 = tmp[idx];
            node->left = n1;
        }
        else{
            n1->isleaf = dict[idx];
            n1->left = NULL;
            n1->right = NULL;
            node->left = n1;
        }
        tfreq[idx] = tfreq[idx]-1;
        
        idx1 = H_selectMin(tfreq);
        if(tmp[idx1] != NULL){
            n2 = tmp[idx1];
            node->right = n2;
        }
        else{
            n2->isleaf = dict[idx1];
            n2->left = NULL;
            n2->right = NULL;
            node->right = n2;
        }
        node->isleaf = '0';
        //H_PrintBinaryDict(node);
        tfreq[idx1] = tfreq[idx1]-1;
        tfreq[idx] = tfreq[idx] + tfreq[idx1] + 2;
        t = idx;
        tmp[idx] = node;
        tmp[idx1] = NULL;
    }
    
    return tmp[t];
}

void H_PrintBinaryDict(Tree* head){
    if(head == NULL){return;}
    queue<Tree*> qu;
    qu.push(head);
    while(!qu.empty()){
        int size = (int)qu.size();
        for(int i(0); i < size; ++i){
            if(qu.front() != NULL){
                cout<<qu.front()->isleaf<<"  ";
                //if(qu.front()->left != NULL)
                qu.push(qu.front()->left);
                //if(qu.front()->right != NULL)
                qu.push(qu.front()->right);
            }
            else{
                cout<<"..  ";
            }
            qu.pop();
        }
        cout<<endl;
    }
}

void H_ConvertTree(Tree* head, map<char, string>& mp, string code){
    if(head == NULL){
        return;
    }
    if(head->left == NULL && head->right == NULL){
        mp[head->isleaf] = code;
        return;
    }
    if(head->left != NULL){
        H_ConvertTree(head->left, mp, code+'0');
    }
    if(head->right != NULL){
        H_ConvertTree(head->right, mp, code+'1');
    }
}

map<char, string> H_CodingDict(const vector<char>& data){
    vector<double> freq;
    vector<char> dict;
    GetStatics(data, freq, dict);
    map<char, string> mp;
    Tree* head = H_Buildtree(freq, dict);
    string s;
    H_ConvertTree(head, mp, s);
    return mp;
}

void H_encode(const vector<char>& data, map<char, string> mp, const string& name){
    ofstream file("./"+name+"H_encode.dat");
    for(int i = 0; i < data.size(); ++i){
        file<<mp[data[i]];
    }
}

void H_run(const string& name){
    ifstream f(name, ios_base::binary);
    vector<char> v((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    if(v.size() <= 0){
        cout<<"Can not read File."<<endl;
        return;
    }
    map<char, string> mp = H_CodingDict(v);
    map<char, string>::iterator it = mp.begin();
    cout<<"Huffman encoding"<<endl;
    cout<<"   "<<"char"<<"  "<<"code"<<endl;
    while(it != mp.end()){
        cout<<"  "<<it->first<<"   "<<it->second<<endl;
        it++;
    }
    H_encode(v, mp, name);
}

#endif /* Huffman_GS_hpp */
