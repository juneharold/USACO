#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<pii> events[2*nmax]; 

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+5), b(n+5);
    for (ll i=1; i<=n; i++) cin >> a[i];
    for (ll i=1; i<=n; i++) cin >> b[i];

    vector<ll> l2(n+5), r2(n+5);
    ll mn=2*n+1, mx=0;
    for (ll i=n; i>=1; i--) {
        mn=min(mn, b[i]);
        mx=max(mx, b[i]);
        l2[i]=mn, r2[i]=mx;
    }

    mn=2*n+1, mx=0;
    for (ll i=1; i<=n; i++) {
        mn=min(mn, a[i]);
        mx=max(mx, a[i]);
        ll l=min(mn, l2[i]), r=max(mx, r2[i]);
        events[1].push_back({1, r});
        if (l+1<=2*n) events[l+1].push_back({2, r});
    }

    ll ans=0;
    multiset<ll> ms;
    for (ll i=1; i<=2*n; i++) {
        while (!events[i].empty()) {
            pii temp=events[i].back();
            events[i].pop_back();
            if (temp.fs==1) ms.insert(temp.sc);
            else ms.erase(ms.find(temp.sc));
        }
        if (!ms.empty()) ans+=(2*n-*ms.begin()+1);
    }
    cout << ans << "\n";
    ms.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
