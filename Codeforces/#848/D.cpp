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
    if (x==0) return 0;
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        string a, b; cin >> a >> b;
        ll cnt=0;
        for (ll i=0; i<n; i++) {
            if (a[i]!=b[i]) cnt++;
        }
        if (n==1) {
            cout << cnt << "\n";
            continue;
        }

        vector<ll> f(n+1, 0);
        f[n]=1;
        for (ll i=n-1; i>=1; i--) {
            f[i]=(n+(n-i)*f[i+1]%MOD)*fastpow(i, MOD-2);
            f[i]%=MOD;
        }

        ll ans=0;
        for (ll i=cnt; i>=1; i--) ans=(ans+f[i])%MOD;
        cout << ans << "\n";
    }
}

/*
4
1
0
1
2
00
00
4
1000
1110
5
01001
10111
*/
