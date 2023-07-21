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
        int x=n/2+1, y=n;
        for (int i=0; i<n; i++) {
            if (i%2==0) cout << x-- << ' ';
            else cout << y-- << ' ';
        }
    }
    else {
        int x=n/2, y=n;
        for (int i=0; i<n; i++) {
            if (i%2==0) cout << x-- << ' ';
            else cout << y-- << ' ';
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
