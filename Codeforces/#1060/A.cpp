#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<char> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    int ans=0, prev=-1e9;
    for (int i=1; i<=n; i++) {
        if (a[i]=='1' && prev<i-k+1) {
            ans++;
            prev=i;
        }
        else if (a[i]=='1' && prev>=i-k+1) {
            prev=i;
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
