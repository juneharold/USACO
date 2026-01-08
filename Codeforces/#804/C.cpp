#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+5), pos(n+5);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pos[a[i]]=i;
    }
    if (n<=2) {
        cout << "1\n";
        return;
    }

    int l=min(pos[0], pos[1]), r=max(pos[0], pos[1]);
    ll ans=1;
    for (int i=2; i<n; i++) {
        if (l<=pos[i] && pos[i]<=r) {
            ans=ans*(r-l+1-i)%MOD;
        }
        else {
            l=min(l, pos[i]);
            r=max(r, pos[i]);
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
