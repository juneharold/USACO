#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<ll> a(n+1); 
    for (int i=1; i<=n; i++) cin >> a[i];

    if (n==1) {
        cout << "1\n";
        return;
    }

    if (n%2==0) {
        ll ans=0;
        for (int i=1; i+1<=n; i+=2) {
            ans=max(ans, a[i+1]-a[i]);
        }
        cout << ans << "\n";
    }
    else {
        ll ans=INF;
        for (int i=1; i<=n; i+=2) {
            ll temp=0;
            for (int j=1; j+1<i; j+=2) {
                temp=max(temp, a[j+1]-a[j]);
            }
            for (int j=i+1; j+1<=n; j+=2) {
                temp=max(temp, a[j+1]-a[j]);
            }
            ans=min(ans, temp);
        }
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
