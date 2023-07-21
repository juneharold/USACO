#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=998244353;

ll fastpow (ll x, ll y) {
    ll ret=1;
    x%=MOD;
    while (y) {
        if (y%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        y/=2;
    }
    return ret;
}

ll dp[nmax]={};

ll find_dp(ll n, ll g, ll k) {
    if (dp[k]!=-1) return dp[k];
    ll p=2*(g-k)*(g-k)%MOD*fastpow(n*(n-1), MOD-2)%MOD;
    dp[k]=1+find_dp(n, g, k+1)+(1-p+MOD)*fastpow(p, MOD-2);
    dp[k]%=MOD;
    return dp[k];
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    ll g=0;
    for (ll i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i]==0) g++;
    }
    ll k=0;
    for (ll i=1; i<=g; i++) if (a[i]==0) k++;
    fill(&dp[0], &dp[g], -1);
    cout << find_dp(n, g, k) << "\n";
    fill(&dp[0], &dp[n+1], 0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        solve();
    }
}
