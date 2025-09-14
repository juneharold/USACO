#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    ll altsum=0;
    for (int i=1; i<=n; i++) altsum+=(i%2 ? a[i] : -a[i]);

    ll mx=-1e18, mn=1e18, ans=altsum;
    for (ll i=1; i<=n; i++) {
        if (i%2==0) {
            //cout << altsum << ' ' << ((2*a[i]+i)-mn) << endl;
            ans=max(ans, altsum+((2*a[i]+i)-mn));
            mx=max(mx, 2*a[i]-i);
        }
        else {
            //cout << altsum << ' ' << (mx-(2*a[i]-i)) << endl;
            ans=max(ans, altsum+(mx-(2*a[i]-i)));
            mn=min(mn, 2*a[i]+i);
        }
    }
    
    if (n%2) ans=max(ans, altsum+n-1);
    else ans=max(ans, altsum+n-2);

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
