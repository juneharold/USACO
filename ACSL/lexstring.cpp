#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int cnt=5;
    while (cnt--){
        string s; cin >> s;
        char c[105];
        int idx=0;
        for (int i=0; i<s.size(); i++) {
            if (48<=s[i] && s[i]<=57) {
                c[idx]=s[i];
                idx++;
            }
            if (65<=s[i] && s[i]<=90) {
                c[idx]=s[i];
                idx++;
            }
            if (97<=s[i] && s[i]<=122) {
                c[idx]=s[i];
                idx++;
            }
        }

        sort(&c[0], &c[idx]);

        vector<pair<int, int>> v;
        for (int i=0; i<idx; i++) {
            
        }
    }
}
