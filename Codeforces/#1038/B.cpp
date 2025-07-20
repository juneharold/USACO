#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1), b(n+1), c(n+1), d(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    ll ans=0;
    for (ll i=1; i<=n; i++) {
        if (b[i]>d[i]) {
            ans+=a[i]+(b[i]-d[i]);
        }
        else if (a[i]>c[i]) {
            ans+=(a[i]-c[i]);
        }
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
