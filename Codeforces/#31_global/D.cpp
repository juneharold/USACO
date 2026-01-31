#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<ll> x(n+5), r(n+5, -1);
    for (int i=1; i<=n; i++) {
        cin >> x[i];
        x[i]*=2;
    }
    x[n+1]=1e18;

    int ans=0, idx=1;
    while (idx+1<=n) {
        ans++; // for idx and idx+1
        ll lo=1;
        ll hi=min(x[idx+2]-x[idx+1]-1, x[idx+1]-x[idx]-1);

        if (idx+2>n) break;

        for (int i=idx+2; i<=n; i++) {
            ll dprev=x[i]-x[i-1];
            ll dnext=x[i+1]-x[i];

            ll nlo=max(1LL, dprev-hi);
            ll nhi=min(dnext-1, dprev-lo);

            if (nlo<=nhi) {
                ans++;
                lo=nlo;
                hi=nhi;
            } else {
                idx=i;
                break;
            }

            if (i==n) idx=1e9;
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
