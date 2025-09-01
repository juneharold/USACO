#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

bool cmp(pii a, pii b) {
    return a.fs*b.sc<=b.fs*a.sc;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    vector<ll> dp(n+5, 0);
    dp[1]=a[1];
    for (ll i=2; i<=n; i++) {
        dp[i]=dp[i-1]+a[i]-1;
        dp[i]=min(dp[i], dp[i-2]+a[i-1]+max(0LL, a[i]-(i-1)));
    }

    cout << dp[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
