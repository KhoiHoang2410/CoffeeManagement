//
//  Helper.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Helper_h
#define Helper_h

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string Normalize(string&);
void PutError(string classBehaviour, string log);
void PutError(string classBehaviour, string log, int code);
bool IsInRange(string x, int l, int r);
pair<bool, int> StringToInt(string x);
vector <string> GetListFile(string dir);
bool IsHiddenFile(string file);

static bool isDebug = 1;

template <typename T>
void OutPut(string title, T content) {    
    if (isDebug) {
        cout << endl;
        cout << "----------------------------" << endl;
        cout << title << endl;
        cout << content << endl;
        cout << "----------------------------" << endl;
    }
}

#endif /* Helper_h */
