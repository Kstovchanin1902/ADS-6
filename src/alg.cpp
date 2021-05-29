// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
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
                   if (symb >= 'A' && symb <= 'Z')
                       symb += ('a' - 'A');
                   res.push_back(symb);
               } else {
                if (!res.empty()) {
                wAP.add(res);
                }
                res.clear();
               }
            if (!res.empty()) {
                wAP.add(res);
            }
            res.clear();
        }
    }
    return wAP;
}
