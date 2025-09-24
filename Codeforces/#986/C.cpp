#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll n, m, v; cin >> n >> m >> v;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    vector<ll> pfs(n+1, 0);
    for (ll i=1; i<=n; i++) pfs[i]=pfs[i-1]+a[i];

    vector<ll> cnt1(n+5, 0), cnt2(n+5, 0);
    ll sum=0;
    for (ll i=1; i<=n; i++) {
        cnt1[i]=cnt1[i-1];
        sum+=a[i];
        if (sum>=v) {
            cnt1[i]++;
            sum=0;
        }
    }
    sum=0;
    for (ll i=n; i>=1; i--) {
        cnt2[i]=cnt2[i+1];
        sum+=a[i];
        if (sum>=v) {
            cnt2[i]++;
            sum=0;
        }
    }

    //for (int i=1; i<=n; i++) cout << cnt1[i] << ' ' << cnt2[i] << endl;

    ll l=0, r=1;
    ll ans=-1e18;
    while (l<=r && r<=n+1) {
        if (r>l && cnt1[l]+cnt2[r]>=m) {
            ans=max(ans, pfs[r-1]-pfs[l]);
            r++;
        }
        else if (cnt1[l]+cnt2[r+1]>=m) r++;
        else if (r==l) l++, r++;
        else l++;
    }
    cout << (ans==-1e18 ? -1 : ans) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
