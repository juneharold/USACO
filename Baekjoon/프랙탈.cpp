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
    ll N, a; cin >> N >> a;
    ll k=(fastpow(N, a)-fastpow(N, a-1)+MOD)%MOD;
    ll ans=k+fastpow(N-1, a);
    ll u=(1-fastpow(N, MOD-2)+MOD)%MOD;
    ans+=k*(u*(fastpow(u, a-1)-1+MOD)%MOD)%MOD*fastpow(u-1, MOD-2)%MOD;
    cout << N%MOD*ans%MOD;
}

