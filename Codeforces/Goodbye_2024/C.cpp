#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll fastpow (ll x, ll y) {
    ll ret=1;
    while (y) {
        if (y%2) {
            ret*=x;
        }
        x*=x;
        y/=2;
    }
    return ret;
}



void solve() {
    ll n, k; cin >> n >> k;
    ll div2=0, x=n, ans=0;
    while (x>=k) {
        if (x%2) {
            ll num_segments=fastpow(2, div2);
            ll a1=(x+1)/2, d=x+1, an=n-x/2;
            ll num_terms=(an-a1)/d+1;
            //cout << num_segments << ' ' << a1 << ' ' << an << endl;
            ans+=num_segments*(a1+an)/2;
        }
        div2++;
        x/=2;
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
