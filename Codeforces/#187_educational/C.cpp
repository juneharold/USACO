#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll s, m; cin >> s >> m;
    ll mn=0;
    for (ll i=0; i<=60; i++) {
        if ((1LL<<i)&m) {
            mn=(1LL<<i);
            break;
        }
    }
    if (s%mn!=0) {
        cout << "-1\n";
        return;
    }

    ll lo=0, hi=2e18;
    while (lo<hi) {
        ll mid=(lo+hi)/2, S=s;
        for (ll i=60; i>=0; i--) {
            if ((1LL<<i)&m) {
                ll x=S/(1LL<<i);
                S-=(1LL<<i)*min(x, mid);
            }
        }
        if (S==0) hi=mid;
        else lo=mid+1;
    }
    cout << lo << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
