#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

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

vector<ll> special[10];

map<ll, ll> ans;

void solve() {
    ll x; cin >> x;
    cout << 2*x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
