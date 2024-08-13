#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    map<char, int> m;
    for (int i=0; i<4*n; i++) {
        char x; cin >> x;
        if (x=='?') continue;
        m[x]++;
    }

    int ans=0;
    for (auto e: m) ans+=min(n, e.sc);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
