#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int val(int x) {
    if (x<=3) return 1;
    return val(x/2+1)+1;
}

bool mark(int x) {
    return (x&1)&&((x-1)&(x-2))==0;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n+1);
    vector<ll> pfs1(n+1, 0), pfs2(n+1, 0);
    for (int i=1; i<=n; i++) {
        ll x; cin >> x;
        pfs1[i]=pfs1[i-1]+val(x);
        pfs2[i]=pfs2[i-1]+(mark(x));
    }
    int l, r;
    while (q--) {
        cin >> l >> r;
        ll ans=(pfs1[r]-pfs1[l-1])+(pfs2[r]-pfs2[l-1])/2;
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
