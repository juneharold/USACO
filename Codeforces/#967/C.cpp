#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int query (int a, int b) {
    cout << "? " << a << ' ' << b << "\n"; cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;
    vector<pii> ans;
    for (int i=2; i<=n; i++) {
        int res=1;
        while (true) {
            int bef=res;
            res=query(res, i);
            if (res==bef) break;
        }
        ans.push_back({res, i});
    }
    cout << "! ";
    for (auto x: ans) cout << x.fs << ' ' << x.sc << ' '; cout.flush();
    cout << "\n"; cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
