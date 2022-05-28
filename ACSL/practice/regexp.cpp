#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
#define ll long long

vector<string> tokenize (string s) {
    vector<string> ret;
    string temp="";
    for (char x: s) {
        if (x==32) {
            ret.push_back(temp);
            temp="";
        }
        else if (x!=',') {
            temp+=x;
        }
    }
    ret.push_back(temp);
    return ret;
}

int main()
{
    string S; getline(cin, S);
    vector<string> in=tokenize(S);

    for (int t=1; t<=5; t++) {
        string s; cin >> s;
        
        for (int i=0; i<10; i++) {
            string st=in[i];
            if (in[i]=="#") st="";


        }
    }
}
