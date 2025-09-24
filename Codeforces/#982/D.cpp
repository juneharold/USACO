#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=3e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll n, m, a[nmax], b[nmax];

void solve() {
    cin >> n >> m;
    for (ll i=1; i<=n; i++) cin >> a[i];
    for (ll j=1; j<=m; j++) cin >> b[j];

    vector<ll> pfs(n+1, 0);
    for (ll i=1; i<=n; i++) pfs[i]=pfs[i-1]+a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
    vector<vector<ll>> cnt(n+1, vector<ll>(m+1, 1));
    for (ll j=1; j<=m; j++) dp[0][j]=0;

    for (ll j=1; j<=m; j++) {
        for (ll i=1; i<=n; i++) {
            dp[i][j]=dp[i][j-1];
            cnt[i][j]=1;
            ll lo=1, hi=i;
            while (lo<hi) {
                ll mid=(lo+hi)/2;
                if (pfs[i]-pfs[mid-1]<=b[j]) hi=mid;
                else lo=mid+1;
            }
            if (b[j]<a[i]) continue;
            if (dp[lo-1][j]+m-j<dp[i][j]) {
                dp[i][j]=dp[lo-1][j]+m-j;
                cnt[i][j]=cnt[lo-1][j];
            }
            else if (dp[lo-1][j]+m-j==dp[i][j]) {
                cnt[i][j]+=cnt[lo-1][j];
            }
        }
    }
    ll ans=INF, ops;
    for (ll j=1; j<=m; j++) if (dp[n][j]<ans) {
        ans=dp[n][j];
        ops=cnt[n][j];
    }
    if (ans==INF) cout << "-1\n";
    else cout << ans << ' ' << ops << "\n";

    for (ll i=1; i<=n; i++) a[i]=0;
    for (ll i=1; i<=m; i++) b[i]=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
