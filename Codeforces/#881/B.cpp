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
    //vector<ll> out;
    while (T--) {
        ll n; cin >> n;
        vector<ll> a(n, 0);
        ll sum=0; 
        for (ll i=0; i<n; i++) {
            cin >> a[i];
            sum+=abs(a[i]);
        }
        ll cnt=0;
        for (ll i=0; i<n; i++) {
            if (a[i]<0) {
                while (i<n && a[i]<=0) {
                    i++;
                }
                cnt++;
            }
        }
        cout << sum << ' ' << cnt << "\n";
    }
    //for (ll x: out) cout << x << "\n";
}
