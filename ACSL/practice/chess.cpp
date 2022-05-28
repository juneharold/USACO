#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> tokenize (string s) {
    vector<string> ret;
    string temp="";
    for (char x: s) {
        if (x==32) {
            ret.push_back(temp);
            temp="";
        }
        else temp+=x;
    }
    ret.push_back(temp);
    return ret;
}

int visit[10][10]={};

int main()
{
    string S; getline(cin, S);
    vector<string> pos=tokenize(S);
    pair<int, int> king;
    for (int i=0; i<pos.size(); i++) {
        if (pos[i][0]=='K') {
            int
        }
    }
}
