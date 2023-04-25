#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        string s; cin >> s;
        int first0=1e9, first1=1e9, last0=-1e9, last1=-1e9;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='0') {
                first0=min(first0, i);
                last0=max(last0, i);
            }
            if (s[i]=='1') {
                first1=min(first1, i);
                last1=max(last1, i);
            }
        }

        for (int i=0; i<q; i++) {
            int l, r; cin >> l >> r;
            l--; r--;
            if (s[l]=='0' && first0<l) cout << "YES\n";
            else if (s[l]=='1' && first1<l) cout << "YES\n";
            else if (s[r]=='0' && last0>r) cout << "YES\n";
            else if (s[r]=='1' && last1>r) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
