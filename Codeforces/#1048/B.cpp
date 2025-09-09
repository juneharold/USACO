#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n, m; cin >> n >> m;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(&a[1], &a[n+1]);
    ll ans=0, cnt=m;
    for (int i=n; i>=1; i--) {
        if (cnt==0) break;
        ans+=a[i]*cnt;
        cnt--;
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
