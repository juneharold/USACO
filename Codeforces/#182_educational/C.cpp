#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=998244353, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+2), b(n+2);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    a[n+1]=b[n+1]=1001;
    ll ans=1;
    for (int i=1; i<=n; i++) {
        if (max(a[i], b[i])<=min(a[i+1], b[i+1])) ans*=2;
        ans%=MOD;
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
