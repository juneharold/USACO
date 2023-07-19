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

void solve() {
    ll n; cin >> n;
    ll mn=1;
    for (ll mx=mn+n-1; mx<2e7; mx++) {
        ll S=(mx-mn)*(mx-mn);
        ll maxsum=(n-1)*(2*mx-n+2)/2+mn, minsum=(n-1)*(2*mn+n-2)/2+mx;
        ll k=(S-minsum)/n;
        if (k>0 && minsum+k*n<=S && S<=maxsum+k*n) {
            minsum+=k*n, maxsum+=k*n;
            mx+=k, mn+=k;
            cout << mn << ' ' << mx << ' ';
            ll dist=S-minsum, maxpos=mx-1;
            for (ll i=1; i<=n-2; i++) {
                ll pos=mn+n-2+(1-i);
                ll move=maxpos-pos;
                if (dist>=move) {
                    cout << maxpos << ' ';
                    dist-=move;
                    maxpos--;
                }
                else if (dist && dist<move) {
                    cout << pos+dist << ' ';
                    dist=0;
                }
                else cout << pos << ' ';
            }
            cout << "\n";
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        solve();
    }
}
