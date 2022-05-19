#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
#define ll long long
#define f first
#define s second

string combo[7]={"ch", "ck", "ph", "sh", "th", "wh", "wr"};
string prefix[6]={"co", "de", "dis", "pre", "re", "un"};
string suffix[5]={"age", "ful", "ing", "less", "ment"};
string vowel[5]={"a", "e", "i", "o", "u"};
vector<string> ans;

int main()
{
    string s; cin >> s;

    for (int i=0; i<6; i++) {
        if (s.size()<=prefix[i].size()) {
            string a=s.substr(0, prefix[i].size());
            if (a==prefix[i]) {
                s=s.substr(prefix[i].size(), s.size()-prefix[i].size());
                ans.push_back(prefix[i]);
                break;
            }
        }
    }

    string end="";
    for (int i=0; i<5; i++) {
        if (s.size()<=suffix[i].size()) {
            string a=s.substr(s.size()-suffix[i].size(), suffix[i].size());
            if (a==suffix[i]) {
                s=s.substr(0, s.size()-suffix[i].size());
                end=suffix[i];
                break;
            }
        }
    }
    
}
