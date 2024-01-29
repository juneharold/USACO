#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll x, n; cin >> x >> n;
    vector<ll> factors;
    for (ll i=1; i*i<=x; i++) {
        if (x%i==0) {
            factors.push_back(i);
            if (i*i!=x) factors.push_back(x/i);
        }
    }
    sort(factors.begin(), factors.end());

    for (int i=0; i<factors.size(); i++) {
        if (factors[i]*n>x) {
            cout << factors[i-1] << "\n";
            return;
        }
    }
    cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
