#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(&a[1], &a[n+1]);
    vector<ll> alice, bob;
    for (int i=n; i>=1; i-=2) alice.push_back(a[i]);
    for (int i=n-1; i>=1; i-=2) bob.push_back(a[i]);

    for (int i=0; i<bob.size(); i++) {
        ll add=min(alice[i]-bob[i], k);
        bob[i]+=add;
        k-=add;
    }

    ll ans=0;
    for (ll x: alice) ans+=x;
    for (ll x: bob) ans-=x;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
