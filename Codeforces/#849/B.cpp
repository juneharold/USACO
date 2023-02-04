#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int x=0, y=0;
        int works=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='U') y++;
            if (s[i]=='D') y--;
            if (s[i]=='L') x--;
            if (s[i]=='R') x++;
            if (x==1 && y==1) works=1;
        }
        if (works) cout << "YES\n";
        else cout << "NO\n";
    }
    
}