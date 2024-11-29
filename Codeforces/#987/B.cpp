#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    for (int i=1; i<=n; i++) {
        if (a[i]!=i) {
            if (i<n && a[i]==i+1 && a[i+1]==i) {
                i++;
            }
            else {
                cout << "NO\n"; 
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
