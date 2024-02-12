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
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll n, x; cin >> n >> x;
    if (n%2!=x%2) {
        cout << "0\n";
        return;
    }

    set<ll> ans;
    for (ll i=1; i*i<=n-x; i++) {
        if ((n-x)%i==0) {
            ll c1=i, c2=(n-x)/i;
            if (c1%2==0 && (c1+2)/2>=x) ans.insert((c1+2)/2);
            if (c2%2==0 && (c2+2)/2>=x) ans.insert((c2+2)/2);
        }
    }
    for (ll i=1; i*i<=n+x-2; i++) {
        if ((n+x-2)%i==0) {
            ll c1=i, c2=(n+x-2)/i;
            if (c1%2==0 && (c1+2)/2>=x) ans.insert((c1+2)/2);
            if (c2%2==0 && (c2+2)/2>=x) ans.insert((c2+2)/2);
        }
    }
    //for (int x: ans) cout << x << "\n";
    cout << ans.size() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
