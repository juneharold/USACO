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
const ll nmax=4e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

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

ll mul(ll a, ll b) {
    a%=MOD;
    b%=MOD;
    return a*b%MOD;
}

void solve() {
    int n, k; cin >> n >> k;
    ll sum1=0, sum2=0, x;
    for (int i=1; i<=k; i++) {
        cin >> x;
        sum1+=x;
    }
    for (int i=1; i<=n-k; i++) {
        cin >> x;
        sum2+=x;
    }
    sum1%=MOD;
    sum2%=MOD;
    ll alice=0;
    alice+=mul(mul((n-k+1)/2, sum2), fastpow(n-k, MOD-2));
    alice+=mul(mul((n-k+2)/2, sum1), fastpow(n-k+1, MOD-2));
    cout << alice%MOD << ' ' << (sum1+sum2-alice%MOD+MOD)%MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
