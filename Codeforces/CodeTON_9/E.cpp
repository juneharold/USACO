#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e6+5, sqrmax=635, MOD=998244353, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<ll> dp(n+1, 0);
    dp[n]=1;
    ll sum=1;
    for (ll i=n-1; i>=1; i--) {
        dp[i]=i*sum+1;
        dp[i]%=MOD;
        sum+=dp[i];
        sum%=MOD;
    }

    ll ans=0;
    for (ll k=4; k<=n; k++) {
        ll cnt_ways=((k)*(k-3)/2)%MOD;
        ans+=dp[k]*cnt_ways;
        ans%=MOD;
    }
    ans+=1; // just adding 0s to front
    ans+=n-2; // n-2 ways to make sequence: 0000....010111111
    cout << ans%MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
