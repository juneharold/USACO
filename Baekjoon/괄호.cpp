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
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e6+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll fastpow (ll x, ll y) {
    ll ret=1;
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

ll fact[nmax]={}, invfact[nmax]={};

ll nCr(ll n, ll r) {
    return fact[n]*invfact[n-r]%MOD*invfact[r]%MOD;
}

void solve() {
    fact[0]=1, invfact[0]=1;
    for (int i=1; i<nmax; i++) fact[i]=fact[i-1]*i%MOD;
    for (int i=1; i<nmax; i++) invfact[i]=fastpow(fact[i], MOD-2);
    int N, K; cin >> N >> K;
    ll ans=0;
    for (int k=0; k<=N/2; k++) {
        ll n=N-k;
        ll cnt=(n-k+1)*nCr(n+k, k)%MOD*fastpow(n+1, MOD-2)%MOD;
        ans+=fastpow(K, N-k)*cnt%MOD;
        ans%=MOD;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
