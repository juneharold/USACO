#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n, y; cin >> n >> y;
    vector<int> a(n+1), pfs(nmax, 0), original_cnt(nmax, 0);
    int mx=0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        original_cnt[a[i]]++;
        pfs[a[i]]++;
        mx=max(mx, a[i]);
    }

    for (int i=1; i<=mx; i++) pfs[i]+=pfs[i-1];

    ll ans=-1e18;
    for (ll x=2; x<=mx+1; x++) {
        ll revenue=0, tags=0, p=1;
        while (true) {
            int left=(p-1)*x+1, right=min((ll)mx, p*x);
            if (left>mx) break;

            ll cnt=pfs[right]-pfs[left-1];
            revenue+=cnt*p;
            tags+=max(0LL, cnt-original_cnt[p]);

            p++;
        }
        ans=max(ans, revenue-y*tags);
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
