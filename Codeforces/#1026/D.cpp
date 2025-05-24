#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll mx[nmax];
vector<pii> from[nmax];

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> b(n+1);
    for (ll i=1; i<=n; i++) cin >> b[i];
    ll s, t, w;
    for (ll i=1; i<=m; i++) {
        cin >> s >> t >> w;
        from[t].push_back({s, w});
    }
    ll lo=0, hi=INF;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        fill(&mx[1], &mx[n+1], -INF);
        mx[1]=min(mid, b[1]);
        for (ll i=2; i<=n; i++) {
            for (auto [s, w]: from[i]) {
                if (mx[s]<w) continue;
                mx[i]=max(mx[i], mx[s]);
            }
            mx[i]+=b[i];
            mx[i]=min(mx[i], mid);
        }
        if (mx[n]>=0) hi=mid;
        else lo=mid+1;
    }
    if (lo==INF) cout << "-1\n";
    else cout << lo << "\n";
    
    for (ll i=1; i<=n; i++) {
        from[i].clear();
        mx[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
