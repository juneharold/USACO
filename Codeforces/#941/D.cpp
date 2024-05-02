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
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> ans;
    for (ll i=0; i<20; i++) {
        if ((1LL<<(i+1))-1<k && k<=(1LL<<(i+2))) {
            ll sum=0;
            for (ll j=0; j<=i; j++) {
                sum+=(1LL<<j);
                ans.push_back((1LL<<j));
            }
            if (k-sum-1>0) ans.push_back(k-sum-1);
            break;
        }
    }
    for (ll i=k+1; i<=n; i*=2) ans.push_back(i);
    ans.push_back(2*k+1);

    cout << ans.size() << "\n";
    for (ll x: ans) cout << x << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
