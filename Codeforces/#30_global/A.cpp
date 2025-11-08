#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    int mn=2e9, mx=-2e9;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        mn=min(mn, a);
        mx=max(mx, a);
    }
    int x; cin >> x;
    if (mn<=x && x<=mx) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
