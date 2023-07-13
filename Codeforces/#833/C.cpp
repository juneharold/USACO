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
vector<ll> out;

void solve() {
    ll n; cin >> n;
    ll sum=0, mx=0, ans=0;
    bool zero=false;
    map<ll, ll> m;
    for (ll i=1; i<=n; i++) {
        int a; cin >> a;
        if (a==0) {
            if (zero) ans+=mx;
            else ans+=m[0];
            zero=true;
            m.clear();
            mx=0;
        }
        sum+=a;
        m[sum]++;
        mx=max(mx, m[sum]);
    }
    if (zero) ans+=mx;
    else ans+=m[0];
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        solve();
    }
    for (ll x: out) cout << x << "\n";
}

/*
1
4
1 0 0 0
*/
