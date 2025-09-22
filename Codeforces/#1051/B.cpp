#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n+1), b(k+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=k; i++) cin >> b[i];

    sort(&a[1], &a[n+1]);
    sort(&b[1], &b[k+1]);

    ll ans=0, b_sum=b[1], idx=2;
    for (int i=1; i<=n; i++) {
        if (i!=b_sum) ans+=a[n-i+1];

        if (i==b_sum && idx<=k) {
            b_sum+=b[idx];
            idx++;
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
