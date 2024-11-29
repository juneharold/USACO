#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    map<int, int> m;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        m[x]++;
    }
    int mx=0;
    for (auto p: m) mx=max(mx, p.sc);
    cout << n-mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
