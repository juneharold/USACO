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
    int n, x; cin >> n >> x;
    if (n%x) {
        cout << "-1\n";
        return;
    }
    vector<int> p(n+1);
    for (int i=1; i<=n; i++) p[i]=i;
    p[1]=x;
    p[n]=1;
    while (x<n) {
        for (int i=x*2; i<=n; i+=x) { // x will become n in the end. So p[x]=n;
            if (n%i==0) {
                p[x]=i;
                x=i;
                break;
            }
        }
    }
    for (int i=1; i<=n; i++) cout << p[i] << ' ';
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
