#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long ll;
const ll mx=1e18;
ll fastpow (ll x, ll y) {
    ll ret=1;
    while (y) {
        if (y%2) {
            ret*=x;
        }
        x*=x;
        y/=2;
    }
    return ret;
}

void solve() {
    ll n; cin >> n;
    for (int i=2; i<=60; i++) {
        ll lo=2, hi=pow(n, 1.0/i)+1;
        while (lo<hi) {
            ll mid=(lo+hi)/2;
            ll res=0;
            bool cont=false;
            for (int j=0; j<=i; j++) {
                if (fastpow(mid, j)>n) {
                    cont=true;
                    break;
                }
                res+=fastpow(mid, j);
            }
            if (cont) {
                hi=mid-1;
                continue;
            }
            if (res==n) {
                cout << "YES\n";
                return;
            }
            if (res>n || res==0) hi=mid;
            else lo=mid+1;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
