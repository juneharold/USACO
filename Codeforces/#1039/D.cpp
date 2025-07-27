#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    ll ans=0, cnt=0, sum=0;
    for (ll i=1; i<=n; i++) {
        if (i>1 && a[i]>a[i-1]) {
            sum+=i-1;
            cnt++;
        }
        ans+=(i+1)*i/2-sum;
        //cout << ans-ans_bef << endl;
        //sum+=cnt;
        // if (i>1 && a[i]>a[i-1]) {
        //     sum+=cnt;
        // }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
