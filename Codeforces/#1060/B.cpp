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

    ll mx=0;
    for (int i=1; i<=n; i++) {
        mx=max(mx, a[i]);
        if (i%2==0) a[i]=max(mx, a[i]);
    }

    ll ans=0;
    for (int i=1; i<=n; i++) {
        if (i%2) {
            ll add=0;
            if (i+1<=n && a[i+1]<=a[i]) add=a[i]-a[i+1]+1;
            if (i-1>=1 && a[i-1]<=a[i]) add=max(add, a[i]-a[i-1]+1);
            ans+=add;
        }
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
