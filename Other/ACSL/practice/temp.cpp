#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> tokenize(string s) {
    vector<string> ret;
    s+=" ";
    string temp="";
    for (int i=0; i<s.size(); i++) {
        if (s[i]==32) {
            ret.push_back(temp);
            temp="";
        }
        else {
            temp+=s[i];
        }
    }
    return ret;
}

int main()
{
    string s; getline(cin, s);
    vector<string> x=tokenize(s);

    for (int i=0; i<x.size(); i++) {
        if (i%2==0) {
            cout << x[i][0] << " " << x[i][1] << " ";
        }
        else {
            int w=stoi(x[i]);
            cout << w << "\n";
        }
    }
}
