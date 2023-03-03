#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool solve(string s) {
    int idx=0;
    while (idx<s.size()) {
        if (s[idx]=='0') {
            if (idx+1>=s.size()) return false;
            if (s[idx+1]!='1') return false;
            idx+=2;
        }
        else {
            if (idx+3>=s.size()) return false;
            if (s[idx+1]!='0') return false;
            if (s[idx+2]!='0') return false;

            int cnt0=1;
            for (int i=idx+2+cnt0; i<s.size(); i++) { 
                if (s[i]=='1') break;
                cnt0++;
            }

            if (idx+2+cnt0>=s.size()) return false;
            if (s[idx+2+cnt0]!='1') return false;
            
            int cnt1=1;
            for (int i=idx+2+cnt0; i<s.size(); i++) {
                if (i+1<s.size() && s[i+1]=='0') {
                    //idx=i+1;
                    break;
                }
                else if (i+1<s.size() && s[i+1]=='1') {
                    string target="100";
                    bool Exit=true;
                    for (int j=i+1; j<i+4; j++) {
                        if (target[j-i-1]!=s[j]) Exit=false;
                    }
                    if (Exit) break;
                }
                cnt1++;
            }
            idx+=2+cnt0+cnt1;
        }
    }
    return true;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        if (solve(s)) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
3
10010111
011000100110001
0110001011001

10
10011001
100111001
1000110001
10001100001
10011000111
0110011110001
1001110001101
10001100110101
10001110001111
10001111000011

1
100000101010
*/




