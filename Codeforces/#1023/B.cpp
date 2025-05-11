#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    ll mn=1e9+1, mx=0, sum=0, cntmx=0;
    for (ll i=1; i<=n; i++) {
        sum+=a[i];
        mn=min(mn, a[i]);
        if (a[i]>mx) {
            mx=a[i];
            cntmx=1;
        }
        else if (a[i]==mx) {
            cntmx++;
        }
    }

    if (mx-mn-1>k || (mx-mn>k && cntmx>1) || sum%2==0) cout << "Jerry\n";
    else cout << "Tom\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
