#include<string>
using namespace std;

string normalize(string& source) {
    string res = "";
    for (int i=0; i<source.size(); ++i) {
        if ('a' <= source[i] && source[i] <= 'z') res += source[i];
        else if ('A' <= source[i] && source[i] <= 'Z') res += source[i] - ('A' - 'a');
    }
    return res;
}
