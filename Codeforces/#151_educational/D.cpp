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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> a(n, 0);
        for (int i=0; i<n; i++) cin >> a[i];
        ll cur=0, hi=0, diff=0, ans=0;
        for (int i=0; i<n; i++) {
            cur+=a[i];
            hi=max(hi, cur);
            if (cur<hi && hi-cur>diff) {
                ans=hi;
                diff=hi-cur;
            }
        }
        cout << ans << "\n";
    }
}
