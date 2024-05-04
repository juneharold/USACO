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
    vector<pii> cost(n+1);
    for (ll i=1; i<=n; i++) cin >> cost[i].sc;
    for (ll i=1; i<=n; i++) cin >> cost[i].fs;
    sort(&cost[1], &cost[n+1]);

    vector<ll> selected(n+1, 0);
    for (ll i=1; i<=n; i++) selected[i]=selected[i-1]+max(cost[i].fs-cost[i].sc, 0LL);
    ll sum=0;
    multiset<ll> s;
    for (ll i=n; i>=n-(k-1); i--) {
        s.insert(cost[i].sc);
        sum+=cost[i].sc;
    }
    ll ans=max(0LL, selected[n-k]-sum);
    //cout << ans << endl;
    for (ll i=n-k; i>=1; i--) {
        s.insert(cost[i].sc);
        sum+=cost[i].sc-(*--s.end());
        s.erase(--s.end());
        ans=max(ans, selected[i-1]-sum);
        //cout << selected[i-1] << ' ' << sum << endl;
        //cout << ans << endl;
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