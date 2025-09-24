#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int x=0, y=0;
    for (int i=0; i<1000; i++) {
        for (int j=0; j<s.size(); j++) {
            if (s[j]=='N') y++;
            else if (s[j]=='E') x++;
            else if (s[j]=='W') x--;
            else y--;
            if (x==a && y==b) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
