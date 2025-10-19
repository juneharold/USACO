#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=250005, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    vector<ll> pfs0(n+1, 0), pfs1(n+1, 0);
    for (ll i=1; i<=n; i++) {
        pfs0[i]=pfs0[i-1]+(a[i]==0);
        pfs1[i]=pfs1[i-1]+(a[i]==1);
    }

    vector<int> adj_equal(n+1, 0);
    for (int i=1; i<n; i++) {
        adj_equal[i]=adj_equal[i-1]+(a[i]==a[i+1]);
    }
    adj_equal[n]=adj_equal[n-1];   
    
    ll l, r;
    while (q--) {
        cin >> l >> r;
        ll cnt0=pfs0[r]-pfs0[l-1], cnt1=pfs1[r]-pfs1[l-1];
        if (cnt0%3!=0 || cnt1%3!=0) {
            cout << "-1\n";
            continue;
        }

        ll ans=cnt0/3+cnt1/3;
        bool has_adj=(adj_equal[r-1]-adj_equal[l-1])>0;
        if (!has_adj) ans++;
        cout << ans << "\n";
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
