#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

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
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int n; cin >> n;
        ll ans=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            ans+=x*(fastpow(2, i-1)-fastpow(2, n-i));
            ans=(ans+INT32_MAX*MOD)%MOD;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}