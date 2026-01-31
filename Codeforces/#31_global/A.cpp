#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll l, a, b; cin >> l >> a >> b;
    vector<bool> vst(l+5, false);
    int cur=a, ans=0;
    while (!vst[cur]) {
        vst[cur]=true;
        ans=max(ans, cur);
        cur=(cur+b)%l;
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
