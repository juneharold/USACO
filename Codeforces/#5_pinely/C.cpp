#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n, X; cin >> n >> X;
    vector<ll> a(n+1, 0);
    for (int i=1; i<=n; i++) cin >> a[i];

    sort(&a[1], &a[n+1]);
    ll sum=0;
    for (int i=1; i<=n; i++) sum+=a[i];

    ll m=sum/X;
    ll ans=0;
    for (int i=n; i>n-m; i--) ans+=a[i];
    cout << ans << "\n";
        
    ll cur=0, l=1, r=n;
    while (l<=r) {
        if ((cur+a[r])/X>cur/X) {
            cout << a[r] << ' ';
            cur+=a[r];
            r--;
        }
        else {
            cout << a[l] << ' ';
            cur+=a[l];
            l++;
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
