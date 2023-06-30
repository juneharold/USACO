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
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

ll fastpow (ll x, ll y) {
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
        ll xa, ya, xb, yb, xc, yc; cin >> xa >> ya >> xb >> yb >> xc >> yc;
        ll ans=0;
        if ((xa<xb && xa<xc) || (xb<xa && xc<xa)) {
            ans+=min(abs(xa-xb), abs(xa-xc));
        }
        if ((ya<yb && ya<yc) || (yb<ya && yc<ya)) {
            ans+=min(abs(ya-yb), abs(ya-yc));
        }
        cout << ans+1 << "\n";
    }
}
