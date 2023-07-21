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
const ll nmax=5e5+5, sqrmax=635, MOD=1e9+7;

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

int cnt[nmax]={};

void solve() {
    int n, x; cin >> n >> x;
    for (int i=1; i<=n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }
    int carry=0;
    for (int i=1; i<x; i++) {
        if ((cnt[i]+carry)%(i+1)==0) {
            carry=(cnt[i]+carry)/(i+1);
        }
        else {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
