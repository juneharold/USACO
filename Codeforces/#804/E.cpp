#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e18+7, INF=9e18;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n+5);
    for (ll i=1; i<=n; i++) cin >> a[i];
    
    vector<ll> cnt(m+5, 0);
    for (ll i=1; i<=n; i++) cnt[a[i]]++;

    ll ans=1e18, bad=n, curmax=m;
    vector<ll> dp(m+5, 1e18), bucket(m+5, 0);
    for (ll L=m; L>=1; L--) {
        // update bucket 
        dp[L]=L;
        bad-=cnt[L];
        bucket[L]+=cnt[L];

        ll cur=L*L;
        while (cur<=m) {
            // update bucket
            ll old=dp[cur];
            dp[cur]=min(dp[cur], dp[cur/L]);

            if (dp[cur]==1e18) {
                cur+=L;
                continue;
            }

            if (old==1e18) {
                bad-=cnt[cur];
                bucket[dp[cur]]+=cnt[cur];
            }
            else {
                bucket[old]-=cnt[cur];
                bucket[dp[cur]]+=cnt[cur];
            }
            cur+=L;
        }

        while (curmax-1>=L && bucket[curmax]==0) {
            curmax--;
        }

        // udpate ans
        if (bad==0) {
            ans=min(ans, curmax-L);
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
