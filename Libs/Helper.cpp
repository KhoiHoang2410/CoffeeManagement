#include <string>
using namespace std;

#include "../Include/Helper.hpp"

#include <iostream>

string Normalize(string& source) {
    string res = "";
    for (int i=0; i<source.size(); ++i) {
        if ('a' <= source[i] && source[i] <= 'z') res += source[i];
        else if ('A' <= source[i] && source[i] <= 'Z') res += source[i] - ('A' - 'a');
    }
    return res;
}

void putError(string classBehaviour, string log, int code) {
    cout << classBehaviour << endl;
    cout << log << ".\n";
    exit(code);
}

void putError(string classBehaviour, string log) {
    cout << classBehaviour << endl;
    cout << log << ".\n";
}
