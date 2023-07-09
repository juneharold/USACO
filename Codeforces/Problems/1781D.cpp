#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1, 0);
    for (ll i=1; i<=n; i++) cin >> a[i];

    ll ans=1;
    for (ll i=1; i<n; i++) {
        for (ll j=i+1; j<=n; j++) {
            for (ll m=1; m*m<=a[j]-a[i]; m++) {
                if ((a[j]-a[i])%m) continue;
                if (((a[j]-a[i])/m-m)%2) continue;
                ll k=((a[j]-a[i])/m-m)/2;
                ll x=k*k-a[i], cnt=0;
                if (x<0) continue;
                for (ll idx=1; idx<=n; idx++) {
                    ll sqr=sqrt(a[idx]+x);
                    if (a[idx]+x==sqr*sqr) cnt++;
                }
                ans=max(ans, cnt);
            }
        }   
    }
    cout << ans << "\n";
}

int main()
{
    ll T; cin >> T;
    while (T--) {
        solve();
    }
}