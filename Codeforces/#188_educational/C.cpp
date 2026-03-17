#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    vector<ll> a(3), ans(3, 0);
    ll m; cin >> a[0] >> a[1] >> a[2] >> m;
    for (int i=0; i<3; i++) ans[i]+=(m/a[i])*6;
    vector<ll> b={lcm(a[0], a[1]), lcm(a[1], a[2]), lcm(a[2], a[0])};
    ans[0]-=(m/b[0])*3, ans[1]-=(m/b[0])*3;
    ans[1]-=(m/b[1])*3, ans[2]-=(m/b[1])*3;
    ans[2]-=(m/b[2])*3, ans[0]-=(m/b[2])*3;

    ll x=lcm(a[0], lcm(a[1], a[2]));
    ans[0]+=(m/x)*2;
    ans[1]+=(m/x)*2;
    ans[2]+=(m/x)*2;

    for (int i=0; i<3; i++) cout << ans[i] << ' ';
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
