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

    bool same=true;
    int mx=0, idx=-1;
    for (int i=1; i<=n; i++) {
        if (a[i]>mx) {
            mx=a[i];
            idx=i;
        }
        if (a[i]!=a[1]) {
            same=false;
        }
    }
    if (same) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i=1; i<=n; i++) {
        if (i==idx) cout << "1 ";
        else cout << "2 ";
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
