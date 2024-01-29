#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

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

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll sumf=0;
    for (int i=0; i<m; i++) {
        ll a, b, f; cin >> a >> b >> f;
        sumf+=f;
        sumf%=MOD;
    }
    vector<ll> fact(k+1, 1), invfact(k+1, 1);
    for (ll i=1; i<=k; i++) fact[i]=i*fact[i-1]%MOD;
    for (ll i=1; i<=k; i++) invfact[i]=fastpow(fact[i], MOD-2);

    ll ans=0, p=fastpow(n*(n-1)/2, MOD-2), np=(n*(n-1)/2-1)*fastpow(n*(n-1)/2, MOD-2)%MOD;
    for (ll i=1; i<=k; i++) {
        ll temp=1;
        temp=temp*fastpow(p, i)%MOD;
        temp=temp*fastpow(np, k-i)%MOD;
        temp=temp*fact[k]%MOD*invfact[i]%MOD*invfact[k-i]%MOD;
        temp=temp*(((2*sumf+m*(i-1))*i/2)%MOD)%MOD;
        ans+=temp;
        ans%=MOD;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
