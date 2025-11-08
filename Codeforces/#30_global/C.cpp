#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n+5);
    vector<pii> monster(m+5);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> monster[i].fs;
    for (int i=1; i<=m; i++) cin >> monster[i].sc;

    sort(&monster[1], &monster[m+1]);
    
    priority_queue<int> pq;
    for (int i=1; i<=n; i++) pq.push(-a[i]);

    int ans=0, idx=1;
    priority_queue<int> active;
    while (!pq.empty()) {
        int sword=-pq.top();
        //cout << sword << "\n";
        pq.pop();
        while (idx<=m && monster[idx].fs<=sword) {
            active.push(monster[idx].sc);
            idx++;
        }

        if (!active.empty()) {
            int c=active.top();
            active.pop();
            ans++;
            if (c!=0) {
                int new_sword=max(sword, c);
                pq.push(-new_sword);
            }
            //cout << "new: " << new_sword << endl;
        }

        //cout << "end------" << endl;
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
