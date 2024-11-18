#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll x, y, z, k; 

ll damage(ll a, ll b) {
    ll c=min(a/k, b);
    return k*c*(c+1)/2+(b-c)*a;
}

ll find_a(int b) {
    ll lo=b, hi=z;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        if (damage(mid, b)<z) lo=mid+1;
        else hi=mid;
    }
    if (damage(lo, b)<z) return -1;
    return lo;
}

ll find_b(int a) {
    ll lo=a, hi=z;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        if (damage(a, mid)<z) lo=mid+1;
        else hi=mid;
    }
    if (damage(a, lo)<z) return -1;
    return lo;
}

void solve() {
    cin >> x >> y >> z >> k;
    ll ans=INF;
    for (ll i=1; i<=2e4; i++) {
        //cout << i << ": " << find_a(i) << ' ' << find_b(i) << endl;
        ll a=find_a(i), b=find_b(i);
        if (a!=-1) ans=min(ans, a*x+i*y);
        if (b!=-1) ans=min(ans, i*x+b*y);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
