#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1, 0);
    for (ll i=1; i<=n; i++) cin >> a[i];

    vector<ll> mx(n+1, 0);
    for (ll i=1; i<=n; i++) {
        mx[i]=max(mx[i-1], a[i]);
    }
    vector<ll> ans;
    ll sum=0;
    for (ll i=n; i>=1; i--) {
        sum+=a[i];
        ans.push_back(max(sum, sum-a[i]+mx[i-1]));
    }
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
