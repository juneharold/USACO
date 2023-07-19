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
    int n; cin >> n;
    if (n%2) {
        vector<int> ans(n, 0);
        int idx=0;
        for (int i=n-n/2; i<=n+n/2; i++) ans[idx++]=i+2;
        ans[0]--;
        ans[n-1]++;
        ans[n-2]++;
        for (int i=0; i<n; i++) cout << ans[i] << ' ';
    }
    else {
        for (int i=n/2; i<=n-1; i++) cout << i << ' ';
        for (int i=n+1; i<=3*n/2; i++) cout << i << ' ';
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
