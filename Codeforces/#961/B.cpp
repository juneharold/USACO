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
    ll n, m; cin >> n >> m;
    vector<pii> v(n);
    for (int i=0; i<n; i++) cin >> v[i].fs;
    for (int i=0; i<n; i++) cin >> v[i].sc;
    sort(v.begin(), v.end());
    
    ll ans=0;
    for (ll i=0; i<v.size(); i++) {
        ll x=min(m/v[i].fs, v[i].sc);
        ans=max(ans, v[i].fs*x);
        if (i==v.size()-1 || v[i+1].fs-v[i].fs>1) continue;
        ll need=m-v[i].fs*x;
        ll y=min(need/v[i+1].fs, v[i+1].sc);
        need=m-v[i].fs*x-v[i+1].fs*y;
        ll k=min(need, min(v[i+1].sc-y, x));
        ans=max(ans, v[i].fs*x+v[i+1].fs*y+k);
        //cout << x << ' ' << y << ' ' << k << endl;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
