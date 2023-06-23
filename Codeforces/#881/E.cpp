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
    vector<ll> out;
    while (T--) {
        ll n, m; cin >> n >> m;
        vector<pair<ll, ll>> llerval(m, {0, 0});
        for (ll i=0; i<m; i++) cin >> llerval[i].f >> llerval[i].s;
        vector<ll> a(n+1, 1e9);
        ll q; cin >> q;
        for (ll i=1; i<=q; i++) {
            ll pos; cin >> pos;
            a[pos]=i;
        }

        ll lo=0, hi=q+1;
        while (lo<hi) {
            ll mid=(lo+hi)/2;
            vector<ll> b(n+1, 0);
            for (ll i=1; i<=n; i++) {
                if (a[i]<=mid) b[i]=1;
            }
            vector<ll> pfs(n+1, 0);
            for (ll i=1; i<=n; i++) {
                pfs[i]=pfs[i-1]+b[i];
            }

            bool possible=false;
            for (ll i=0; i<m; i++) {
                ll l=llerval[i].f, r=llerval[i].s;
                if (pfs[r]-pfs[l-1]>(r-l+1)/2) {
                    possible=true;
                    break;
                }
            }

            if (possible) hi=mid;
            else lo=mid+1;
        }
        if (lo==q+1) out.push_back(-1);
        else out.push_back(lo);
    }
    for (ll x: out) cout << x << "\n";
}
