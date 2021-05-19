#include <string>
#include <vector>
#include <dirent.h>
using namespace std;

#include "../Include/Helper.hpp"

#include <iostream>

vector <string> GetListFile(string dir) {
    DIR *dp;
    
    if((dp  = opendir(dir.c_str())) == NULL) {
        PutError("GetListFile", "", 1);
    }
    
    vector <string> files;
    struct dirent *dirp;
    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return files;
}

string Normalize(string& source) {
    string res = "";
    for (int i=0; i<source.size(); ++i) {
        if ('a' <= source[i] && source[i] <= 'z') res += source[i];
        else if ('A' <= source[i] && source[i] <= 'Z') res += source[i] - ('A' - 'a');
    }
    return res;
}

void PutError(string classBehaviour, string log, int code) {
    cout << classBehaviour << endl;
    cout << log << ".\n";
    exit(code);
}

void PutError(string classBehaviour, string log) {
    if (isDebug) {
        cout << classBehaviour << endl;
        cout << log << ".\n";
    }
}

pair<bool, int> StringToInt(string x) {
    int res = 0;
    for (int i=0; i<x.size(); ++i) {
        if ('0' <= x[i] && x[i] <= '9') (res *= 10) += x[i] - '0';
        else return make_pair(false, -1);
    }
    return make_pair(true, res);
}

bool IsInRange(string x, int l, int r) {
    pair<bool, int> tmp = StringToInt(x);
    if (!tmp.first) return false;
    return (l <= tmp.second && tmp.second <= r);
}

bool IsHiddenFile(string file) {
    if (file[0] == '.') return false;
    return true;
}