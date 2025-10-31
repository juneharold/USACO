#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int R, X, D, n; cin >> R >> X >> D >> n;
    char c;
    int ans=0;
    for (int i=0; i<n; i++) {
        cin >> c;
        if (c=='1') {
            ans++;
            R=max(0, R-D);
        }
        else {
            if (R<X) ans++;
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
