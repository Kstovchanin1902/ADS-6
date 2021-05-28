// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
std::string downReg(std::string str) {
    char* up =  reinterpret_cast<char*>(str);
    std::string tranz = "";
    int count = str.length();
    for (int i = 0; i < count; i++) {
        if (up[i] >= 'A' && up[i] <= 'Z')
            up[i] += ('a' - 'A');
        tranz.push_back(up[i]);
    }
    str = tranz;
    return str;
}
BST<std::string> makeTree(const char* filename) {
std::ifstream fin(filename);
    BST<std::string> wAP;
    if (fin.is_open()) {
        std::string outCh;
        char symb = ' ';
        std::string res;
        while (!fin.eof()) {
           getline(fin, outCh);
           for (int i = 0; i < outCh.length(); i++)
               if ((outCh[i] >= 'A' && outCh[i] <= 'Z') ||
               (outCh[i] >= 'a' && outCh[i] <= 'z')) {
                   symb = outCh[i];
                   res.push_back(symb);
               } else {
                if (!res.empty()) {
                res = downReg(res);
                wAP.add(res);
                }
                res.clear();
               }
            if (!res.empry()) {
                res = downReg(res);
                wAP.add(res);
            }
            res.clear();
        }
    }
    return wAP;
}
