#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int ans=0, cnt=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='0') cnt++;
        else cnt=0;

        if (cnt==m) {
            ans++;
            i+=k-1;
            cnt=0;
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
