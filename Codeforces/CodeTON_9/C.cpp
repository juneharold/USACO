#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll x, m; cin >> x >> m;
    ll ans=0, y=1;
    set<ll> used;
    while (y<=min(x, m)) {
        if ((x^y)%y==0) ans++;
        y++;
    }
    ans+=m/x-1;
    for (ll i=m-x+1; i<=m+x; i++) {
        ll y=i^x;
        if (y<=m && (x^y)%x==0) ans++;
    }
    if (x<=m) ans--;
    cout << ans << "\n";
}
/*
1
5 13
*/
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
