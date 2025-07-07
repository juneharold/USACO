#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n; 
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    int mx=a[1];
    for (int i=2; i<=n; i++) {
        if (a[i]<mx) {
            cout << "Yes\n";
            cout << "2\n";
            cout << mx << ' ' << a[i] << "\n";
            return;
        }
        mx=max(mx, a[i]);
    }
    cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
