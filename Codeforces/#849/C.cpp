#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> ans;
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt=0;
        for (int i=0; i<n; i++) {
            if (i>=n-i-1) break;

            if (s[i]!=s[n-i-1]) cnt++;
            else break;
        }
        cout << n-cnt*2 << "\n";
    }
}