#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+5, 1e18);
    for (ll i=1; i<=n; i++) cin >> a[i];

    ll ans=0;
    for (ll i=1; i<=n; i+=2) {
        ll temp=max(0LL, a[i]-min(a[i-1], a[i+1]));
        a[i]-=temp;
        ans+=temp;
    }

    a[n+1]=0, a[0]=0;
    for (ll i=2; i<=n; i+=2) {
        if (a[i]<a[i-1]+a[i+1]) {
            ll temp=(a[i-1]+a[i+1])-a[i];
            a[i+1]-=temp;
            ans+=temp;
        }
    }

    //for (ll i=1; i<=n; i++) cout << a[i] << ' ' ;

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
