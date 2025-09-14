#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt1=0, ans=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='1') cnt1++;
    }
    for (int i=n-1; i>=n-cnt1; i--) {
        if (s[i]=='0') ans++;
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
