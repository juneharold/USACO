#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s="codeforces";
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        char a; cin >> a;
        int work=0;
        for (int j=0; j<s.size(); j++) {
            if (s[j]==a) work=1;
        }
        if (work) cout << "YES\n";
        else cout << "NO\n";
    }
}