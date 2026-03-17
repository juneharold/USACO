#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    for (int i=1; i<=n; i++) cin >> a[i];
    priority_queue<pii> pq;
    for (int i=1; i<=n; i++) pq.push({a[i], i});

    int cur=n+1, ans=0;
    while (!pq.empty()) {
        int x=pq.top().fs, pos=pq.top().sc;
        pq.pop();
        if (pos>=cur) continue;
        else {
            ans++;
            cur=pos;
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
