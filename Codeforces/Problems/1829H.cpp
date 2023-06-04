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
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

ll fastpow(ll x, ll y) {
    ll exponent=y, ret=1;
    while (exponent) {
        if (exponent%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        exponent/=2;
    }
    return ret;
}

ll setbits(ll x) {
    ll ret=0;
    while (x) {
        if (x%2) ret++;
        x/=2;
    }
    return ret;
}

int main()
{
    ll T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n+1);
        for (ll i=1; i<=n; i++) cin >> a[i];

        vector<vector<ll>> dp(n+1, vector<ll>(64, 0));
        
        for (ll i=1; i<=n; i++) {
            for (ll j=0; j<64; j++) {
                dp[i][j]+=dp[i-1][j]; // a[i]를 사용 안 할 때 
                dp[i][(a[i]&j)]+=dp[i-1][j]; //a[i]를 사용 할 때 
            }
            dp[i][a[i]]+=1; // a[i]만 sequence에 있기 
            for (ll j=0; j<64; j++) dp[i][j]%=MOD;
        }

        vector<ll> target;
        for (ll i=0; i<64; i++) {
            if (setbits(i)==k) target.push_back(i);
        }
        ll ans=0;
        for (ll x: target) ans=(ans+dp[n][x])%MOD;
        cout << ans << "\n";
    }
}
/*
1
4 0
0 1 2 3
*/