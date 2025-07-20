#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<pair<pii, int>> points;
    int x, y;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        points.push_back({{x, y}, i+1});
    }
    sort(points.begin(), points.end());

    vector<pii> a, b;
    for (int i=0; i<n/2; i++) a.push_back({points[i].fs.sc, points[i].sc});
    for (int i=n/2; i<n; i++) b.push_back({points[i].fs.sc, points[i].sc});

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<pii> ans;
    for (int i=0; i<n/2; i++) {
        ans.push_back({a[i].sc, b[n/2-1-i].sc});
    }
    for (auto x: ans) cout << x.fs << ' ' << x.sc << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
