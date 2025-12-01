#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n+5), b(n+5);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];

    vector<ll> pfs(n+5, 0);
    for (int i=1; i<=n; i++) pfs[i]=pfs[i-1]+a[i];

    vector<ll> pre(n+5, 0), suf(n+5, -1e18);
    for (int i=1; i<=n; i++) pre[i]=min(pre[i-1], pfs[i]);
    for (int i=n; i>=1; i--) suf[i]=max(suf[i+1], pfs[i]);

    ll ans=-1e18;
    for (int i=1; i<=n; i++) {
        int dx=(k%2) ? b[i] : 0;
        ans=max(ans, suf[i]-pre[i-1]+dx);
    }
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
