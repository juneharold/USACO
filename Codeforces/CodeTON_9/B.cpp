#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    string s; cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (i+1<s.size() && s[i]==s[i+1]) {
            cout << s.substr(i, 2) << "\n";
            return;
        }
        else if (i+2<s.size()) {
            set<char> temp;
            temp.insert(s[i]);
            temp.insert(s[i+1]);
            temp.insert(s[i+2]);
            if (temp.size()==3) {
                cout << s.substr(i, 3) << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
