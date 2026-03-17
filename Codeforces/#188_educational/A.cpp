#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<char> d(n+5);
    for (int i=1; i<=n; i++) cin >> d[i];
    vector<int> rec(n+5, 0);
    int cur=1;
    for (int i=1; i<=n; i++) {
        rec[cur]=1;
        if (d[cur]=='L') cur--;
        else cur++;
    }
    int ans=0;
    for (int i=1; i<=n; i++) ans+=rec[i];
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
